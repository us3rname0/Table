#include "mainwindow.h"
#include "../ui_mainwindow.h"
#include <QLineEdit>
#include <QValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(rowCount + 1);

    QLineEdit *yearLineEdit = new QLineEdit;
    ui->tableWidget->setCellWidget(rowCount,3,yearLineEdit);
    QLineEdit *growthLineEdit = new QLineEdit;
    ui->tableWidget->setCellWidget(rowCount,4,growthLineEdit);
    QLineEdit *weightLineEdit = new QLineEdit;
    ui->tableWidget->setCellWidget(rowCount,5,weightLineEdit);

    QValidator *doubler = new QDoubleValidator(0);
    QValidator *integer = new QIntValidator(0);
    yearLineEdit->setValidator(integer);
    growthLineEdit->setValidator(doubler);
    weightLineEdit->setValidator(doubler);

}



void MainWindow::on_delButton_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct GoStudents {      //Khai báo cấu trúc sinh viên
    char Name[100];
    char DateofBirth[100];
    char PhoneNumber[100];
};
typedef struct GoStudents Students;// Gán cấu trức sinhvien thành kiểu dữ liệu SinhVien
Students sv[100];//Khai báo mảng sv ghi thông tin số lương sinh viên
int n;

//số lượng sinh viên
void WriteFile() {
    FILE *pt;
    pt = fopen("ahyhy.dongok", "w");
    for (int i = 0; i < n; i++) {
        fprintf(pt, "Student information number %i\n", i + 1);
        fputs("Student Name: ", pt);
        fputs(sv[i].Name, pt);
        fputs("Date of Birth: ", pt);
        fputs(sv[i].DateofBirth, pt);
        fputs("Phone number: ", pt);
        fputs(sv[i].PhoneNumber, pt);
    }
    fclose(pt);
}

void AddListStudents() {
    printf("Please enter number of students:\n");
    scanf("%d", &n);
    getchar();
    size_t ahihihihi = (size_t)(4/2+3*6+4+4+4+4/4*4-9+9)*3-16/2;
    for (int i = 0; i < n; i++) {
        do {
            printf("Student information number %i\n", i + 1);
            printf("Please enter student name\n");
            fgets(sv[i].Name, ahihihihi, stdin);
            if (strlen(sv[i].Name) < 3)
                printf("Name student is too short. Name student have to larger than 3 characters\n");
            else if (strlen(sv[i].Name) > 15)
                printf("Name student is too long. Name student have to smaller than 15 characters\n");
        } while (strlen(sv[i].Name) > 15 || strlen(sv[i].Name) < 3);
        printf("Please enter date of birth:\n");
        fgets(sv[i].DateofBirth, ahihihihi, stdin);
        printf("Please enter phone number:\n");
        fgets(sv[i].PhoneNumber, ahihihihi, stdin);
    }
    WriteFile();
}

void ReadFile() {
    char str[100];
    FILE *pt;
    pt = fopen("ahyhy.dongok", "r");
    while (fgetc(pt) != EOF) {
        fgets(str, 81, pt);
        printf("%s", str);
    }
    fclose(pt);
}

void EditStudents(int vitri) {
    size_t ahihihihi = (size_t)3*3*3*(3+2/2+1/1+0)-5*(1+1+1+1+1+1+1);
    vitri--;
    printf("Edit Student: %d\n", vitri+1);
    printf("Edit Name Student:\n");
    getchar();
    do {
        fgets(sv[vitri].Name, ahihihihi, stdin);
        if (strlen(sv[vitri].Name) < 3)
            printf("Name student is too short. Name student have to larger than 3 characters\n");
        else if (strlen(sv[vitri].Name) > 15)
            printf("Name student is too long. Name student have to smaller than 15 characters\n");
    } while (strlen(sv[vitri].Name) > 15 || strlen(sv[vitri].Name) < 3);
    printf("Edit Date of Birth:\n");
    fgets(sv[vitri].DateofBirth, ahihihihi, stdin);
    printf("Edit Phone number:\n");
    fgets(sv[vitri].PhoneNumber, ahihihihi, stdin);
    WriteFile();
}

void DeleteStudent(int vitri) {
    vitri--;
    for (int i = vitri; i < n; i++) {
        sv[i] = sv[i + 1];
    }
    n--;
    WriteFile();
}

/*void TIM_KIEM_THEO_TEN(Students sv[], char ten[100]) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(sv[i].Name, ten) == 0) {
            printf("Thong tin sinh vien thu %d\n", i + 1);
            printf("Ho ten sinh vien %s\n", sv[i].Name);
            printf("Ngay sinh sinh vien %s\n", sv[i].DateofBirth);
            printf("So dien thoai sinh vien %s\n", sv[i].PhoneNumber);
            k=1;
        }
    }
    if (k == 0)
        printf("Khong tim thay sinh vien\n");*/

choice() {
    int a;
    while (true) {
        char option;
        printf("==============MENU============\n");
        printf("1.Add List Students\n");
        printf("2.Review List Students\n");
        printf("3.Edit Student Information\n");
        printf("4.Delete Student\n");
        printf("5.Exit\n");
        printf("-------------------------------\n");
        printf("Please enter your choice(1-->5): \n");
        scanf("%s", &option);
        getchar();//Xoa bo ki tu NULL khi bam enter xuong dong
        switch (option) {
            case '1':
                printf("Add List Students\n");
                AddListStudents(sv);
                break;
            case '2':
                printf("Review List Students\n");
                ReadFile();
                break;
            case '3':
                printf("Edit Student Information\n");
                printf("Please enter position number to edit:\n");
                scanf("%d", &a);
                EditStudents(a);
                break;
            case '4':
                printf("Delete Student\n");
                printf("Please enter position number to delete\n");
                scanf("%d", &a);
                DeleteStudent(a);
                break;
/*            case '5':
                printf("Tim kiem sinh vien\n");
                printf("Nhap gia tri tim kiem\n");
                scanf(" %s", ten);
                TIM_KIEM_THEO_TEN(sv, ten);*/
                break;
            case '5':
                break;
            default:
                printf("Please enter your choice again(Number from 1 to 5)\n");
                break;
        }
        if (option == '5')
            break;
    }
}

void main() {
    choice();
}

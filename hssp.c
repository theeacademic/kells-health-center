
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct patient {
    char name[50];
    int age;
    char gender[10];
    char problem[100];
};

int main() {
    struct patient p;
    char choice;
    FILE *fp;

    printf("Enter patient name: ");
    fgets(p.name, 50, stdin);

    printf("Enter patient age: ");
    scanf("%d", &p.age);

    printf("Enter patient gender: ");
    scanf("%s", p.gender);

    printf("Enter patient problem: ");
    scanf("%s", p.problem);

    fp = fopen("patient.txt", "a");
    fprintf(fp, "\n%s %d %s %s", p.name, p.age, p.gender, p.problem);
    fclose(fp);

    printf("Patient details added successfully.\n");

    printf("Do you want to view patient details? (y/n)");
    scanf(" %c", &choice);

    if(choice == 'y') {
        fp = fopen("patient.txt", "r");
        if(fp == NULL) {
            printf("File not found!");
            exit(1);
        }
        char c = fgetc(fp);
        while(c != EOF) {
            printf("%c", c);
            c = fgetc(fp);
        }
        fclose(fp);
    }

    return 0;
    }

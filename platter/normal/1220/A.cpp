#include <stdio.h>
#include <string.h>

int main(void) {
    int n;
    char str[100001];
    scanf("%d\n", &n);
    gets(str);
    int zero=0;
    int one=0;
    for(int i=0;i<n;i++) {
        if (str[i]=='z')
        zero+=1;
        if (str[i]=='n')
        one+=1;
    }
    for(int i=0;i<one;i++) {
        printf("1 ");
    }
    for(int i=0;i<zero;i++) {
        printf("0 ");
    }
    return 0;
}
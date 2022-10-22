#include <cstdio>
#include <cstring>

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        char str[1055];
        gets(str);
        int n=strlen(str);
        if (str[n-2]=='p'&&str[n-1]=='o') {
            printf("FILIPINO\n");
        }
        else if (str[n-4]=='m'&&str[n-3]=='a'&&str[n-2]=='s'&&str[n-1]=='u') {
            printf("JAPANESE\n");
        }
        else if (str[n-4]=='d'&&str[n-3]=='e'&&str[n-2]=='s'&&str[n-1]=='u') {
            printf("JAPANESE\n");
        }
        else if (str[n-5]=='m'&&str[n-4]=='n'&&str[n-3]=='i'&&str[n-2]=='d'&&str[n-1]=='a') {
            printf("KOREAN\n");
        }
    }
    return 0;
}
#include <cstdio>
#include <cstring>

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        char str[101];
        gets(str);
        int n=strlen(str);
        bool zero=false;
        int even=0;
        int total=0;
        for(int i=0;i<n;i++) {
            if (str[i]=='0') {
                zero=true;
            }
            if (str[i]%2==0) {
                even+=1;
            }
            total+=str[i]-'0';
        }
        if (zero&&even>=2&&total%3==0) {
            printf("red\n");
        }
        else {
            printf("cyan\n");
        }
    }
    return 0;
}
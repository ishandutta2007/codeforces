#include <cstdio>
#include <cstring>

int main(void) {
    char str[500001];
    gets(str);
    int n=strlen(str);
    int fb=-1;
    int fc=-1;
    int lc=-1;
    int lb=-1;
    for(int i=0;i<n;i++) {
        if (str[i]=='[') {
            fb=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--) {
        if (str[i]==']') {
            lb=i;
            break;
        }
    }
    if (fb==-1||lb==-1||fb>=lb) {
        printf("-1");
        return 0;
    }
    for(int i=fb+1;i<lb;i++) {
        if (str[i]==':') {
            fc=i;
            break;
        }
    }
    for(int i=lb-1;i>fb;i--) {
        if (str[i]==':') {
            lc=i;
            break;
        }
    }
    if (fc==lc||fc==-1||lc==-1) {
        printf("-1");
        return 0;
    }
    int count=0;
    for(int i=fc+1;i<lc;i++) {
        if (str[i]=='|') {
            count+=1;
        }
    }
    printf("%d",4+count);
    return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        char str[100001];
        gets(str);
        int n=strlen(str);
        int u=0;
        int d=0;
        int l=0;
        int r=0;
        for(int i=0;i<n;i++) {
            if (str[i]=='U') {
                u+=1;
            }
            if (str[i]=='D') {
                d+=1;
            }
            if (str[i]=='L') {
                l+=1;
            }
            if (str[i]=='R') {
                r+=1;
            }
        }
        int lr=min(l,r);
        int ud=min(u,d);
        if (lr==0&&ud==0) {
            printf("0\n\n");
            continue;
        }
        if (lr==0) {
            printf("2\nUD\n");
            continue;
        }
        if (ud==0) {
            printf("2\nRL\n");
            continue;
        }
        printf("%d\n",2*lr+2*ud);
        for(int i=0;i<lr;i++) {
            printf("R");
        }
        for(int i=0;i<ud;i++) {
            printf("U");
        }
        for(int i=0;i<lr;i++) {
            printf("L");
        }
        for(int i=0;i<ud;i++) {
            printf("D");
        }
        printf("\n");
    }
    return 0;
}
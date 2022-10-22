#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d\n",&n);
        if (n<4) {
            printf("-1\n");
            continue;
        }
        if (n%4==1) {
            int now=3;
            for(;now<=n;now+=4) {
                printf("%d ",now);
            }
            now=((n-1)/4)*4+1;
            for(;now>0;now-=4) {
                printf("%d ",now);
            }
            now=4;
            for(;now<=n;now+=4) {
                printf("%d ",now);
            }
            now=((n-2)/4)*4+2;
            for(;now>0;now-=4) {
                printf("%d ",now);
            }
            printf("\n");
            continue;
        }
        int now=2;
        for(;now<=n;now+=4) {
            printf("%d ",now);
        }
        now=((n-4)/4)*4+4;
        for(;now>0;now-=4) {
            printf("%d ",now);
        }
        now=1;
        for(;now<=n;now+=4) {
            printf("%d ",now);
        }
        now=((n-3)/4)*4+3;
        for(;now>0;now-=4) {
            printf("%d ",now);
        }
        printf("\n");
    }
}
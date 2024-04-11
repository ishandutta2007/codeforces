#include <bits/stdc++.h>
using namespace std;

int f(int x) {
    return (x+1)/3;
}

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        int r1,c1,r2,c2,r3,c3;
        scanf("%d %d %d %d %d %d",&r1,&c1,&r2,&c2,&r3,&c3);
        int cx=f(r1+r2+r3);
        int cy=f(c1+c2+c3);
        int x,y;
        scanf("%d %d",&x,&y);
        if ((cx==1||cx==n)&&(cy==1||cy==n)) {
            if (cx==x||cy==y) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
        }
        else {
            if (cx%2!=x%2&&cy%2!=y%2) {
                printf("NO\n");
            }
            else {
                printf("YES\n");
            }
        }
    }
    return 0;
}
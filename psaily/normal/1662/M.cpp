#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
int n,m;

int main() {
    int _;
    for (scanf("%d",&_);_;_--) {
        scanf("%d%d",&n,&m);
        int rmx=0,wmx=0;
        rep(i,1,m+1) {
            int r,w;
            scanf("%d%d",&r,&w);
            rmx=max(rmx,r);
            wmx=max(wmx,w);
        }
        if (rmx+wmx>n) {
            puts("IMPOSSIBLE");
        } else {
            rep(i,1,rmx+1) putchar('R');
            rep(i,rmx+1,n+1) putchar('W');
            puts("");
        }

    }


    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n,k;
int x[100];
int y[100];

int julde(int x) {
    return x>0?x:-x;
}

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%d %d\n",&n,&k);
        for(int i=0;i<n;i++) {
            scanf("%d %d",&x[i],&y[i]);
        }
        bool flag=false;
        for(int i=0;i<n;i++) {
            bool f=true;
            for(int j=0;j<n;j++) {
                if (julde(x[i]-x[j])+julde(y[i]-y[j])>k) {
                    f=false;
                    break;
                }
            }
            if (f) {
                flag=true;
                printf("1\n");
                break;
            }
        }
        if (!flag) {
            printf("-1\n");
        }
    }
}
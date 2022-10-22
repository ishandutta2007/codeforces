#include <bits/stdc++.h>
using namespace std;

int val[65536];
bool vis[65536];

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n,k;
        scanf("%d %d",&n,&k);
        if (k==n-1) {
            if (n==4) {
                printf("-1\n");
                continue;
            }
            for(int i=0;i<n;i++) {
                if (i==0) {
                    val[i]=n-4;
                }
                else if (i==1) {
                    val[i]=3;
                }
                else if (i==3) {
                    val[i]=1;
                }
                else if (i==n-4) {
                    val[i]=0;
                }
                else if (i==n-2) {
                    val[i]=n-1;
                }
                else if (i==n-1) {
                    val[i]=n-2;
                }
                else {
                    val[i]=n-1-i;
                }
            }
        }
        else {
            for(int i=0;i<n;i++) {
                if (i==0) {
                    val[i]=n-1-k;
                }
                else if (i==n-1-k) {
                    val[i]=0;
                }
                else if (i==k) {
                    val[i]=n-1;
                }
                else if (i==n-1) {
                    val[i]=k;
                }
                else {
                    val[i]=n-1-i;
                }
            }
        }
        for(int i=0;i<n;i++) {
            vis[i]=false;
        }
        for(int i=0;i<n;i++) {
            if (!vis[i]) {
                printf("%d %d\n",i,val[i]);
                vis[i]=true;
                vis[val[i]]=true;
            }
        }
    }
    return 0;
}
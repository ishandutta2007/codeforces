#include <bits/stdc++.h>
using namespace std;

int arr[50000];
int nt[50000];

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        memset(nt,-1,sizeof(nt));
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
        }
        int x;
        scanf("%d",&x);
        for(int i=0;i<n-1;i++) {
            if (arr[i]+arr[i+1]<x*2) {
                nt[i]=i+1;
            }
        }
        for(int i=0;i<n-2;i++) {
            if (arr[i]+arr[i+1]>=x*2&&arr[i+1]+arr[i+2]>=x*2&&arr[i]+arr[i+1]+arr[i+2]<x*3) {
                nt[i]=i+2;
            }
        }
        int now=0;
        int ret=0;
        int cnt=0;
        while (now!=n) {
            if (nt[now]==-1) {
                ret+=(cnt+1)/2;
                cnt=0;
                now++;
            }
            else {
                now=nt[now];
                cnt++;
            }
        }
        printf("%d\n",n-ret);
    }
    return 0;
}
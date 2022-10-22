#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int lo=0; //h(mid)!=1
    int hi=2005*n; //h(mid)=1
    while (lo+1<hi) {
        int mid=(lo+hi)/2;
        printf("? %d\n",mid);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        if (x==1) {
            hi=mid;
        }
        else {
            lo=mid;
        }
    }
    int ret=hi;
    for(int i=2;i<=n;i++) {
        int val=(hi+1-i-1)/i+1;
        printf("? %d\n",val);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        if (x!=0)
        ret=min(ret,val*x);
    }
    printf("! %d\n",ret);
    fflush(stdout);
}
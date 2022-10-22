#include <bits/stdc++.h>
using namespace std;

long long arr[300000];
long long cost[300000];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++) {
            scanf("%lld",&arr[i]);
            arr[i]--;
        }
        for(int i=0;i<m;i++) {
            scanf("%lld",&cost[i]);
        }
        sort(arr,arr+n);
        int now=0;
        long long ret=0;
        for(int i=n-1;i>=0;i--) {
            if (arr[i]<now) {
                ret+=cost[arr[i]];
            }
            else {
                ret+=cost[now++];
            }
        }
        printf("%lld\n",ret);
    }
}
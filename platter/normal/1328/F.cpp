#include <bits/stdc++.h>
using namespace std;

long long arr[200000];
long long lc[200000];
long long rc[200000];
int st[200000];
int en[200000];

int main(void) {
    int n,k;
    scanf("%d %d\n",&n,&k);
    for(int i=0;i<n;i++) {
        scanf("%lld ",&arr[i]);
    }
    sort(arr,arr+n);
    int cnt=0;
    for(int i=0;i<n;i++) {
        cnt++;
        if (cnt>=k) {
            printf("0");
            return 0;
        }
        if (i==n-1||arr[i]!=arr[i+1]) {
            for(int j=i;j>=0&&arr[j]==arr[i];j--) {
                st[j]=i-cnt+1;
                en[j]=i;
            }
            cnt=0;
        }
    }
    long long cost=0;
    long long ret=1e18;
    for(int i=1;i<n;i++) {
        cost+=(arr[i]-arr[i-1])*i;
        lc[i]=cost;
        if (i>=k-1) {
            ret=min(ret,cost);
            if (st[i]>=k) {
                ret=min(ret,cost-st[i]);
            }
            else {
                ret=min(ret,cost+k-i-1);
            }
        }
    }
    cost=0;
    rc[n-1]=0;
    for(int i=n-2;i>=0;i--) {
        cost+=(arr[i+1]-arr[i])*(n-1-i);
        rc[i]=cost;
        if (i<=n-k) {
            ret=min(ret,cost);
            if (en[i]<n-k) {
                ret=min(ret,cost-n+1+en[i]);
            }
            else {
                ret=min(ret,cost-n+k+i);
            }
        }
    }
    for(int i=0;i<n;i++) {
        ret=min(ret,lc[i]+rc[i]-n+k);
    }
    printf("%lld",ret);
}
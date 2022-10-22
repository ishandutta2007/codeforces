#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long dp[200055][2];
int n,k;
long long p;
long long cost[200055];
long long INF=1e12;

long long ans(int now,int type) {
    if (dp[now][type]!=-INF) {
        return dp[now][type];
    }
    if (type==1&&now<k-1) {
        return -INF;
    }
    if (type==1&&now==k-1) {
        dp[now][type]=p-cost[now];
        return dp[now][type];
    }
    if (now==0) {
        return p-cost[0];
    }
    if (type==0) {
        dp[now][type]=max(ans(now-1,0),ans(now-1,1))-cost[now];
    }
    if (type==1) {
        dp[now][type]=max(ans(now-k,0),ans(now-k,1))-cost[now];
    }
    return dp[now][type];
}

long long money(int now) {
    if (now==-1) {
        return INF;
    }
    if (now==n) {
        return -INF;
    }
    return max(ans(now,0),ans(now,1));
}

int search() {
    int lo=0;
    int hi=n;
    int mid=(lo+hi)/2;
    while (lo<=hi) {
        mid=(lo+hi)/2;
        if (money(mid-1)>=0&&money(mid)<0) {
            return mid;
        }
        if (money(mid-1)<0) {
            hi=mid-1;
        }
        else {
            lo=mid+1;
        }
    }
    return mid;
}

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int i=0;i<200055;i++) {
        dp[i][0]=-INF;
        dp[i][1]=-INF;
    }
    for(int t=0;t<c;t++) {
        scanf("%d %lld %d\n",&n,&p,&k);
        for(int i=0;i<n;i++) {
            scanf("%lld ",&cost[i]);
        }
        sort(cost,cost+n);
        printf("%d\n",search());
        for(int i=0;i<=n;i++) {
            dp[i][0]=-INF;
            dp[i][1]=-INF;
        }
    }
    return 0;
}
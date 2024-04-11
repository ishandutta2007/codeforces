#include<bits/stdc++.h>
using namespace std;

int dp[100001];
int r,n;
int x[100001];
int y[100001];
int t[100001];

int julde(int x) {
    return x>0?x:-x;
}

int main(void) {
    x[0]=1;
    y[0]=1;
    int ret=0;
    scanf("%d %d",&r,&n);
    for(int i=1;i<=n;i++) {
        scanf("%d %d %d",&t[i],&x[i],&y[i]);
        dp[i]=-1e6;
        for(int j=i-1;j>=0&&j>=i-4*r;j--) {
            if (julde(x[i]-x[j])+julde(y[i]-y[j])<=t[i]-t[j]) {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ret=max(ret,dp[i]);
    }
    printf("%d",ret);
}
#include <bits/stdc++.h>
using namespace std;

int dp[5001][5001];
char s[5001];
char t[5001];
const int nn=1e6;
int n,m;

int ans(int one,int two) {
    if (dp[one][two]!=nn) {
        return dp[one][two];
    }
    int val=(s[one]==t[two]?3:-1);
    int ret=val;
    if (s[one]!=t[two]) {
        if (one!=n-1) {
            ret=max(ret,ans(one+1,two)+val);
        }
        if (two!=m-1) {
            ret=max(ret,ans(one,two+1)+val);
        }
    }
    else {
        if (one!=n-1&&two!=m-1) {
            ret=max(ret,ans(one+1,two+1)+val-1);
        }
    }
    return dp[one][two]=ret;
}

int main(void) {
    scanf("%d %d\n",&n,&m);
    scanf("%s\n%s",s,t);
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            dp[i][j]=nn;
        }
    }
    int ret=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            ret=max(ret,ans(i,j)-1);
        }
    }
    printf("%d",ret);
}
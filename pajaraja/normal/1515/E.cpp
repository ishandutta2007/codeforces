#include <bits/stdc++.h>
#define MAXN 407
using namespace std;
long long n,MOD,dp[MAXN][MAXN],binom[2*MAXN][2*MAXN],st[MAXN];
int main()
{
    cin>>n>>MOD;
    st[0]=1;
    for(int i=1;i<MAXN;i++) st[i]=(st[i-1]*2)%MOD;
    for(int i=0;i<2*MAXN;i++) binom[i][0]=binom[i][i]=1;
    for(int i=1;i<2*MAXN;i++) for(int j=1;j<i;j++) binom[i][j]=(binom[i-1][j]+binom[i-1][j-1])%MOD;
    for(int i=1;i<=n;i++) dp[i][i]=st[i-1];
    for(int i=2;i<=n;i++) for(int k=1;k<i;k++) for(int j=1;j<k;j++) dp[i][k]=(dp[i][k]+dp[i-j-1][k-j]*binom[k][j]%MOD*st[j-1])%MOD;
    long long sol=0;
    for(int i=1;i<=n;i++) sol=(sol+dp[n][i])%MOD;
    cout<<sol;
}
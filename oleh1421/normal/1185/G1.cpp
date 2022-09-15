#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,T;
int t[101];
int g[101];
ll mod=1000000007ll;
int dp[40001][21];
int F(int mask,int j,int sum){
    ll res=0ll;
    if (sum==T) return 1ll;
    if (sum>T) return 0;
    if (dp[mask][j]) return (dp[mask][j]+mod-1ll)%mod;
    for (int i=0;i<n;i++){
        if ((mask&(1<<i))) continue;
        if (g[i]==g[j]) continue;
        res+=F((mask|(1<<i)),i,sum+t[i]);
    }
    dp[mask][j]=(res+1ll)%mod;
    return res%mod;
}
int main()
{
    cin>>n>>T;
    for (int i=0;i<n;i++) cin>>t[i]>>g[i];
    ll res=0ll;
    for (int i=0;i<n;i++){
        res+=F((1<<i),i,t[i]);
        res%=mod;
    }
    cout<<res;
   return 0;
}
/*
9 12
3 2 4 1 5 6 3 6 8
0 0 0 0 1 2 3 4 6
*/
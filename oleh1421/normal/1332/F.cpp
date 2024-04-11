//#pragma GCC optimize ("trapv")
//#pragma GCC opitmize ("unroll-loops")

#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
const ll mod=998244353ll;

ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return (a*binpow(a,b-1))%mod;
    else return binpow((a*a)%mod,b/2ll);
}
ll dp[N][3];
vector<int>g[N];
void dfs(int v,int pr){
    for (auto to:g[v]){
        if (to==pr) continue;
        dfs(to,v);
    }
    dp[v][0]=1ll;
    dp[v][1]=1ll;
    dp[v][2]=1ll;
    ll x=1ll;
    for (auto to:g[v]){
        if (to==pr) continue;
        dp[v][0]*=dp[to][0]*2ll+dp[to][1]+dp[to][2];
        dp[v][0]%=mod;
        dp[v][1]*=dp[to][0]*2ll+dp[to][2];
        dp[v][1]%=mod;
        dp[v][2]*=dp[to][0]*2ll+dp[to][2];
        dp[v][2]%=mod;
        x*=dp[to][0]+dp[to][2];
        x%=mod;
    }
    dp[v][2]+=mod-x;
    dp[v][2]%=mod;
//    cout<<v<<" "<<dp[v][0]<<" "<<dp[v][1]<<" "<<dp[v][2]<<endl;

}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    cout<<(dp[1][0]+dp[1][2]-1ll)%mod;
    return 0;
}
/*
0 0
0 0
*/
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse,avx,avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 rnd(time(NULL));
const int N=500100;
const ll mod=1000000007;
ll C[N];
ll f[N];
ll rf[N];
ll binpow(ll a,ll b){
    if (!b) return 1;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
int p[N];
int sz[N];
ll sum[N];
vector<int>g[N];
void dfs(int v,int pr){
    p[v]=pr;
    sz[v]=1;
    for (int to:g[v]){
        if (to==pr) continue;
        dfs(to,v);
        sum[v]+=C[sz[to]];
        sum[v]%=mod;
        sz[v]+=sz[to];
    }
}
void solve(int Case){
    int n,k;cin>>n>>k;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    f[0]=1;
    for (int i=1;i<=n;i++){
        f[i]=(f[i-1]*i)%mod;
    }
    rf[n]=binpow(f[n],mod-2);
    for (int i=n;i>=1;i--){
        rf[i-1]=(rf[i]*i)%mod;
    }
    for (int i=0;i<k;i++) C[i]=0;
    for (int i=k;i<=n;i++){
        C[i]=(f[i]*rf[k]%mod)*rf[i-k]%mod;
    }
    dfs(1,0);
    ll res=0ll;
    for (int v=2;v<=n;v++){
        res+=sz[v]*(C[sz[v]]+mod-sum[v])%mod*(n-sz[v])%mod;
        res%=mod;
        ll S=sum[p[v]]+mod-C[sz[v]];
        S+=C[n-sz[p[v]]];
        S%=mod;
        res+=(n-sz[v])*(C[n-sz[v]]+mod-S)%mod*(sz[v])%mod;
        res%=mod;
    }
    for (int v=1;v<=n;v++){
        res+=n*(C[n]+mod*2-sum[v]-C[n-sz[v]])%mod;
        res%=mod;
    }
    cout<<res<<endl;


}
int32_t main() {
//    freopen("seabattle.in","r",stdin);
//    freopen("seabattle.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt=1;
//    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}
/**
1
3
1 -1 1
**/
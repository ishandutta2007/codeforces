// #pragma comment(linker, "/STACK:102400000,102400000")
// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;


const int maxn=300007;
const int mod=998244353;

int n,m;
vi g[maxn];
int par[maxn],d[maxn];
vector<pii> hii;
vi res;
int fnd(int u){
    if (par[u]==u) return u;
    return par[u]=fnd(par[u]);
}

bool unite(int u,int v){
    int pu=fnd(u), pv=fnd(v);
    if (pu==pv) return 0;
    par[pu]=pv;
    return 1;
}

bool dfs(int u,int p,int t){
    if (u==t) return 1;
    bool ok=0; 
    for (auto c:g[u]){
        if (c==p) continue;
        if (dfs(c,u,t)) ok=1, res.pb(c);
    }
    return ok;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    cin>>n>>m;
    rep1(i,n) par[i]=i;
    rep(i,m){
        int u,v;
        cin>>u>>v;
        if (unite(u,v)) g[u].pb(v), g[v].pb(u);
    }
    int q;
    cin>>q;
    while (q--){
        int u,v;
        cin>>u>>v;
        hii.pb({u,v});
        d[u]++, d[v]++;
    }
    int count=0;
    rep1(i,n){
        if (d[i]&1) count++;
    }
    if (count){
        cout<<"NO\n"<<count/2;
        return 0;
    }
    cout<<"YES\n";
    for (auto [u,v]:hii){
        res.clear();
        dfs(u,-1,v);
        res.pb(u);
        reverse(range(res));
        cout<<sz(res)<<"\n";
        for (auto c:res) cout<<c<<" ";
        cout<<"\n";
    }
    return 0;
}
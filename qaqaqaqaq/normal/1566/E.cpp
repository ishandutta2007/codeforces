// #pragma comment(linker, "/STACK:102400000,102400000")
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

const int inf=LLONG_MAX/4;
mt19937 rng(time(NULL)); // don't hack, pls!

const int maxn=200007;
const int mod=998244353;
const double EPS=1e-9;
const double pi=3.14159265358979;


int n;
vi g[maxn];
int par[maxn],dep[maxn],p[maxn];
bool ok[maxn];
vi d[maxn];
void dfs(int u,int p){
    par[u]=p;
    for (auto c:g[u]){
        if (c==p) continue;
        dep[c]=dep[u]+1;
        dfs(c,u);
    }
}
void solve(){
    cin>>n;
    rep1(i,n) g[i].clear();
    rep1(i,n) ok[i]=0,dep[i]=0;
    rep(i,n-1){
        int u,v;
        cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
    }
    dfs(1,-1);
    rep(i,n+1) d[i].clear();
    rep1(i,n) d[dep[i]].pb(i);
    int ans=0,buds=0;
    for (int i=n;i>0;--i){
        for (auto c:d[i]){
            if (ok[c]) continue;
            ans++; 
            if (!ok[par[c]]) ok[par[c]]=1, buds++;
        }
    }
    // cerr<<ans<<" "<<buds<<" "<<ok[1]<<endl;
    cout<<ans-buds+1<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(20);
    int _;
    cin>>_;
    while (_--){
        solve();
    }
    return 0;
}

/*
2
101919804931827191 136638622643121931

*/
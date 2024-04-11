#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const long long int N=4e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
int poww(int n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return (((r*r)%mod)*poww(n,k&1))%mod;
}
int n,m;
ll b[N];
vector<int> scc[N],ve;
vector<int> out[N],in[N];
bool vis[N];
void dfs(int v){
    vis[v] = 1;
    for (int u : out[v]) if(!vis[u]) dfs(u);
    ve.pb(v);
}
void sfd(int v,int c){
    vis[v] = 1;
    for (int u : in[v]) if (!vis[u]) sfd(u,c);
    scc[c].pb(v);
}
int main(){
    cin >> n;
    rep(i,1,n+1) cin >> b[i];
    cin >> m;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        out[u].pb(v);
        in[v].pb(u);
    }
    rep(i,1,n+1) if (!vis[i]) dfs(i);
    memset(vis,0,sizeof vis);
    int c = 0;
    repr(i,n-1,0){
        if (!vis[ve[i]]){
            c++;
            sfd(ve[i],c);
        }
    }
    ll ans1 = 0,ans2 = 1;
    rep(i,1,c+1){
        int t=0,mi= 1e9+1;
        for (int u : scc[i]){
            if (b[u] < mi){
                t = 1;
                mi = b[u];
            }
            else if(b[u] == mi) t++;
        }
        ans1 += mi;
        ans2 *= t;
        ans2 %= mod;
    }
    cout << ans1 << ' ' << ans2;
}
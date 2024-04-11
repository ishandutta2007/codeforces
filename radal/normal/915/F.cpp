#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e6+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
ll n,par[N],mi[N],mx[N];
pll a[N];
bool vis[N];
vector<int> comp[N],adj[N];
int getpar(int x){
    if (par[x] == x) return x;
    return par[x] = getpar(par[x]);
}
void merge(int u,int v){
    if (getpar(u) == getpar(v)) return;
    u = par[u];
    v = par[v];
    if (comp[u].size() < comp[v].size()) swap(v,u);
    int sz = comp[v].size();
    while (sz){
        sz--;
        comp[u].pb(comp[v][sz]);
        par[comp[v][sz]] = u;
        comp[v].pop_back();
    }
    return;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i,1,n+1){
        cin >> a[i].X;
        a[i].Y = i;
        comp[i].pb(i);
        par[i] = i;
    }
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    sort(a+1,a+n+1);
    rep(i,1,n+1){
        vis[a[i].Y] = 1;
        for (int u : adj[a[i].Y]){
            if (vis[u]){
                getpar(u);
                getpar(a[i].Y);
                mx[a[i].Y] += 1ll*comp[par[u]].size()*comp[par[a[i].Y]].size();
                merge(a[i].Y,u);
            }
        }
    }
    reverse(a+1,a+n+1);
    rep(i,1,n+1){
        comp[i].clear();
        comp[i].pb(i);
        par[i] = i;
    }
    memset(vis,0,sizeof vis);
    rep(i,1,n+1){
        vis[a[i].Y] = 1;
        for (int u : adj[a[i].Y]){
            if (vis[u]){
                getpar(u);
                getpar(a[i].Y);
                mi[a[i].Y] += 1ll*comp[par[u]].size()*comp[par[a[i].Y]].size();
                merge(a[i].Y,u);
            }
        }
    }
    ll ans = 0;
    rep(i,1,n+1){
        ans += 1ll*a[i].X*(mx[a[i].Y]-mi[a[i].Y]);
    }
    cout << ans << endl;
    return 0;
}
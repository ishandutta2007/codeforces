#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 5e5+20,mod = 1e9+7 ,inf = 1e9+10,maxm = (1 << 10)+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z;
}
int n,t;
vector<int> adj[N];
pll dpd[N],dpu[N];
int sz[N];
ll ans;
void dfs2(int v,int p){
    pll mx1 = dpu[v],mx2 = {-n,0};
    for (int u : adj[v]){
        if (u == p) continue;
        int val = dpd[u].X;
        if (sz[u]&1) val++;
        else val--;
        if (val > mx1.X){
            mx2 = mx1;
            mx1 = {val,dpd[u].Y};
            continue;
        }
        if (val == mx1.X){
            mx1.Y += dpd[u].Y;
            continue;
        }
        if (val > mx2.X){
            mx2 = {val,dpd[u].Y};
            continue;
        }
        else if (val == mx2.X)
            mx2.Y += dpd[u].Y;
    }
    for (int u : adj[v]){
        if (u == p)  continue;
        int x = dpd[u].X;
        if (sz[u]&1) x++;
        else x--;
        if (x != mx1.X)
            dpu[u] = mx1;
        else{
            if (dpd[u].Y != mx1.Y)
                dpu[u] = {mx1.X,mx1.Y-dpd[u].Y};
            else
                dpu[u] = mx2;
        }
        if (sz[u]&1){
            if (t-dpd[u].X-dpu[u].X == n/2) ans += 1ll*dpd[u].Y*dpu[u].Y;
            dpu[u].X++;
        }
        else{
            ans += 1ll*(t == n/2)*sz[u]*(n-sz[u]);
            dpu[u].X--;
            if (!dpu[u].X) dpu[u].Y++;
            dpu[u] = max(dpu[u],{0,1});
        }
        dfs2(u,v);
    }
}
void dfs(int v,int p){
    sz[v] = 1;
    dpd[v] = {0,1};
    for (int u : adj[v]){
        if (u == p) continue;
        dfs(u,v);
        sz[v] += sz[u];
        if (sz[u]&1){
            if (dpd[u].X+1 == dpd[v].X)
                dpd[v].Y += dpd[u].Y;
            else if (dpd[u].X+1 > dpd[v].X)
                dpd[v] = {dpd[u].X+1,dpd[u].Y};
        }
        else{
            if (dpd[u].X-1 == dpd[v].X)
                dpd[v].Y += dpd[u].Y;
            else if (dpd[u].X-1 > dpd[v].X)
                dpd[v] = {dpd[u].X-1,dpd[u].Y};
        }
    }
    t += (sz[v]&1);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    if (n&1){
        cout << 0;
        return 0;
    }
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    dpu[1] = {0,1};
    dfs2(1,0);
    cout << ans;
}
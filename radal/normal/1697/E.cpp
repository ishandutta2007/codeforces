#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse4,avx2")
#pragma GCC optimize("unroll-loops,O2")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 1e2+20,mod = 998244353,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
//    if (a+b < 0) return a+b+mod;
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
pll p[N];
int mi[N],sz[N],fac[N],inv[N];
bool vis[N];
vector<int> adj[N],comp;
int dp[N][N];
inline int dist(pll a,pll b){
    return abs(a.X-b.X)+abs(a.Y-b.Y);
}
bool dfs(int v){
    comp.pb(v);
    vis[v] = 1;
    bool fl = 0;
    sz[v] = 1;
    for (int u : adj[v]){
        if (mi[u] < mi[v]){
            fl = 1;
            continue;
        }
        if (!vis[u]){
            fl |= dfs(u);
            sz[v] += sz[u];
        }
    }
    return fl;
}
inline int c(int r,int n){
    if (r < 0 || r > n) return 0;
    return 1ll*fac[n]*inv[r]%mod*inv[n-r]%mod;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i,0,n){
        cin >> p[i].X >> p[i].Y;
        mi[i] = 2*inf;
        rep(j,0,i){
            int d = dist(p[i],p[j]);
            if (d == mi[i])
                adj[i].pb(j);
            if (d < mi[i]){
                adj[i].clear();
                adj[i].pb(j);
                mi[i] = d;
            }
            if (d == mi[j])
                adj[j].pb(i);
            if (d < mi[j]){
                adj[j].clear();
                adj[j].pb(i);
                mi[j] = d;
            }
        }
    }
    int t = 0;
    vector<int> ve;
    fac[0] = inv[0] = 1;
    rep(i,0,n){
        if (vis[i]) continue;
        comp.clear();
        bool f = dfs(i);
        if (f || sz[i] == 1){
            t += sz[i];
            continue;
        }
        int d = dist(p[comp[0]],p[comp[1]]);
        for (int u : comp){
            for (int v : comp){
                if (u == v) continue;
                if (dist(p[u],p[v]) != d){
                    f = 1;
                    break;
                }
            }
            if (f) break;
        }
        if (f){
            t += sz[i];
            continue;
        }
        ve.pb(sz[i]);
    }
    rep(i,1,n+1){
        fac[i] = 1ll*i*fac[i-1]%mod;
        inv[i] = poww(fac[i],mod-2);
    }
    int sz = ve.size();
    if (!sz){
        debug(1);
        cout << fac[n];
        return 0;
    }
    rep(i,0,sz){
        rep(j,i+1,n-t+1){
            if (!i){
                if (j == 1) dp[i][j] = 1;
                else if (j == ve[i]) dp[i][j] = 1;
                continue;
            }
            if (j < ve[i]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = mkay(dp[i-1][j-1],dp[i-1][j-ve[i]]);
        }
    }
    int ans = 0;
    rep(i,0,n-t+1){
        ans = mkay(ans,1ll*c(i+t,n)*fac[i+t]%mod*dp[sz-1][i]%mod);
    }
    cout << ans;
}
#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,avx2")
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
constexpr int N = 50+10,mod = 998244353,inf = 1e9+10;
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
        k /= 2;
    } 
    return z; 
}
int dp[N][N],d[N][N],sum,cnt[N],s;
vector<pll> adj[N];
vector<int> l;
void dfs(int v,int p,int r){
    for (pll u : adj[v]){
        if (u.X == p) continue;
        d[r][u.X] = d[r][v]+u.Y;
        dfs(u.X,v,r);
    }
}
void dfs2(int v,int p){
    sum += cnt[v];
    if (adj[v].size() == 1) l.pb(v);
    for (pll u : adj[v]){
        if (u.X != p){
            dfs2(u.X,v);
        }
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i,1,n){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    rep(i,1,n+1) dfs(i,0,i);
    int m;
    cin >> s >> m;
    vector<int> leaf;
    rep(i,1,n+1) if (adj[i].size() == 1) leaf.pb(i);
    rep(j,1,m+1){
        for (int i : leaf){
            vector<int> ve;
            for (int u : leaf){
                if (u == i) continue;
                rep(v,0,j) ve.pb(dp[u][v]+d[i][u]);
            }
            sort(all(ve));
            dp[i][j] = ve[ve.size()-j];
        }
    }
    if (adj[s].size() == 1){
        cout << dp[s][m];
        return 0;
    }
    rep(i,0,m){
        int x;
        cin >> x;
        cnt[x]++;
    }
    int mi = inf;
    for (pll u : adj[s]){
        dfs2(u.X,s);
        if (!sum){
            l.clear();
            continue;
        }
        vector<int> ve;
        for (int u : l){
            rep(v,1,sum+1){
                ve.pb(d[s][u]+dp[u][m-v]);
            }
        }
        sort(all(ve));
        mi = min(mi,ve[ve.size()-sum]);
        sum = 0;
        l.clear();
    }
    cout << mi;
    return 0;
}
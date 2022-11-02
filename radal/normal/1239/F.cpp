#include <bits/stdc++.h>
#pragma GCC target("sse,sse2")
#pragma GCC optimize("unroll-loops,O3")
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
constexpr int N = 5e5+20,mod = 998244353,inf = 1e9+10,sq = 340;
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
vector<int> adj[N],ve[N],g[N];
int deg[N],par[N],h[N],n,ch[N],r,T;
bool vis[N],go[N];
bool dfs2(int v,int p){
    par[v] = p;
    vis[v] = 1;
    if (v != r){
        for (int u : adj[v]){
            if (u == p) continue;
            if (vis[u]){
                ch[v] = v;
                continue;
            }
            h[u] = h[v]+1;
            dfs2(u,v);
            if (ch[v] != v && ch[u] != -1) ch[v] = ch[u];
        }
        return 0;
    }
    int perv = -1;
    for (int u : adj[v]){
        if (vis[u]) continue;
        h[u] = 1;
        dfs2(u,v);
        if (perv == -1){
            perv = ch[u];
            continue;
        }
        if (h[perv]+h[ch[u]]+1 == n) return 0;
        go[v] = 1;
        int cur = perv,ans = n-1;
        while (cur != v){
            go[cur] = 1;
            ans--;
            cur = par[cur];
        }
        cur = ch[u];
        while (cur != v){
            go[cur] = 1;
            ans--;
            cur = par[cur];
        }
        cout << "Yes" << endl << ans << endl;
        rep(i,1,n+1) if (!go[i]) cout << i << ' ';
        cout << endl;
        return 1;
    }
    return 0;
}
bool dfs(int v,int p){
    par[v] = p;
    vis[v] = 1;
    if (p && !ve[p].empty() && !ve[v].empty() && ve[v][0] != ve[p][0]){
        cout << "Yes" << endl << n-4 << endl;
        rep(i,1,n+1){
            if (i == p || i == v || i == ve[v][0] || i == ve[p][0]) continue;
            cout << i << ' ';
        }
        cout << endl;
        return 1;
    }
    int mx = -1;
    for (int u : g[v]){
        if (u == p || !vis[u]) continue;
        mx = max(mx,h[u]);
    }
    if (mx != -1){
        cout << "Yes" << endl << n-(h[v]-mx+1) << endl;
        int cur = v;
        while (cur && h[cur] >= mx){
            go[cur] = 1;
            cur = par[cur];
        }
        rep(i,1,n+1) if (!go[i]) cout << i << ' ';
        cout << endl;
        return 1;
    }
    if (!ve[v].empty()) ch[v] = v;
    for (int u : g[v]){
        if (u == p) continue;
        h[u] = h[v]+1;
        if (dfs(u,v)) return 1;
        if (ch[u] == -1) continue;
        if (ch[v] == -1){
            ch[v] = ch[u];
            continue;
        }
        if (ve[ch[v]][0] == ve[ch[u]][0]) continue;
        int cur = ch[v];
        int ans = n-3;
        go[v] = 1;
        go[ve[ch[v]][0]] = 1;
        go[ve[ch[u]][0]] = 1;
        while (cur != v){
            go[cur] = 1;
            ans--;
            cur = par[cur];
        }
        cur = ch[u];
        while (cur != v){
            go[cur] = 1;
            ans--;
            cur = par[cur];
        }
        cout << "Yes" << endl << ans << endl;
        rep(i,1,n+1) if (!go[i]) cout << i << ' ';
        cout << endl;
        return 1;
    }
    return 0;
}
void solve(){
    int m;
    cin >> n >> m;
    rep(i,1,n+1){
        deg[i] = 0;
        ch[i] = -1;
        adj[i].clear();
        ve[i].clear();
        g[i].clear();
        vis[i] = 0;
        h[i] = 0;
        go[i] = 0;
    }
    int mx = 0;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[v]++;
        deg[u]++;
        mx = max({mx,deg[u],deg[v]});
    }
    if (n <= 3 || mx == 2){
        cout << "No" << endl;
        return;
    }
    rep(i,1,n+1){
        if (deg[i]%3 == 0){
            cout << "Yes" << endl;
            cout << n-1 << endl;
            rep(j,1,i) cout << j << ' ';
            rep(j,i+1,n+1) cout << j << ' ';
            cout << endl;
            return;
        }
    }
    rep(i,1,n+1){
        if (deg[i]%3 == 1){
            for (int u : adj[i]){
                if (deg[u]%3 == 1){
                    cout << "Yes" << endl;
                    cout << n-2 << endl;
                    if (u < i) swap(u,i);
                    rep(j,1,i) cout << j << ' ';
                    rep(j,i+1,u) cout << j << ' ';
                    rep(j,u+1,n+1) cout << j << ' ';
                    cout << endl;
                    return;
                }
                if (!ve[u].empty()){
                    cout << "Yes" << endl << n-3 << endl;
                    int v = ve[u].back();
                    rep(j,1,n+1){
                        if (v == j || u == j || i == j) continue;
                        cout << j << ' ';
                    }
                    cout << endl;
                    return;
                }
                ve[u].pb(i);
            }
        }
        else{
            for(int u : adj[i])
                if (2  == deg[u]%3)
                    g[i].pb(u);
        }
    }
    rep(i,1,n+1) if (!vis[i] && deg[i]%3 == 2) if (dfs(i,0)) return;
    rep(i,1,n+1){
        vis[i] = 0;
        ch[i] = -1;
    }
    rep(i,1,n+1){
        if (deg[i]%3 == 1){
            h[i] = 0;
            r = i;
            if (dfs2(i,0)) return;
            break;
        }
    }
    cout << "No" << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> T;
    rep(i,0,T){
        solve();
    }
    return 0;
}
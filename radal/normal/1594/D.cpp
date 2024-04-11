#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const int N = 5e5+20,mod = 1e9+7,inf = 2e9,sq = 400;
int poww(int n,ll k){
    if (!k) return 1;
    if (k == 1) return n;
    int r = poww(n,k/2);
    return 1ll*r*r%mod*poww(n,k&1)%mod;
}
pair<pll,bool> e[N];
int par[N];
vector<int> adj[N];
pair<int,bool> vis[N];
int cnt[N][2],sz[N];
int getpar(int v){
    if (par[v] == v)
        return v;
    return par[v] = getpar(par[v]);
}
inline void mg(int u,int v){
    u = getpar(u);
    v = getpar(v);
    if (u == v) return;
    par[v] = u;
}
bool dfs(int v,int t,bool c){
    vis[v] = {t,c};
    for (int u : adj[v]){
        if (vis[u].X){
            if (vis[u].Y == c) return 1;
            continue;
        }
        if (dfs(u,t,1-c)) return 1;
    }
    return 0;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        int n,m;
        cin >> n >> m;
        rep(i,1,n+1){
            par[i] = i;
            adj[i].clear();
            vis[i] = {0,0};
            sz[i] = 0;
        }
        rep(i,0,m){
            int u,v;
            string s;
            cin >> u >> v >> s;
            if (s[0] == 'i')
                e[i] = {{u,v},1};
            else{
                e[i] = {{u,v},0};
                mg(u,v);
            }
        }
        bool f = 0;
        rep(i,0,m){
            if (e[i].Y){
                int u = getpar(e[i].X.X),v = getpar(e[i].X.Y);
                if (u == v){
                    f = 1;
                    break;
                }
                adj[u].pb(v);
                adj[v].pb(u);
            }
        }
        if (f){
            cout << -1 << endl;
            continue;
        }
        int t = 0;
        rep(i,1,n+1){
            int u = getpar(i);
            if (!vis[u].X){
                t++;
                if (dfs(u,t,1)){
                    f = 1;
                    break;
                }
            }
        }
        if (f){
            cout << -1 << endl;
            continue;
        }
        rep(i,1,n+1) sz[par[i]]++;
        rep(i,1,t+1) cnt[i][0] = cnt[i][1] = 0;
        rep(i,1,n+1){
            if (par[i] == i)
                cnt[vis[i].X][vis[i].Y] += sz[i];
        }
        int ans = 0;
        rep(i,1,t+1) ans += max(cnt[i][0],cnt[i][1]);
        cout << ans << endl;
    }
}
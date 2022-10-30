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
const long long int N = 5e5+20,mod = 1e9+7,inf = 1e9,sq = 65,maxm = 3e4+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,ll k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int fix[N],n,d[N];
vector<pll> adj[N];
set<pll> G[N];
void bfs(){
    queue<int> q;
    q.push(n);
    d[n] = 0;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        int sz = adj[v].size();
        bool f = 0;
        rep(i,0,sz){
            if (f){
                f = 0;
                continue;
            }
            int u = adj[v][i].X;
            if (fix[u] == -1){
                if (adj[v][i].Y == 1 || i == sz-1 || adj[v][i+1].X != u){
                    fix[u] = 1-adj[v][i].Y;
                    continue;
                }
                f = 1;
                if (d[u] > d[v]+1){
                    d[u] = d[v]+1;
                    q.push(u);
                }
                continue;
            }
            if (fix[u] == adj[v][i].Y){
                if (d[u] > d[v]+1){
                    d[u] = d[v]+1;
                    q.push(u);
                    continue;
                }
            }
        }
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    memset(fix,-1,sizeof fix);
    memset(d,63,sizeof d);
    int m;
    cin >> n >> m;
    rep(i,0,m){
        int u,v,w;
        cin >> u >> v >> w;
        G[v].insert({u,w});
    }
    rep(i,1,n+1) for (pll u : G[i]) adj[i].pb(u);
    fix[n] = 1;
    bfs();
    if (d[1] > inf) cout << -1 << endl;
    else cout << d[1] << endl;
    rep(i,1,n+1){
        if (fix[i] == -1) fix[i] = 1;
        cout << fix[i];
    }
}
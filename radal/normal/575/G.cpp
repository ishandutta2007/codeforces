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
typedef pair<int,int> pll;
const long long int N=1e5+25,mod = 1e9+7,inf=1e16,maxq = 5e5+30,maxm = 1e3+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
int n,m,d[N];
pll par[N];
bool mark[N],vis[N];
vector<pll> adj[N],dag[N];
void dfs(){
    queue<int> q;
    mark[n-1] = 1;
    vis[n-1] = 1;
    q.push(n-1);
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (pll u : adj[v]) if (!vis[u.X] && u.Y == 0){
            vis[u.X] = 1;
            mark[u.X] = 1;
            q.push(u.X);
            par[u.X].X = v;
            par[u.X].Y = 0;
        }
    }
    /*for (pll u : adj[v]){
        if (!(u.Y|vis[u.X])){
            par[u.X].X = v;
            par[u.X].Y = 0;
            dfs(u.X);
        }
    }*/
    return;
}
void bfs(){
    queue<int> q;
    rep(i,0,n){
        if (mark[i]){
            d[i] = 0;
            q.push(i);
        }
    }
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (pll v : adj[u]){
            if(d[v.X] == -1){
                d[v.X] = d[u]+1;
                q.push(v.X);
            }
         }
    }
    return;
}
void dg(int v){
    vis[v] = 1;
    for(pll u : adj[v]){
        //if (vis[u.X]) continue;
        if (d[u.X]+1 == d[v]){
            dag[u.X].pb({v,u.Y});
            if (!vis[u.X]) dg(u.X);
        }
        //if (!vis[u.X]) dg(u.X);
    }
}
void ans(){
    memset(vis,0,sizeof vis);
    bool f = 0;
    vector<int> ve,ve2;
    rep(i,0,n){
        if (mark[i]){
            ve.pb(i);
            vis[i] = 1;
        }
    }
    rep(i,1,100000){
        if (f) break;
        ve2.clear();
        int mi = 30;
        for (int u : ve){
            vis[u] = 1;
            for(pll v : dag[u]){
                if (v.X == 0){
                    if (par[v.X].Y == -1 || par[0].Y > v.Y){
                        par[0] = {u,v.Y};
                        f = 1;
                    }
                }
                if (vis[v.X]) continue;
                if (v.Y < mi){
                    ve2.clear();
                    mi = v.Y;
                    ve2.pb(v.X);
                    if (u == 3) debug(v.X);
                    par[v.X] = {u,v.Y};
                }
                else if (v.Y == mi){
                    ve2.pb(v.X);
                    par[v.X] = {u,v.Y};
                }
            }
            if (!u) f = 1;
        }
        swap(ve2,ve);
    }
}
int main(){
    ios:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(d,-1,sizeof d);
    cin >> n >> m;
    rep(i,0,m){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    rep(i,0,n) par[i] = {-1,-1};
    dfs();
    if (mark[0]){
        cout << 0 << endl;
        int v = 0;
        vector<int> ve;
        while (v != -1){
            ve.pb(v);
            v = par[v].X;
        }
        cout << ve.size() << endl;
        for (int u : ve) cout << u << ' ' ;
        return 0;
    }
    bfs();
    memset(vis,0,sizeof vis);
    dg(0);
    ans();
    int v = 0;
    string s = "";
    vector<int> ve;
    while (v != -1){
        ve.pb(v);
        if (par[v].Y != -1 && !mark[v]) s = char(par[v].Y+int('0'))+s;
        v = par[v].X;
    }
    cout << s << endl;
    cout << ve.size() << endl;
    for (int u : ve) cout << u << ' ';
    return 0;
}
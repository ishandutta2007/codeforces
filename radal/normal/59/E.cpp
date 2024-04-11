#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
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
const long long int N=3e3+20,mod = 1e9+7,inf=3e8,maxk = 1e5+20;
const long double eps = 0.0001;
vector <int> adj[N];
vector <pll> adj2[N];
pair<pll,ll> bad[maxk];
int par[N][N];
ll d[N][N];
int k;
bool vis[N][N];
void bfs(){
    queue<pll> q;
    for (int u : adj[1]){
        d[1][u] = 1;
        par[1][u] = -1;
        q.push({1,u});
        vis[1][u] = 1;
    }
    while (!q.empty()){
        pll p= q.front();
        q.pop();
        for (int u :  adj[p.Y]){
            pair<pll,ll> x = {p,u};
            if (!d[p.Y][u]){
                vis[p.Y][u] = 1;
                int ind = lower_bound(bad,bad+k,x)-bad;
                if (bad[ind] != x){
                    d[p.Y][u] = d[p.X][p.Y]+1;
                    par[p.Y][u] = p.X;
                    q.push({p.Y,u});
                }
            } 
        }
    }
    return;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(); cout.tie();
    int n,m;
    cin >> n >> m >> k;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep(i,0,k) cin >> bad[i].X.X >> bad[i].X.Y >> bad[i].Y;
    sort(bad,bad+k);
    bfs();
    ll mi = inf,ind = -1;
    rep(i,1,n){
        if (d[i][n] < mi && d[i][n]){
            mi = d[i][n];
            ind = i;
        }
    }
    if (ind == -1){
        cout << -1;
        return 0;
    }
    int u = ind,v = n;
    vector<int> ve;
    ve.pb(n);
    while (u > 0){
        ve.pb(u);
        int w = v;
        v = u;
        u = par[u][w];
    }
    reverse(ve.begin(),ve.end());
    cout << ve.size()-1 << endl;
    debug(d[3][2]);
    for (int u : ve) cout << u << ' ';
    return 0;

}
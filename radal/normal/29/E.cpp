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
typedef pair<ll,ll> pll;
const long long int N=5e2+20,mod = 1e9+7,inf=8e18,maxk = 1e5+20;
const long double eps = 0.0001;
vector<int> adj[N];
int d[N][N][2];
pll par[N][N][2];
int n,m;
void bfs(){
    queue<pair<pll,bool> > q;
    q.push({{1,n},0});
    par[1][n][0] = {0,0};
    while(!q.empty()){
        auto p = q.front();
        int u = p.X.X,v = p.X.Y;
        q.pop();
        if (p.Y){
            for (int w : adj[v]){
                if (par[u][w][0].X == -1){
                    d[u][w][0] = d[u][v][1]+1;
                    par[u][w][0] = {u,v};
                    q.push({{u,w},0});
                }
            }
        }
        else{
            for (int w : adj[u]){
                if (par[w][v][1].X == -1){
                    d[w][v][1] = d[u][v][0]+1;
                    par[w][v][1] = {u,v};
                    q.push({{w,v},1});
                }
            }
        }
    }
}
int main(){
    cin >> n >> m;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep(i,1,n+1){
        rep(j,1,n+1){
            par[i][j][0] = {-1,-1};
            par[i][j][1] = {-1,-1};
        }
    }
    rep(i,1,n+1) par[i][i][0].X = 0;
    bfs();
    if (!d[n][1][0]){
        cout << -1;
        return 0;
    }
    cout << d[n][1][0]/2 << endl;
    int u = n,v = 1,i = 0;
    vector<int> ve1,ve2;
    while (par[u][v][i].X){
        if (i) ve2.pb(u);
        else ve1.pb(v);
        pll p = par[u][v][i];
        i = 1-i;
        u = p.X;
        v = p.Y;
    }
    ve2.pb(1);
    ve1.pb(n);
    reverse(ve1.begin(),ve1.end());
    reverse(ve2.begin(),ve2.end());
    for (int w : ve2)cout  << w << ' ';
    cout << endl;
    for (int w : ve1) cout << w << ' ';
    return 0;
}
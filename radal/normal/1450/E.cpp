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
const long long int N=3e2+20,mod = 1e9+7,inf=3e16,maxk = 1e5+20;
const long double eps = 0.0001;
int n,m,vert;
vector<int> adj[N];
ll d[N][N];
int vis[N];
bool dfs(int v,int c){
    vis[v] = c;
    for (int u : adj[v]){
        if (vis[u] == c) return 0;
        if (!vis[u] && !dfs(u,3-c)) return 0;
    }
    return 1;
}
int main(){
    memset(d,63,sizeof d);
    cin >> n >> m;
    rep(i,0,m){
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].pb(v);
        adj[v].pb(u);
        if (w){
            d[u][v] = 1;
            d[v][u] = -1;
        }
        else{
            d[u][v] = 1;
            d[v][u] = 1;
        }
    }
    if (!dfs(1,1)){
        cout << "NO";
        return 0;
    }
    ll mx = -20;
    rep(i,1,n+1) d[i][i] = 0;
    rep(k,1,n+1){
        rep(i,1,n+1){
            rep(j,1,n+1){
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    rep(i,1,n+1){
        if (d[i][i] < 0){
            cout << "NO";
            return 0;
        }
    }
    rep(i,1,n+1){
        rep(j,1,n+1){
            if (d[i][j] > mx){
                mx = d[i][j];
                vert = i;
            }
        }
    }
    cout << "YES" << endl << mx << endl;
    rep(i,1,n+1) cout << d[vert][i] << ' ' ;

}
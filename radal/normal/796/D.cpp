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
const long long int N=3e5+20,mod = 1e9+7,inf=3e8;
const long double eps = 0.0001;
ll par[N],dis[N];
int k,d,cnt;
pll edge[N];
vector<int> adj[N],sc;
void bfs(){
    queue <int> q;
    for (int u : sc){
        q.push(u);
        par[u] = u;
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u : adj[v]){
            if (!par[u]){
                par[u] = par[v];
                q.push(u);
            }
            if (par[u] != par[v]){
              //  debug(u);
            //    debug(v);
          //      cnt++;
            }
        }
    }
}
int main(){
    int n;
    cin >> n >> k >> d;
    rep(i,0,k){
        int v;
        cin >> v;
        sc.pb(v);
    }
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        edge[i+1] = {u,v};
    }
    bfs();
    vector<int> ve;
    rep(i,1,n){
        if (par[edge[i].X] != par[edge[i].Y]){
            cnt++;
            ve.pb(i);
        }
    }
    cout << cnt << endl;
    for (int u : ve) cout << u << ' ';
    return 0;
}
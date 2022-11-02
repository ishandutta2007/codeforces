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
typedef pair<ll,ll> pll;
const long long int N=5e5+20,mod = 1e9+7,inf=4e18,maxm = 2e5+20;
const long double eps = 0.0001;
ll n,m;
bool vis[N];
int d[N];
vector<int> adj[N];
void bfs(int v){
    d[v] = 0;
    queue<int> q;
    q.push(v);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int w : adj[u]){
            if(d[w] == -1){
                d[w] = d[u]+1;
                q.push(w);
            }
        }
    }
    return;
}
int main(){
    memset(d,-1,sizeof d);
    cin >> n >> m;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bfs(1);
    int sc = 1,mx = 0;
    rep(i,1,n+1){
        if (d[i] > mx){
            mx = d[i];
            sc = i;
        }
    }
    memset(d,-1,sizeof d);
    bfs(sc);
    mx = 0;
    rep(i,1,n+1) mx = max(d[i],mx);
    cout << mx;
}
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
const long long int N=1e3+20,mod = 1e9+7,inf=8e18,maxk = 1e5+20;
const long double eps = 0.0001;
bool mark[N][N];
vector<int> adj[N];
int n,m,s,t;
int d[N],d2[N];
void bfs(){
    queue<int> q;
    d[s] = 0;
    q.push(s);
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int u : adj[v]){
            if (d[u] == -1){
                d[u] = d[v]+1;
                q.push(u);
            }
        }
    }
}
void bfs2(){
    queue<int> q;
    d2[t] = 0;
    q.push(t);
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int u : adj[v]){
            if (d2[u] == -1){
                d2[u] = d2[v]+1;
                q.push(u);
            }
        }
    }
}
int main(){
    memset(d,-1,sizeof d);
    memset(d2,-1,sizeof d2);
    cin >> n >> m >> s >> t;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        mark[u][v] = 1;
        mark[v][u] = 1;
    }
    bfs();
    bfs2();
    ll cnt = 0;
    rep(i,1,n+1){
        rep(j,i+1,n+1){
            if (!mark[i][j] && (d[i]+d2[j]+1 >= d[t] && d[j]+d2[i]+1 >= d[t])){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
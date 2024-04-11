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
const long long int N=1e3+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
vector <int> adj[N];
int visited[N],col[N];
int dist[N][N],mx[N];
bool dfs(int v,int t){
    for (int u : adj[v]){
        if (!visited[u]){
            visited[u] = t;
            col[u] = 2-col[v]+1;
            if (!dfs(u,t)) return 0;
        }
        else if (col[u] == col[v]) return 0;
    }
    return 1;
}

void bfs(int v){
    queue <int> q;
    q.push(v);
    dist[v][v] = 1;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int w : adj[u]){
            if (!dist[v][w]){
                dist[v][w] = dist[v][u]+1;
                q.push(w);
            }
        }
    }
    return;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    int n,m;
    cin >> n >> m;
    rep(i,0,m){
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int t = 1;
    rep(i,1,n+1){
        if (visited[i]) continue;
        col[i] = 1;
        visited[i] = t;
        if (!dfs(i,t)){
            cout << -1;
            return 0;
        }
        t++;
    }
    rep(i,1,n+1){
        bfs(i);
        rep(j,1,n+1){
            mx[visited[i]] = max(mx[visited[i]],dist[i][j]-1);
        }
    }
    ll ans = 0;
    rep(i,1,n+1) ans += mx[i];
    cout << ans;
    return 0;
}
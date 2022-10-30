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
const long long int N=2e5+20,mod = 1e9+7,inf=2e8;
const long double eps = 0.0001;
int n,m,k,s,t;
vector <int> sc;
bool blue[N];
vector <int> adj[N],adj2[N];
pll dist[N];
bool vis[N];
void check(int v){
    vis[v] = 1;
    for (int u : adj2[v]){
        if (!vis[u]) check(u);
    }
    return;
}
bool bfs(int mid){
    memset(vis,0,sizeof vis);
    rep(i,0,n){
        dist[i] = {0,0};
        adj2[i].clear();
    }
    queue <pll> q;
    for (int u : sc){
        dist[u].X = 1;
        dist[u].Y = u;
        q.push({u,u});
    }
    while (!q.empty()){
        pll v = q.front();
        q.pop();
        for (int u : adj[v.X]){
            if (!dist[u].X){
                dist[u].X = dist[v.X].X+1;
                dist[u].Y = v.Y;
                q.push({u,v.Y});
            }
            else{
                if (dist[u].X+dist[v.X].X-1 <= mid){
                    adj2[dist[u].Y].pb(dist[v.X].Y);
                    adj2[dist[v.X].Y].pb(dist[u].Y);
                }
            }
        }
    }
    check(s);
    if (!vis[t]) return 0;
    return 1;
}
int binary(int l,int r){
    int mid;
    while (r-l > 1){
        mid = (l+r)/2;
        if (bfs(mid)) r = mid;
        else l = mid;
    }
    if (r != n+1) return r;
    else return -1;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    rep(i,0,k){
        int a;
        cin >> a;
        sc.pb(a);
        blue[a] = 1;
    }
    rep(i,0,m){
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    cin >> s >> t;
    if (!blue[t])
        sc.pb(t);
    cout << binary(0,n+1);
    return 0;
}
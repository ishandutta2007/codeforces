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
const long long int N=1e5+30,mod = 1e9+7,inf=2e5;
const long double eps = 0.0001;
int dist[N],mx[N],dist2[N],n;
vector <pair<pll,int> > adj[N];
pll p[N];
pair<pll,pll> edge[N];
void bfs(){
    dist[1] = 1;
    queue <int> q;
    q.push(1);
    p[1].X = -1;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (auto u : adj[v]){
            if (!dist[u.X.X]){
                dist[u.X.X] = dist[v]+1;
                q.push(u.X.X);
                p[u.X.X].X = v;
                p[u.X.X].Y = u.Y;
            }
            if (dist[u.X.X] < dist[v]){
                if (mx[v] < mx[u.X.X]+u.X.Y){
                    mx[v] = mx[u.X.X]+u.X.Y;
                    p[v].X = u.X.X;
                    p[v].Y = u.Y;
                }
            }
        }
    }
    return;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m,cnt = 0;
    cin >> n >> m;
    rep(i,0,m){
        int x,y,z;
        cin >> x >> y >> z;
        adj[x].pb({{y,z},i});
        adj[y].pb({{x,z},i});
        if (z) cnt++;
        edge[i].Y.Y = z;
        edge[i].X.X = x;
        edge[i].X.Y = y;
    }
    bfs();
    int ans = 0;
    cout << dist[n]+cnt-2*mx[n]-1 << endl;
    int v = n;
    while (p[v].X != -1){
        edge[p[v].Y].Y.X = 1;
        if (edge[p[v].Y].Y.Y == 0){
            cout << p[v].X << ' ' << v << ' ' << 1 << endl;
        }
        v = p[v].X;
    }
    rep(i,0,m) if (edge[i].Y.X == 0 && edge[i].Y.Y == 1) cout << edge[i].X.X << ' ' << edge[i].X.Y << ' ' << 0 << endl;
    return 0;
}
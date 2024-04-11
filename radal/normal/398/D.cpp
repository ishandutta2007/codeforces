#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const int N = 5e4+20,mod = 1e9+7,inf = 2e9,sq = 600;
bool on[N],mark[N];
int d[N],ans[N];
unordered_set<int> adj[N];
pair<char,pll> que[N*5];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,q,o;
    cin >> n >> m >> q >> o;
    rep(i,0,o){
        int j;
        cin >> j;
        on[j] = 1;
    }
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        d[u]++;
        d[v]++;
        if (d[u] == sq) mark[u] = 1;
        if (d[v] == sq) mark[v] = 1;
    }
    rep(i,0,q){
        cin >> que[i].X >> que[i].Y.X;
        if (que[i].X == 'A' || que[i].X == 'D'){
            cin >> que[i].Y.Y;
            if (que[i].X == 'A'){
                d[que[i].Y.X]++;
                d[que[i].Y.Y]++;
                if (d[que[i].Y.X] == sq) mark[que[i].Y.X] = 1;
                if (d[que[i].Y.Y] == sq) mark[que[i].Y.Y] = 1;
            }
            else{
                d[que[i].Y.X]--;
                d[que[i].Y.Y]--;
            }
        }
        else que[i].Y.Y = -1;
    }
    vector<int> big;
    big.reserve(600);
    int sz = 0;
    rep(i,1,n+1)
        if (mark[i]) big.pb(i),sz++;
    rep(i,1,n+1){
        for (int u : adj[i]){
            if (mark[u]) continue;
            ans[i] += on[u];
        }
    }
    rep(i,0,q){
        int u = que[i].Y.X,v = que[i].Y.Y;
        if (que[i].X == 'O'){
            on[u] = 1;
            if (!mark[u]) for (int w : adj[u]) ans[w]++;
            continue;
        }
        if (que[i].X == 'F'){
            on[u] = 0;
            if (!mark[u]) for (int w : adj[u]) ans[w]--;
            continue;
        }
        if (que[i].X == 'A'){
            adj[u].insert(v);
            adj[v].insert(u);
            if (!mark[v] && on[v]) ans[u]++;
            if (!mark[u] && on[u]) ans[v]++;
            continue;
        }
        if (que[i].X == 'D'){
            adj[u].erase(v);
            adj[v].erase(u);
            if (!mark[v] && on[v]) ans[u]--;
            if (!mark[u] && on[u]) ans[v]--;
            continue;
        }
        int out = ans[u];
        auto it = adj[u].end();
        rep(i,0,sz){
            if (!on[big[i]]) continue;
            if (adj[u].find(big[i]) != it) out++;
        }
        cout << out << endl;
    }
}
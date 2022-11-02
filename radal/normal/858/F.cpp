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
const long long int N=2e5+20,mod = 1e9+7,inf=2e8;
const long double eps = 0.0001;
vector<pll> adj[N];
vector <pair<pll,int> > ans;
bool visited[N],vis[N];
void dfs(int v,int p){
    visited[v] = 1;
    int x = -1,ind = -1;
    for (pll u : adj[v]) if (!visited[u.X]) dfs(u.X,v);
    for (auto u : adj[v]){
        if (u.X == -1) continue;
        if (!vis[u.Y] && u.X != p){
            if (x != -1){
                ans.pb({{u.X,v},x});
                x = -1;
                vis[u.Y] = 1;
                vis[ind] = 1;
            }
            else{
                x = u.X;
                ind = u.Y;
            }
        }
    }
    if (x != -1 && p != -1){
        ans.pb({{p,v},x});
        int i = 0;
        for (auto u : adj[p]){
            if (u.X == v){
                vis[u.Y] = 1;
                vis[ind] = 1;
                break;
            }
            i++;
        }
    }
    return;

}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    rep(i,0,m){
        int x,y;
        cin >> x >> y;
        adj[x].pb({y,i});
        adj[y].pb({x,i});
    }
    rep(i,1,n+1) if (!visited[i]) dfs(i,-1);
    cout << ans.size() << endl;
    for (auto u : ans){
        cout << u.X.X << ' ' << u.X.Y << ' ' << u.Y << endl;
    }
    return 0;
}
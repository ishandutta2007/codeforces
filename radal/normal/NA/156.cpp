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
typedef pair<int,ll> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
int n;
vector <pll> adj[3*N];
bool vis[4*N],visited[4*N],ans[N];
void dfs(int v,bool c){
    visited[v] = 1;
    while (!adj[v].empty()){
        pll u = adj[v].back();
        adj[v].pop_back();
        if (vis[u.Y]) continue;
        vis[u.Y] = 1;
        if (u.Y < n) ans[u.Y] = c;
        if (min(u.X,v) < N && max(v,u.X) > N){
            dfs(u.X,!c);
        }
        else dfs(u.X,c);
    }
    return;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i,0,n){
        int x,y;
        cin >> x >> y;
        adj[x].pb({y+N,i});
        adj[y+N].pb({x,i});
    }
    int p = n+1,a=-1;
    rep(i,0,3*N){
        if (adj[i].size()%2){
            if (a == -1) a = i;
            else{
                adj[a].pb({i,p});
                adj[i].pb({a,p});
                p++;
                a = -1;
            }
        }
    }
    rep(i,1,3*N){
        if (!visited[i]) dfs(i,0);
    }
    rep(i,0,n){
        if (ans[i]) cout << 'b';
        else cout << 'r';
    }
}
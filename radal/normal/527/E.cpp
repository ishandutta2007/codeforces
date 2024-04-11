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
const long long int N=1e5+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
int n,m;
int pts[N];
vector <pll> adj[N];
bool visited[6*N];
vector <int> ve;
void dfs(int v){
    int sz = adj[v].size();
    while (!adj[v].empty()){
        pll u = adj[v].back();
        adj[v].pop_back();
        if (!visited[u.Y]){
            visited[u.Y] = 1;
            dfs(u.X);
        }
    }
    ve.pb(v);
    return;
} 
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    int p = m;
    rep (i,0,m){
        int x,y;
        cin >> x >> y;
        adj[x].pb({y,i});
        adj[y].pb({x,i});
    }
    int a=-1;
    rep(i,1,n+1){
        if(adj[i].size()%2){
            if (a == -1) a = i;
            else{
                adj[a].pb({i,p});
                adj[i].pb({a,p});
                a = -1;
                p++;
            }
        }
    }
    dfs(1);
    if (p % 2){
        cout << p+1 << endl;
    }
    else cout << p << endl;
    for(int i = 1; i < p+1; i++){
        if (i >= ve.size()) break;
        if (i%2) cout << ve[i-1] << ' ' << ve[i] << endl;
        else cout << ve[i] << ' ' << ve[i-1] << endl;
    }
    if (p%2) cout << 1 << ' ' << 1 << endl;
    return 0;
}
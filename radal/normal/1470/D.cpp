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
const long long int N=3e5+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
vector<int> adj[N];
int d[N];
vector<int> gg;
void dfs(int v){
    d[v] = 1;
    gg.pb(v);
    vector<int> ve;
    for (int u : adj[v]){
        if (!d[u]) ve.pb(u);
        d[u] = 2;
    }
    for (int u : ve){
        for (int w : adj[u]) if (!d[w]) dfs(w);
    }
    return;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    vector <int> ve;
    while (T--){
        int n,m;
        cin >> n >> m;
        rep(i,1,n+1){
            adj[i].clear();
            d[i] = 0;
        }
        rep(i,0,m){
            int u,v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        if (m < n-1){
            cout << "NO" << endl;
            continue;
        }
        gg.clear();
        dfs(1);
        bool f = 1;
        rep(i,1,n+1) if (!d[i]) f = 0;
        if (f){
            cout << "YES" << endl;
            cout << gg.size() << endl;
            for (int u : gg) cout << u << ' ';
            cout << endl;
        }
        else cout << "NO" << endl;

    }
    return 0;
}
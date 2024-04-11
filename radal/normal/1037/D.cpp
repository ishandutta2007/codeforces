#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2")
//#pragma GCC optimize("unroll-loops,O3")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 2e5+10,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z; 
}
vector<int> adj[N],out[N];
int h[N],par[N],a[N],ind[N];
void dfs(int v,int p){
    for (int u : adj[v]){
        if (u != p){
            par[u] = v;
            h[u] = h[v]+1;
            dfs(u,v);
        }
    }
}
inline bool cmp(int i,int j){
    return (ind[i] < ind[j]);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    rep(i,0,n){
        cin >> a[i];
        ind[a[i]] = i;
    }
    if (a[0] != 1){
        cout << "No";
        return 0;
    }
    rep(i,1,n+1){
        for (int j : adj[i]) if (j != par[i]) out[i].pb(j);
        sort(all(out[i]),cmp);
    }
    vector<int> ve;
    queue<int> q;
    q.push(1);
    while (!q.empty()){
        int v = q.front();
        ve.pb(v);
        q.pop();
        for (int u : out[v]) q.push(u);
    }
    rep(i,0,n){
        if (ve[i] != a[i]){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}
#include <bits/stdc++.h>
#pragma GCC target("sse,sse2")
#pragma GCC optimize("unroll-loops,O3")
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
constexpr int N = 1e6+20,mod = 1e9+7,inf = 1e9+10,lg = 18;
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
        k /= 2;
    } 
    return z; 
}
vector<int> ve,adj[N];
int pr[N];
void dfs(int v,int p){
    if (p) pr[v] = min(v,pr[p]);
    else pr[v] = v;
    for (int u : adj[v]){
        if (u == p) continue;
        dfs(u,v);
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n >> q;
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    q--;
    int t,x;
    cin >> t >> x;
    x = x%n+1;
    dfs(x,0);
    int last = 0,ans = x;
    while (q--){
        cin >> t >> x;
        x = (x+last)%n+1;
        if (t == 1) ans = min(ans,pr[x]);
        else{
            last = min(pr[x],ans);
            cout << last << endl;
        }
    }
    return 0;
}
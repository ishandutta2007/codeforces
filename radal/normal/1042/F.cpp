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
constexpr int N = 1e6+20,mod = 1e9+7,inf = 1e9+10,sq = 340;
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
multiset<int> st[N];
vector<int> adj[N];
int n,k;
void dfs(int v,int p,int d = 0){
    if (adj[v].size() == 1){
        st[v].insert(d);
        return;
    }
    for (int u : adj[v]){
        if (u == p) continue;
        dfs(u,v,d+1);
        if (st[v].size() < st[u].size()) swap(st[v],st[u]);
        while (!st[u].empty()){
            int x = (*st[u].rbegin());
            st[u].erase(st[u].find(x));
            auto it = st[v].upper_bound(2*d+k-x);
            if (it == st[v].begin()){
                st[v].insert(x);
                continue;
            }
            it--; 
            st[v].erase(it);
            st[v].insert(max(x,*it));
        }
        st[u].~multiset();
    }
    adj[v].clear();
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int r = -1;
    rep(i,1,n+1) adj[i].shrink_to_fit();
    repr(i,n,1){
        if (adj[i].size() > 1){
            r = i;
            break;
        }
    }
    dfs(r,0);
    cout << st[r].size();
    return 0;
}
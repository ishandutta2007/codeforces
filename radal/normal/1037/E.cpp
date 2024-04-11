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
vector<pll> ve;
set<int> adj[N];
int deg[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    rep(i,0,m){
        int x,y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        ve.pb({x,y});
        deg[x]++;
        deg[y]++;
    }
    set<pll> st;
    rep(i,1,n+1) st.insert({deg[i],i});
    while (!st.empty()){
        pll p = (*st.begin());
        if (p.X >= k) break;
        st.erase(p);
        int v = p.Y;
        for (int u : adj[v]){
            if (deg[u] >= k){
                st.erase({deg[u],u});
                deg[u]--;
                st.insert({deg[u],u});
            }
        }
    }
    vector<int> ans;
    repr(i,m-1,0){
        ans.pb(st.size());
        int x = ve[i].X,y = ve[i].Y;
        if (min(deg[y],deg[x]) >= k){
            st.erase({deg[x],x});
            st.erase({deg[y],y});
            deg[x]--;
            deg[y]--;
            st.insert({deg[x],x});
            st.insert({deg[y],y});
            adj[x].erase(y);
            adj[y].erase(x);
            while (!st.empty()){
                pll p = (*st.begin());
                if (p.X >= k) break;
                st.erase(p);
                int v = p.Y;
                for (int u : adj[v]){
                    if (deg[u] >= k){
                        st.erase({deg[u],u});
                        deg[u]--;
                        st.insert({deg[u],u});
                    }
                }
            }
        }
    }
    reverse(all(ans));
    for (int i : ans) cout << i << endl;
    return 0;
}
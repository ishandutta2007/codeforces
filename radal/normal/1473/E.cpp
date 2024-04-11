#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
typedef long double ld;
typedef pair<int,int> pll;
const long long int N = 2e5+20,mod = 1e9+7,inf = 1e9,sq = 400;
inline int mkay(int a,ll b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
ll d[N][4];
int n,m;
vector<pll> adj[N];
inline void dij(){
    set<pair<ll,pll> > st;
    st.insert({0,{1,0}});
    while (!st.empty()){
        auto p = *(st.begin());
        st.erase(st.begin());
        int v = p.Y.X,i = p.Y.Y;
        for(pll u : adj[v]){
            if (d[u.X][i] > d[v][i]+u.Y){
                st.erase({d[u.X][i],{u.X,i}});
                d[u.X][i] = u.Y+d[v][i];
                st.insert({d[u.X][i],{u.X,i}});
            }
            if ((i&1) == 0 && d[u.X][i+1] > d[v][i]+2*u.Y){
                st.erase({d[u.X][i+1],{u.X,i+1}});
                d[u.X][i+1] = d[v][i]+2*u.Y;
                st.insert({d[u.X][i+1],{u.X,i+1}});
            }
            if ((i&2) == 0 && d[u.X][i+2] > d[v][i]){
                st.erase({d[u.X][i+2],{u.X,i+2}});
                d[u.X][i+2] = d[v][i];
                st.insert({d[u.X][i+2],{u.X,i+2}});
            }
            if (!i && d[u.X][3] > d[v][0]+u.Y){
                st.erase({d[u.X][3],{u.X,3}});
                d[u.X][3] = d[v][0] + u.Y;
                st.insert({d[u.X][3],{u.X,3}});
            }
        }
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    memset(d,63,sizeof d);
    cin >> n >> m;
    d[1][0] = 0;
    rep(i,0,m){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    dij();
    rep(i,2,n+1) cout << d[i][3] << ' ';

}
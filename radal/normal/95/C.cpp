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
typedef pair<ll,ll> pll;
const long long int N=1e3+20,mod = 1e9+7,inf=3e8,maxk = 1e5+20;
const long double eps = 0.0001;
int n,m;
vector <pll> adj[N],adj2[N];
ll c[N],t[N],d[N];
int x,y;
void dij1(int v){
    memset(d,63,sizeof d);
    set<pll> st;
    st.insert({0,v});
    d[v] = 0;
    while (!st.empty()){
        pll p = *(st.begin());
        st.erase(st.begin());
        for (pll u : adj[p.Y]){
            if (d[u.X] > p.X+u.Y){
                st.erase({d[u.X],u.X});
                d[u.X] = p.X+u.Y;
                st.insert({d[u.X],u.X});
            }
        }
    }
}
void dij2(int v){
    memset(d,63,sizeof d);
    set<pll> st;
    st.insert({0,v});
    d[v] = 0;
    while (!st.empty()){
        pll p = *(st.begin());
        st.erase(st.begin());
        for (pll u : adj2[p.Y]){
            if (d[u.X] > p.X+u.Y){
                st.erase({d[u.X],u.X});
                d[u.X] = p.X+u.Y;
                st.insert({d[u.X],u.X});
            }
        }
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m >> x >> y;
    rep(i,0,m){
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    rep(i,1,n+1){
        cin >> t[i] >> c[i];
        dij1(i);
        rep(j,1,n+1) if (i != j && d[j] <= t[i]) adj2[i].pb({j,c[i]});
    }
    dij2(x);
    if (d[y] > 1e16) cout << -1;
    else cout << d[y];
    return 0;

}
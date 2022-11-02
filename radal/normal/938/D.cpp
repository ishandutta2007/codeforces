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
const long long int N=2e5+20,mod = 1e9+7,inf=8e18,maxk = 1e5+20;
const long double eps = 0.0001;
int n,m;
ll d[N];
vector<pll> adj[N];
void dij(){
    set<pll> st;
    rep(i,1,n+1) st.insert({d[i],i});
    while(!st.empty()){
        pll p = *(st.begin());
        st.erase(st.begin());
        int v = p.Y;
        for (pll u : adj[v]){
            if (d[u.X] > d[v]+u.Y){
                st.erase({d[u.X],u.X});
                d[u.X] = d[v]+u.Y;
                st.insert({d[u.X],u.X});
            }
        }
    }
    return;
}
int main(){
    cin >> n >> m;
    rep(i,0,m){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        adj[u].pb({v,2*w});
        adj[v].pb({u,2*w});
    }
    rep(i,1,n+1) cin >> d[i];
    dij();
    rep(i,1,n+1) cout << d[i] << ' ';
    return 0;
}
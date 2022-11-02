#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=1e4+20,mod = 1e9,inf=4e18,maxm = 2e5+20;
const long double eps = 0.0001;
int n,m,k,s1,s2,f;
ll ans[N],d[N];
vector<pair<pll,int> > adj[N];
int vis[N];
void dij(){
    set<pll> st;
    st.insert({0,s1});
    st.insert({0,s2});
    vis[s1] = 1;
    vis[s2] = 2;
    d[s1] = 0;
    d[s2] = 0;
    while (!st.empty()){
        pll p = *(st.begin());
        st.erase(st.begin());
        int v = p.Y;
        for (auto u : adj[v]){
            ll w;
            if(u.Y) w = ans[u.Y];
            else w = u.X.Y;
            if (d[u.X.X] > d[v]+w){
                st.erase({d[u.X.X],u.X.X});
                d[u.X.X] = d[v]+w;
                vis[u.X.X] = vis[v];
                st.insert({d[u.X.X],u.X.X});
            }
        }
    }
}
void dij2 (int s){
    set<pll> st;
    st.insert({0,s});
    d[s] = 0;
    while (!st.empty()){
        pll p = *(st.begin());
        st.erase(st.begin());
        int v = p.Y;
        for (auto u : adj[v]){
            ll w;
            if(u.Y) w = ans[u.Y];
            else w = u.X.Y;
            if (d[u.X.X] > d[v]+w){
                st.erase({d[u.X.X],u.X.X});
                d[u.X.X] = d[v]+w;
                st.insert({d[u.X.X],u.X.X});
            }
        }
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    cin >> n >> m >> k >> s1 >> s2 >> f;
    rep(i,0,m){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({{v,w},0});
    }
    rep(i,1,k+1){
        int u,v,l,r;
        cin >> u >> v >> l >> r;
        adj[u].pb({{v,l},i});
        ans[i] = r;
    }
    rep(i,0,k){
        memset(d,63,sizeof d);
        dij();
        rep(i,1,n+1) if (vis[i] == 1) for (auto u : adj[i]) if (u.Y) ans[u.Y] = u.X.Y;
    }
    memset(d,63,sizeof d);
    ll a;
    dij2(s1);
    a = d[f];
    memset(d,63,sizeof d);
    dij2(s2);
    if (d[f] < a){
        cout << "LOSE" << endl;
        return 0;
    }
    if (d[f] == a) cout << "DRAW" << endl;
    else cout << "WIN" << endl;
    rep(i,1,k+1){
        cout << ans[i] << ' ';
    }
    return 0;
}
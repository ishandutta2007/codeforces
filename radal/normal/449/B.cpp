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
const long long int N=1e5+20,mod = 1e9+7,inf=3e8;
const long double eps = 0.0001;
vector<pair<pll,bool>> adj[N];
ll d[N];
int n,m,k;
pair<pair<pll,ll>,bool> edge[10*N];
vector<pair<pll,pll>> adj2[N];
ll cnt;
bool vis[N];
void dij(){
    set<pll> st;
    st.insert({0,1});
    d[1] = 0;
    while (!st.empty()){
        pll p = *(st.begin());
        st.erase(st.begin());
        ll v = p.Y;
        for (auto u : adj[v]){
            if (d[u.X.X] > d[v]+u.X.Y){
                st.erase({d[u.X.X],u.X.X});
                d[u.X.X] = d[v]+u.X.Y;
                st.insert({d[u.X.X],u.X.X});
            }
        }
    }
    return;
}
void dfs(int v){
    vis[v] = 1;
    for (auto u : adj2[v]){
        if (!vis[u.Y.X]){
            if (u.X.X) cnt++;
            dfs(u.Y.X);
        }
    }
    return;
}
int main(){
    memset(d,63,sizeof d);
    cin >> n >> m >> k;
    rep(i,0,m){
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({{v,w},0});
        adj[v].pb({{u,w},0});
        edge[i] = {{{u,v},w},0};
    }
    rep(i,0,k){
        ll v, w;
        cin >> v >> w;
        adj[1].pb({{v,w},1});
        edge[i+m] = {{{1,v},w},1};
    }
    dij();
    rep(i,0,m+k){
        if (edge[i].Y){
            ll v = edge[i].X.X.Y;
            if (d[v] == edge[i].X.Y) adj2[1].pb({{1,d[v]},{v,edge[i].X.Y}});
        }
        else{
            ll v = edge[i].X.X.Y;
            ll u = edge[i].X.X.X;
            ll w = edge[i].X.Y;
            if (d[v]+w == d[u]){
                adj2[v].pb({{0,d[u]},{u,w}});
            //    adj2[u].pb({{0,d[v]},{v,w}});
            }
            if (d[u]+w == d[v]){
                adj2[u].pb({{0,d[v]},{v,w}});
            }
        }
    }
    rep(i,1,n+1) sort(adj2[i].begin(),adj2[i].end());
    dfs(1);
    cout << k - cnt << endl;
    return 0;
}
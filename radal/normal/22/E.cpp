#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e5+10,mod = 1e9+7,inf=1e9,dlt = 12251;
int poww(int n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return (((r*r)%mod)*poww(n,k&1))%mod;
}
vector<int> out[N],in[N],comp[N],ve[N];
int vis[N];
int din[N],j[N];
void dfs(int v,int c){
    vis[v] = 1;
    comp[c].pb(v);
    for(int u : in[v]) if (!vis[u]) dfs(u,c);
    for (int u : out[v]) if (!vis[u]) dfs(u,c);
}
void dfs2(int v,int c){
    vis[v] =1;
    for (int u: out[v]){
        if (vis[u] == 2) continue;
        if (vis[u] == 1) j[c] = u;
        else dfs2(u,c);
    }
    vis[v] = 2;
}
int main(){
    int n;
    cin >> n;
    rep(i,1,n+1){
        int x;
        cin >> x;
        out[i].pb(x);
        in[x].pb(i);
        din[x]++;
    }
    int c = 0;
    rep(i,1,n+1){
        if (!vis[i]){
            c++;
            dfs(i,c);
        }
    }
    memset(vis,0,sizeof vis);
    rep(i,1,c+1) dfs2(comp[i][0],i);
    vector<pll> ans;
    if (c == 1){
        rep(i,1,n+1) if (!din[i]) ans.pb({j[1],i});
        cout << ans.size() << endl;
        for (pll u : ans) cout << u.X << ' ' << u.Y << endl;
        return 0;
    }
    rep(i,1,c+1) for (int u : comp[i]) if (!din[u]) ve[i].pb(u);
    rep(i,1,c+1){
        if (ve[i].empty()){
            if (i != c) ans.pb({j[i+1],comp[i][0]});
            else ans.pb({j[1],comp[i][0]});
            continue;
        }
        if (i != c) ans.pb({j[i+1],ve[i][0]});
        else ans.pb({j[1],ve[i][0]});
        int sz = ve[i].size();
        rep(k,1,sz) ans.pb({j[i],ve[i][k]});
    }
    cout << ans.size() << endl;
    for(pll u : ans) cout << u.X << ' ' << u.Y << endl;
}
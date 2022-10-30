#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
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
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=2e5+30,mod = 1e9+7,inf=1e9;
ll dpd[N],par[N],dpu[N];
vector <int> adj[N];

void dfs(int v,int p){
    par[v] = p;
    ll z = 1;
    for (auto u : adj[v]){
        if (u != p){
            dfs(u,v);
            z *= (dpd[u]+1);
            z %= mod;
        }
    }
    dpd[v] = z;
}
void dfs2(int v){
    int s = adj[v].size();
    ll pre[s],suf[s];
    pre[0] = 1;
    suf[s-1] = 1;
    rep(i,1,s){
        if (adj[v][i] == par[v]){
            pre[i] = pre[i-1];
            suf[s-i-1] = suf[s-i];
            continue;
        }
        int u = adj[v][i-1],w = adj[v][s-i];
        if (u != par[v]) pre[i] = pre[i-1]*(dpd[u]+1);
        else pre[i] = pre[i-1];
        if (w != par[v]) suf[s-i-1] = suf[s-i]*(dpd[w]+1);
        else suf[s-i-1] = suf[s-i];
        suf[s-i-1] %= mod;
        pre[i] %= mod;
    }
    rep(i,0,s){
        int u = adj[v][i];
        if (u == par[v]) continue;
        dpu[u] = suf[i]*pre[i]%mod*dpu[v]+1;
        dpu[u] %= mod;
    }
    for (int u : adj[v]){
        if (u != par[v]){
            dfs2(u);
        }
    }
}
int main(){
    int n;
    cin >> n;
    dpu[1] = 1;
    rep (i,2,n+1){
        dpu[i] = 1;
        int u;
        cin >> u;
        adj[u].pb(i);
        adj[i].pb(u);
    }
    dfs(1,-1);
    dfs2(1);
    ll ans;
    rep(i,1,n+1){
     //   debug(i); debug(dpu[i]);
        ans = (dpd[i])*(dpu[i]);
        ans %= mod;
        cout << ans << ' ';
    }
    cout << endl;
    rep (i,1,n+1){
       // dfs(i,-1);
      //  cout << dpd[i] << ' ';
    }
    return 0;
}
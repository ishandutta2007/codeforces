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
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pll;
const long long int N=1e5+30,mod = 1e9+7,inf=1e9;
int n,m,d;
int dpd[N],dpu[N],pre[N],suf[N];
set<int> p;
vector <int> adj[N];
void dfs(int v,int par){
    for (int u : adj[v]){
        if (u != par){
            dfs(u,v);
            if (dpd[u] > 0) dpd[v] = max(dpd[v],dpd[u]+1);
            else if (p.find(u) != p.end()) {
                dpd[v] = max(dpd[v],1);
            }
        }
    }
}
void dfs2(int v,int par){
    if (par > -1){
        if (dpu[par] != 0) dpu[v] = max(dpu[v],dpu[par]+1);
        else if (p.find(par) != p.end()) dpu[v] = max(dpu[v],1);
    }
    int sz = adj[v].size();
    rep(i,0,sz){
        pre[i] = -2;
        int u = adj[v][i];
        if (u != par){
            if (i) pre[i] = max(pre[i],pre[i-1]);
            if(dpd[u]){
                if (i && !(i == 1 && adj[v][0] == par)) pre[i] = max(dpd[u],pre[i-1]);
                else pre[i] = dpd[u];
            }
            else if (p.find(u) != p.end()) pre[i] = max(0,pre[i]);
        }
        else{
            if (i) pre[i] = pre[i-1];
        }
    }
    repr(i,sz-1,0){
        suf[i] = -2;
        int u = adj[v][i];
        if (u != par){
            if (i < sz-1) suf[i] = max(suf[i],suf[i+1]);
            if (dpd[u]){
                if (i != sz-1 && !(i == sz-2 && adj[v][i+1] == par)){
                    suf[i] = max(dpd[u],suf[i+1]);
                }
                else{
                    suf[i] = dpd[u];
                }
            }
            else if (p.find(u) != p.end()){
                suf[i] = max(0,suf[i]);
            }
            if (i < sz-1){
                dpu[u] = max(dpu[u],suf[i+1]+2);
            }
            if (i){
                dpu[u] = max(dpu[u],pre[i-1]+2);
            }
        }
        else{
            if (i < sz-1) suf[i] = suf[i+1];
        }
    }
    for(int u : adj[v]) if (u != par) dfs2(u,v);
}
int main(){
    cin >> n >> m >> d;
    rep(i,0,m){
        int x;
        cin >> x;
        p.insert(x);
    }
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);
    dfs2(1,-1);
    int cnt = 0;
    rep(i,1,n+1){
        if (max(dpd[i],dpu[i]) <= d) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
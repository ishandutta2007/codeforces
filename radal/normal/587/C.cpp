#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
typedef vector<int> :: iterator  vit;
const long long int N=1e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k%2))%mod;
}
int h[N];
int par[N][20];
vector<int> adj[N],c[N];
vector<int> pa[20][N],st;
inline void mg(vit it1,vit it2,vit it3, vit it4, vit it5){
    int i =0;
    while (true){
        if (i >= 10 || (it1 == it2 && it3 == it4)) return;
        i++;
        if(it1  == it2 || (it3 != it4 && *it3 < *it1)){
            *it5 = *it3;
            it3++;
            it5++;
        }
        else{
            *it5 = *it1;
            it1++;
            it5++;
        }
    }
}
void dfs(int v,int p){
    par[v][0] = p;
    for (int u : adj[v]){
        if (u == p) continue;
        h[u] = h[v]+1;
        dfs(u,v);
    }
    int sz = 0;
    if (p == -1) return;
    for (int u : c[p]){
        if (sz == 10) break;
        pa[0][v].pb(u);
        sz++;
    }
}
inline int getpar(int u,int k){
    if (h[u] < k) return -1;
    repr(i,16,0){
        if (k >= (1 << i)){
            u = par[u][i];
            k -= (1 << i);
        }
    }
    return u;
}
inline int lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    repr(i,16,0){
        if (h[v]-h[u] < (1 << i)) continue;
        v = par[v][i];
    }
    if (v == u) return v;
    repr(i,16,0){
        if (par[u][i] == par[v][i]) continue;
        u = par[u][i];
        v =  par[v][i];
    }
    return par[v][0];
}
inline void rmq(int u,int v,int k){
    int sz = c[u].size()+st.size();
    vector<int> ve;
    ve.resize(min(10,sz));
    mg(c[u].begin(),c[u].end(),st.begin(),st.end(),ve.begin());
    st = ve;
    sz = st.size();
    repr(i,16,0){
        if (h[u]-h[v] < (1 << i)) continue;
        sz += pa[i][u].size();
        ve.clear();
        ve.resize(min(10,sz));
        mg(st.begin(),st.end(),pa[i][u].begin(),pa[i][u].end(),ve.begin());
        st = ve;
        u = par[u][i];
    }
    return;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,q,x,u,v;
    cin >> n >> m >> q;
    rep(i,0,n-1){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep(i,1,m+1){
        cin >> x;
        c[x].pb(i);
    }
    dfs(1,-1);
    rep(j,1,17){
        rep(i,1,n+1){
            if (h[i] < (1 << j)) continue;
            par[i][j] = par[par[i][j-1]][j-1];
            int p = par[i][j-1];
            int sz = pa[j-1][i].size()+pa[j-1][p].size();
            pa[j][i].resize(min(10,sz));
            mg(pa[j-1][i].begin(),pa[j-1][i].end(),pa[j-1][p].begin(),pa[j-1][p].end(),pa[j][i].begin());
            sz = pa[j][i].size();
            if (sz > 10){
                cout << sz;
                return 0;
            }
            while (sz > 10){
                pa[j][i].pop_back();
                sz--;
            }
        }
    }
    rep(i,0,q){
        int a;
        cin >> u >> v >> a;
        int w = lca(u,v);
        rmq(u,w,a);
        if (w != v) rmq(v,getpar(v,h[v]-h[w]-1),a);
        cout << min(a,int(st.size())) << ' ';
        for (int u : st){
            a--;
            cout << u << ' ';
            if (!a) break;
        }
        cout << endl;
        st.clear();
    }
}
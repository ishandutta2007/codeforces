
// Problem : G. Directing Edges
// Contest : Codeforces - Educational Codeforces Round 92 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1389/G
// Memory Limit : 512 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define X first
#define Y second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const int maxn = 3e5 + 17;
int n, m, k, edge[maxn], comp[maxn], h[maxn], gp, vc[maxn], cntSp[maxn], w[maxn], sz[maxn], spe[maxn];
ll c[maxn], res[maxn];
bool bl[maxn], seen[maxn], is[maxn];
vector<int> g[maxn];
struct E{
    int u, w;
    bool haveSp;
};
vector<E> adj[maxn];
pii e[maxn];
int hi(int v = 0, int p = -1){
    int ret = h[v];
    seen[v] = 1;
    for(auto i : g[v]){
        int u = edge[i] ^ v;
        if(!seen[u]){
            h[u] = h[v] + 1;
            int t = hi(u, v);
            if(t == h[u])  bl[i] = 1;
            ret = min(ret, t);
        }
        else if(u != p)
            ret = min(ret, h[u]);
    }
    return ret;
}
void hello(int v){
    c[ comp[v] = gp ] += vc[v];
    for(auto i : g[v]){
        int u = edge[i] ^ v;
        if(!bl[i] && comp[u] == -1)
            hello(u);
    }
}
ll dfs_res(int v, int p){
    if(bl[v])
        return res[v];
    ll gain = c[v];
    for(auto [u, w, haveSp] : adj[v])
        if(u != p){
            ll b = dfs_res(u, v) - haveSp * w;
            gain += max(0ll, b);
        }
    return gain;
}
void prep(int v,int p = -1){
    sz[v] = 1;
    for(auto [u, _, __] : adj[v])
        if(u != p && !bl[u]){
            prep(u,v);
            sz[v]+=sz[u];
        }
}
void dfs(int v=0){
    prep(v);
    int s=v;
    int p=-1;
    bool br=1;
    while(!(br^=1))
        for(auto [u, _, __] : adj[v])
            if(!bl[u] && u != p && sz[u] > sz[s] / 2){
                br=1,p=v,v=u;
                break;
            }
    res[v] = ::c[v];
    vector<ll> ress;
    for(auto [u, w, haveSp] : adj[v]){
        ress.push_back(max(0ll, dfs_res(u, v) - haveSp * w));
        res[v] += ress.back();
    }
    bl[v] = true;
    for(int i = 0; i < adj[v].size(); i++)
        if(!bl[adj[v][i].u]){
            res[v] -= ress[i];
            dfs(adj[v][i].u);
            res[v] += ress[i];
        }
}
void build_tree(){
    for(int i = 0; i < m; i++)
        if(bl[i]){
            adj[ comp[ e[i].X ] ].push_back({comp[ e[i].Y ], w[i], 0});
            adj[ comp[ e[i].Y ] ].push_back({comp[ e[i].X ], w[i], 0});
        }
}
void dfs_cntSp(int v = 0, int p = -1){
    cntSp[v] = spe[v];
    for(auto &[u, _, haveSp] : adj[v])
        if(u != p){
            dfs_cntSp(u, v);
            if(cntSp[u] && cntSp[u] != k)
                haveSp = true;
            cntSp[v] += cntSp[u];
        }
    for(auto &[u, _, haveSp] : adj[v])
        if(u == p)
            haveSp = cntSp[v] < k && cntSp[v];
}
int main(){
	fio;
    cin >> n >> m >> k;
    vector<int> specials(k);
    for(auto &v : specials)
        cin >> v, v--;
    for(int i = 0; i < n; i++)
        cin >> vc[i];
    for(int i = 0; i < m; i++)
        cin >> w[i];
    for(int i = 0, v, u; i < m; i++){
        cin >> v >> u, v--, u--;
        edge[i] = v ^ u, e[i] = {v, u};
        g[v].push_back(i), g[u].push_back(i);
    }
    hi();
    memset(comp, -1, sizeof comp);
    for(int i = 0; i < n; i++)
        if(comp[i] == -1){
            hello(i);
            gp++;
        }
    for(auto &v : specials)
        spe[comp[v]]++;
    build_tree();
    fill(bl, bl + n, 0);
    dfs_cntSp();
    dfs();
    for(int i = 0; i < n; i++)
        cout << res[comp[i]] << ' ';
    cout << '\n';
}
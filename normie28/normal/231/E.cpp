
// Problem : E. Cactus
// Contest : Codeforces - Codeforces Round #143 (Div. 2)
// URL : https://codeforces.com/problemset/problem/231/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
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
#define fi first
#define se second
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
const int mod = 1e9+7;
vector<int> g[100005], gt[100005], gb[100005], g2[100005];
bool vis[100005];
int par2[100005];
int X[100005];
int p[100005], sz[100005];
int root(int a){
    return p[a] == a?a:(p[a]=root(p[a]));
}
void merge(int a, int b){
    a = root(a), b = root(b);
    if(a != b){
        p[a] = b;
        sz[b] += sz[a];
    }
}
int W[100005];
int par[17][100005], depth[100005];
void dfs(int u, int p, int d = 0){
    vis[u] = 1;
    par2[u] = p;
    depth[u] = d;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v == p) continue;
        if(vis[v]){
            gb[u].emplace_back(v);
            continue;
        }
        gt[u].emplace_back(v);
        dfs(v, u, d+1);
    }
}
int LCA(int a, int b){
    if(depth[b] > depth[a]) swap(a, b);
    int diff = depth[a] - depth[b];
    for(int i=16;i>=0;i--){
        if((diff>>i)&1) a = par[i][a];
    }
    if(a == b) return a;
    for(int i=16;i>=0;i--){
        if(par[i][a] != par[i][b]) a = par[i][a], b = par[i][b];
    }
    return par[0][a];
}
 
void dfs2(int u, int p, int d = 0){
    W[u] = W[p];
    if(sz[u] > 1) W[u]++;
    depth[u] = d;
    par[0][u] = p;
    for(int i=0;i<g2[u].size();i++){
        int v = g2[u][i];
        if(v == p) continue;
        dfs2(v, u, d+1);
    }
}
int main(){
	fio;
    int n, m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i] = i, sz[i] = 1;
    for(int i=1;i<=m;i++){
        int a, b;
        cin>>a>>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(1, 0);
    for(int u=1;u<=n;u++){
        for(int i=0;i<gb[u].size();i++){
            int v = gb[u][i];
            if(depth[u] < depth[v]) continue;
            int u2 = u;
            while(u2 != v){
                merge(u2, par2[u2]);
                u2 = par2[u2];
            }
        }
    }
    for(int u=1;u<=n;u++){
        for(int i=0;i<g[u].size();i++){
            int v = g[u][i];
            if(root(v) == root(u)) continue;
            g2[root(u)].emplace_back(root(v));
        }
    }
    dfs2(root(1), 0);
    for(int j=1;j<17;j++) for(int i=1;i<=n;i++) if(par[j-1][i] != 0) par[j][i] = par[j-1][par[j-1][i]];
    int q;
    cin>>q;
    X[0] = 1;
    for(int i=1;i<=n;i++) X[i] = X[i-1]*2%mod;
    for(int i=1;i<=q;i++){
        int a, b;
        cin>>a>>b;
        a = root(a), b = root(b);
        int c = LCA(a, b);
        int cnt = W[a] + W[b] - 2*W[c];
        if(sz[c] > 1) cnt++;
        cout<<X[cnt]<<endl;
    }
}

// Problem : D. Little Elephant and Broken Sorting
// Contest : Codeforces - Codeforces Round #157 (Div. 1)
// URL : https://codeforces.com/problemset/problem/258/D
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

const int maxn = 1e5 + 10, M = 20;
int par[maxn][M], d[maxn], n, k, st[maxn], rev[maxn], ti;
vector<int>adj[maxn];
void dfs(int v=0,int p=0){
    par[v][0] = p;
    st[v] = ti++;
    rev[st[v]] = v;
    for(int i=1; i<M; i++)
        par[v][i] = par[par[v][i-1]][i-1];
    for(int u : adj[v]){
        if(u == p) continue;
        d[u] = d[v] + 1;
        dfs(u, v);
    }
}
int getH(int v,int k){
    for(int i=0; i<M; i++)
        if(k & (1 << i))
            v = par[v][i];
    return v;
}
int lca(int u,int v){
    if(d[v] < d[u]) swap(u, v);
    v = getH(v, d[v] - d[u]);
    if(u == v) return v;
    for(int i=M; i--;){
        if(par[v][i] != par[u][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[v][0];
}
int dist(int u,int v){
    u = rev[u], v = rev[v];
    return d[u] + d[v] - 2*d[lca(u, v)];
}
set<int>s;
int w;
int bef(int v){
    if(!s.size()) return v;
    if(v <= *(s.begin())) return *(s.rbegin());
    auto it = s.lower_bound(v);
    return *(--it);
}
int aft(int v){
    if(!s.size()) return v;
    if(v >= *(s.rbegin())) return *(s.begin());
    return *(s.upper_bound(v));
}
void add(int v,int val=1){
    v = st[v];
    if(val == -1);
        s.erase(v);
    w += dist(bef(v), v) * val;
    w += dist(aft(v), v) * val;
    w -= dist(aft(v), bef(aft(v))) * val;
    if(val == 1)
        s.insert(v);
}
bool isval(int x){
    for(int i=0; i<x; i++)
        add(i);
    if(w <= k) return 1;
    for(int i=x; i<n; i++){
        add(i), add(i-x, -1);
        if(w <= k) return 1;
    }
    return 0;
}
int main(){
    fio;
    cin >> n >> k;
    k = (k-1) * 2;
    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    int l=0, r = n+1;
    while(r - l > 1){
        int mid = (r+l) / 2;
        s.clear(), w = 0;
        if(isval(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
}
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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "graph.inp"
#define FILE_OUT "graph.out"
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
#define pi 3.1415926535897
typedef long long ll;
//------------xc xch normie tm muoi tm phan tram no----------//
const int N = 2e5;
int n;
vector<int>g[N];
int v[N];
const ll is_query = 1ll << 62;
struct line{
    ll k, b;
    mutable function<const line *()> succ;
    bool operator<(const line & a) const {
        if (a.b != is_query)  return k < a.k;
        auto y = succ();
        if (!y) return 0;
        return a.k * k + b < a.k * y->k + y->b;
    }
};
struct HullDynamic:public multiset<line> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end())
                return 0;
            return z->k >= y->k && z->b >= y->b;
        }
        auto x = prev(y);
        if (z == end()) {
            return x->k == y->k && x->b == y->b;
        }
        return (x->b - z->b) * (y->k - x->k) <= (x->b - y->b) * (z ->k - x->k);
    }
    void insert_line(ll k, ll b) {
        auto y = insert({k, b});
        y -> succ = [=]() {return next(y) == end()? 0: &*next(y);};
        if (bad(y)) {
            erase(y);
            return;
        }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto y = *lower_bound((line){x, is_query});
        return y.k * x + y.b;
    }
}H;
vector<int>d, d2;
bool bz[N];
int sz[N], mxsz[N];
int len[N];
ll res = 0;
ll w[N], all[N];
int root(int x) {
    function<void(int, int)>dfs = [&](int x, int fa){
        sz[x] = 1;
        mxsz[x] = 0;
        d.push_back(x);
        for (auto u:g[x])
            if (u != fa && !bz[u])
                dfs(u, x), sz[x] += sz[u], mxsz[x] = max(mxsz[x], sz[u]);
    };
    d.clear();
    dfs(x, 0);
    for (auto u:d)
        if (max(mxsz[u], (int)d.size() - sz[u]) < max(mxsz[x], (int)d.size() - sz[x])) x = u;
    return x;
}
void divide(int x) {
    x = root(x);
    function<void(int, int)> dfs = [&] (int x, int fa) {
        d2.push_back(x);
        for (auto u:g[x])
            if (u != fa && !bz[u]) {
                len[u] = len[x] + 1;
                w[u] = w[x] + (all[u] = all[x] + v[u]);
                dfs(u, x);
            }
    };
    function<void(int, int)> dfs1 = [&] (int x, int fa) {
        for (auto u:g[x])
            if (u != fa && !bz[u]) {
                len[u] = len[x] + 1;
                w[u] = w[x] + 1ll * len[u] * v[u];
                all[u] = all[x] + v[u];
                dfs1(u, x);
            }
    };
    function<void(int)> work = [&] (int x) {
        H.clear();
        for (auto u:g[x])
            if (!bz[u]) {
                d2.clear();
                len[u] = 2, all[u] = v[u] + v[x];
                w[u] = all[u] + v[x];
                dfs(u, x);
                for (auto v:d2) {
                    if (!H.empty())
                        res = max(res, H.eval(len[v]) + w[v]);
                    res = max(res, w[v]);
                }
                len[u] = 1, w[u] = all[u] = v[u];
                dfs1(u, x);
                ll tmp = v[x];
                for (auto v:d2) {
                    H.insert_line(all[v], w[v]);
                    res = max(res, w[v] + all[v] + tmp);
                }
            }
    };
    work(x);
    reverse(g[x].begin(), g[x].end());
    work(x);
    bz[x] = 1;
    for (auto u:g[x])
        if (!bz[u])
            divide(u);
}
int main() {
    fio;
    cin>>n;
    for (int i = 1; i < n; i ++) {
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i= 1; i <= n; i ++)
        cin>>v[i];
    divide(1);
    cout<<res;
}
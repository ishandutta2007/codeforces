// Problem: C. Tournament
// Contest: Codeforces - Codeforces Round #443 (Div. 1)
// URL: https://codeforces.com/problemset/problem/878/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
	Normie's Template v2.1
	Changes:
	Added vectorization optimizations.
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;

//---------END-------//
const int N = 2e5;
int deep[N], sz[N], mxsz[N], d[N];
vector<int>g[N];
bool bz[N];
int fsz[N][20], fson[N][20], c[20], w[N][20], v[N], all[N], allsz[N];
int fa[N];
int n, q;
int ff[20][N * 4], l[N][20], r[N][20], dfn[20];
const int mod = 998244353;
int add(int x, int y) {
    x+= y;
    return x >= mod ?x - mod : x;
}
int sub(int x, int y) {
    x -= y;
    return x < 0 ? x +mod : x;
}
int mul(int x, int y){
    return 1ll * x * y % mod;
}
int calc(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x), y >>= 1;
    }
    return z;
}
 
void dfs1(int x, int fa){
    sz[x] = 1;
    d[++d[0]] = x;
    mxsz[x] = 0;
    for (auto u:g[x])
        if (!bz[u] && u != fa) {
            dfs1(u, x);
            sz[x] += sz[u];
            mxsz[x] = max(mxsz[x], sz[u]);
        }
}
int did(int x) {
    return max(mxsz[x], d[0] - sz[x]);
}
int root(int x) {
    d[0] = 0;
    dfs1(x, 0);
    for (int i = 1; i <= d[0]; i ++)
        if (did(d[i]) < did(x)) x = d[i];
    return x;
}
void dfs(int x, int fa, int cnt) {
    fsz[x][cnt] = 1;
    l[x][cnt] = ++dfn[cnt];
    for (auto u:g[x])
        if (u!=fa && !bz[u]) {
            dfs(u, x, cnt);
            fsz[x][cnt] += fsz[u][cnt];
        }
    r[x][cnt] = dfn[cnt];
}
int dfs(int x, int cnt) {
    x = root(x);
    allsz[x] = d[0];
    deep[x] = cnt;
    for (int i = 0; i < cnt; i ++)
        fson[x][i] = c[i];
    dfs(x, 0, cnt);
    bz[x] = 1;
    for (auto u:g[x])
        if (!bz[u]) {
            c[cnt] = u;
            fa[dfs(u, cnt + 1)] = x;
        }
    return x;
}
void ins(int l, int r ,int s, int *f, int ll, int rr ,int v) {
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr)
    {
        f[s] = add(f[s], v);
        return;
    }
    ins(l, (l + r )/ 2 , s + s, f, ll, rr, v);
    ins((l +r)/ 2 + 1, r, s + s + 1, f, ll, rr, v);
}
int get(int l, int r ,int s, int *f, int ll) {
    int v = 0;
    while (1) {
        v = add(v, f[s]);
        if (l == r)return v;
        if ((l + r) / 2 >= ll) r = (l + r )/ 2, s += s;
        else
            l = (l + r) / 2 + 1, s += s + 1;
    }
}
int main() {
    fio;
    cin>>n>>q;
    for (int i = 1; i < n; i ++)
    {
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    int invn = calc(n, mod - 2);
    while (q --) {
        int sig, x;
        cin>>sig>>x;
        if (sig == 1) {
            int y;
            cin>>y;
            v[x] = add(v[x], mul(y, invn));
            int z = fa[x];
            for (int i = deep[x] - 1; i >= 0; i --) {
                int tmp = mul(invn, mul(fsz[x][i], y));
                w[fson[x][i]][i] = add(w[fson[x][i]][i], tmp);
                all[z] = add(all[z], tmp);
                tmp = mul(invn, mul(sub(allsz[z], fsz[fson[x][i]][i]), y));
                ins(1, dfn[i], 1, ff[i], l[x][i], r[x][i], tmp);
                z = fa[z];
            }
        } else {
            int ans = add(mul(v[x], allsz[x]), all[x]);
            int z = fa[x];
            for (int i = deep[x] - 1; i >= 0; i --, z= fa[z])
                ans = add(add(add(ans, sub(all[z], w[fson[x][i]][i])), get(1, dfn[i], 1, ff[i], l[x][i])), mul(v[z], allsz[z] - fsz[fson[x][i]][i]));
            cout<<ans<<endl;
        }
    }
}
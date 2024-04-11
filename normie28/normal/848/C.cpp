/*
	Normie's Template v2.2
	Changes:
	Added modulo binpow and inverse.
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

// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
//---------END-------//
const int MAXN = 1000000 + 10;
 
int n, m, arr[MAXN], pre[MAXN], nxt[MAXN], lst[MAXN];
ll ans[MAXN];
 
int tot_cnt, q_cnt;
struct node {
    int x, y, val, id, mul;
} q[MAXN], tmp[MAXN];
 
void del(int x) { q[++tot_cnt] = {x, pre[x], pre[x] - x, 0, 0}; }
void add(int x) { q[++tot_cnt] = {x, pre[x], x - pre[x], 0, 0}; }
 
set<int> col[MAXN];
 
struct BIT {
    ll bit[MAXN];
    void _add(int x, int val) { for (; x <= n + 5; x += x & -x) bit[x] += val; }
    ll _query(int x) { ll ret = 0; for (; x; x -= x & -x) ret += bit[x]; return ret; } 
    void add(int x, int val) { _add(x + 2, val); }
    ll query(int x) { return _query(x + 2); } 
} bit;
 
void cdq(int l, int r) {
    if (l == r) return ;
    int mid = (l + r) >> 1;
    cdq(l, mid), cdq(mid + 1, r);
    int i = l, j = mid + 1, cur = l;
    for (; i <= mid && j <= r; ) {
        if (q[i].x <= q[j].x) bit.add(q[i].y, q[i].val), tmp[cur++] = q[i++];
        else ans[q[j].id] += bit.query(q[j].y) * q[j].mul, tmp[cur++] = q[j++];
    }
    for (; i <= mid; ) bit.add(q[i].y, q[i].val), tmp[cur++] = q[i++];
    for (; j <= r; ) ans[q[j].id] += bit.query(q[j].y) * q[j].mul, tmp[cur++] = q[j++];
    for (int k = l; k < i; ++k) bit.add(q[k].y, -q[k].val);
    for (int k = l; k <= r; ++k) q[k] = tmp[k];
}
 
int main() {
	fio;
	cin>>n>>m;
    for (int i = 0; i <= n; ++i) col[i].insert(0), col[i].insert(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i], pre[i] = lst[arr[i]], lst[arr[i]] = i, col[arr[i]].insert(i);
    }
    for (int i = 1; i <= n; ++i) lst[i] = n + 1;
    for (int i = n; i >= 1; --i) nxt[i] = lst[arr[i]], lst[arr[i]] = i;
    for (int i = 1; i <= n; ++i) add(i);
    for (int _ = 1, opt; _ <= m; ++_) {
        cin>>opt;
        if (opt == 1) {
            int p, x;
            cin>>p>>x;
            if (x == arr[p]) continue;
            del(p);
            int _nn = nxt[p], _pp = pre[p];
            if (_nn != n + 1) del(_nn), pre[_nn] = _pp, add(_nn);
            if (_pp != 0) nxt[_pp] = _nn;
            _pp = *--col[x].lower_bound(p);
            _nn = *col[x].lower_bound(p);
            if (_nn != n + 1) del(_nn), pre[_nn] = p, add(_nn);
            if (_pp != 0) nxt[_pp] = p;
            col[arr[p]].erase(p), col[x].insert(p), arr[p] = x, pre[p] = _pp, nxt[p] = _nn;
            add(p);
        } else {
            int l, r;
            cin>>l>>r;
            q[++tot_cnt] = {r, r, 0, ++q_cnt, 1};
            q[++tot_cnt] = {l - 1, l - 1, 0, q_cnt, 1};
            q[++tot_cnt] = {l - 1, r, 0, q_cnt, -1};
            q[++tot_cnt] = {r, l - 1, 0, q_cnt, -1};
        }
    }
    cdq(1, tot_cnt);
    for (int i = 1; i <= q_cnt; ++i) cout<<ans[i]<<endl;
}
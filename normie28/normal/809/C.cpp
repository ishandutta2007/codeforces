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
#define MOD (ll(1000000007))
#define y1 yy1
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
int x1, y1, x2, y2, k, len, a[35], b[35], c[35];
pii(int) dp[35][2][2][2];
int Add(int a, int b)
{
    return a + b >= MOD ? a + b - MOD : a + b;
}
int Minus(int a, int b)
{
    return a < b ? a - b + MOD : a - b;
}
pii(int) operator+(pii(int) a, pii(int) b)
{
    return make_pair(Add(a.first, b.first), Add(a.second, b.second));
}
pii(int) dfs(int now, int f1, int f2, int f3)
{
    if (now == -1)
        return make_pair(1, 0);
    if (~dp[now][f1][f2][f3].first)
        return dp[now][f1][f2][f3];
    pii(int) ret = make_pair(0, 0);
    for (int i = 0; i <= (f1 ? a[now] : 1); i++)
        for (int j = 0; j <= (f2 ? b[now] : 1); j++)
            if ((i ^ j) <= (f3 ? c[now] : 1)) {
                pii(int) tmp = dfs(now - 1, f1 && i == a[now], f2 && j == b[now], f3 && (i ^ j) == c[now]);
                ret = ret + tmp;
                if (i ^ j)
                    ret.second = (ret.second + (1ll << now) * tmp.first) % MOD;
            }
    dp[now][f1][f2][f3] = ret;
    return ret;
}
int calc(int x, int y, int k)
{
    if (x < 0 || y < 0 || k < 0)
        return 0;
    memset(dp, -1, sizeof(dp));
    len = 0;
    while (x || y || k) {
        a[len] = (x & 1);
        b[len] = (y & 1);
        c[len++] = (k & 1);
        x >>= 1;
        y >>= 1;
        k >>= 1;
    }
    pii(int) ret = dfs(len - 1, 1, 1, 1);
    return Add(ret.first, ret.second);
}
int main()
{
	fio;
    int q;
    cin>>q;
    while (q--) {
        cin>>x1>>y1>>x2>>y2>>k;
        cout<<Minus(Add(calc(x2 - 1, y2 - 1, k - 1), calc(x1 - 2, y1 - 2, k - 1)), Add(calc(x1 - 2, y2 - 1, k - 1), calc(x2 - 1, y1 - 2, k - 1)))<<endl;
    }
}
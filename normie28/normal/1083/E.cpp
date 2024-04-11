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
const int MAXN = 1000007;
 
const ll INF = 1e17;
 
struct CHT
{
    using pll = pair<ll, ll>;
    #define a first
    #define b second
 
    vector<pll> vec;
    int ptr = 0;
 
    ll val(int i, ll x) { return vec[i].a * x + vec[i].b; }
    bool bad(pll p0, pll p1, pll p2) { return 1.0 * (p1.a - p0.a) * (p2.b - p0.b) - 1.0 * (p2.a - p0.a) * (p1.b - p0.b) >= 1e-7; } // overflow?
    void add(ll a, ll b)
    {
        for (pll p(a, b); (int) vec.size() > 1 && bad(p, vec[(int) vec.size() - 1], vec[(int) vec.size() - 2]); vec.pop_back());
        vec.emplace_back(a, b);
    }
 
    ll get(ll x)
    {
        for (ptr = min(ptr, (int) vec.size() - 1); ptr + 1 < (int) vec.size() && val(ptr, x) <= val(ptr + 1, x); ++ptr);
        return val(ptr, x);
    }
} cht;
 
int N;
tuple<ll, ll, ll> rects[MAXN];
ll F[MAXN];
 
int main()
{
    fio;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        ll x, y, a;
        cin >> x >> y >> a;
        rects[i] = make_tuple(x, y, a);
    }
    sort(rects, rects + N);
    cht.add(0, 0);
    for (int i = 0; i < N; ++i) {
        F[i] = cht.get(get<1>(rects[i])) + get<0>(rects[i]) * get<1>(rects[i]) - get<2>(rects[i]);
        cht.add(-get<0>(rects[i]), F[i]);
    }
    cout << *max_element(F, F + N) << endl;
}
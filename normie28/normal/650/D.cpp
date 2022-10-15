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
using namespace std;
 
class Question
{
public:
    int v;
    int l;
    int r;
    int i;
};
 #define N 800002
int a[N];
vector<Question> q[N];
vector<int> v;
int l[N], r[N], f[N], c[N];
int o[N];
 
inline int Lowbit(int x)
{
    return x & -x;
}
 
void SetFenwick(int p, int v)
{
    for(; p <= (signed)::v.size(); p += Lowbit(p))
        f[p] = max(f[p], v);
 
    return;
}
 
int MaxFenwick(int p)
{
    int o;
 
    for(o = 0; p; p -= Lowbit(p))
        o = max(o, f[p]);
 
    return o;
}
 
int main(void)
{
	fio;
    int n, m, p, x;
    int i, j, o;
 
	cin>>n>>m;
    for(i = 1; i <= n; i ++)
    {
		cin>>a[i];
        v.push_back(a[i]);
    }
    for(i = 1; i <= m; i ++)
    {
		cin>>p>>x;
        q[p].push_back((Question){x, 0, 0, i});
        v.push_back(x);
    }
 
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(i = 1; i <= n; i ++)
    {
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        for(j = 0; j < (signed)q[i].size(); j ++)
            q[i].at(j).v = lower_bound(v.begin(), v.end(), q[i].at(j).v) - v.begin() + 1;
    }
 
    for(i = 1, o = 0; i <= n; i ++)
    {
        l[i] = MaxFenwick(a[i] - 1) + 1;
        for(j = 0; j < (signed)q[i].size(); j ++)
            q[i].at(j).l = MaxFenwick(q[i].at(j).v - 1) + 1;
        SetFenwick(a[i], l[i]);
        o = max(o, l[i]);
    }
    memset(f, 0, sizeof(f));
    for(i = n; i >= 1; i --)
    {
        r[i] = MaxFenwick(v.size() - a[i]) + 1;
        for(j = 0; j < (signed)q[i].size(); j ++)
            q[i].at(j).r = MaxFenwick(v.size() - q[i].at(j).v) + 1;
        SetFenwick(v.size() - a[i] + 1, r[i]);
    }
 
    for(i = 1; i <= n; i ++)
        if(l[i] + r[i] - 1 == o)
            c[l[i]] ++;
 
    for(i = 1; i <= n; i ++)
        for(j = 0; j < (signed)q[i].size(); j ++)
            ::o[q[i].at(j).i] = max(l[i] + r[i] - 1 == o && c[l[i]] == 1 ? o - 1 : o, q[i].at(j).l + q[i].at(j).r - 1);
    for(i = 1; i <= m; i ++)
		cout<<::o[i]<<endl;
 
}
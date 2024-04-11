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
namespace CPL_FWHT
{
vector<ll> transform(vector<ll> x, ll inv=0)
{
    vector<ll> res=x;
    ll h=1;
    while(h<res.size())
    {
        for (ll i=0;i<res.size();i+=h*2)
        for (ll j=i;j<i+h;j++)
        {
            ll x=res[j];
            ll y=res[j+h];
            res[j]=(x+y+MOD)%MOD;
            res[j+h]=(x-y+MOD)%MOD;
        }
        h*=2;
    }
    if (inv)
    {
        for (ll i=0;i<log2(res.size());i++)
        {
        for (ll& g : res) 
        {
            g*=(998244354/2);
            g%=MOD;
        }
        }
    }
    return res;
}

	vector<ll> multiply(vector<ll> a, vector<ll> b) // Actual multiplication
	{
		ll u=1;
		while((u<a.size())or(u<b.size())) u*=2;
		u*=2;
		while(a.size()<u) a.push_back(0);
		while(b.size()<u) b.push_back(0);
		//for (auto g : a) cout<<g<<' '; cout<<endl;
		//for (auto g : b) cout<<g<<' '; cout<<endl;
		vector<ll> ra=transform(a,0),rb=transform(b,0);
		for (ll i=0;i<u;i++)
		{
		//	cout<<i<<' '<<ra[i]<<' '<<rb[i]<<endl;
			ra[i]=((ra[i]*rb[i])%MOD);
		}
		vector<ll> res=transform(ra,1);
		return res;
	}
};
using namespace CPL_FWHT;
ll n,m,i,j,k,t,t1,u,v,a,b;
ll arr[100001];
vector<ll> va,vb,vc;
int main()
{
	fio;
    cin>>n;
    cin>>m;
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            char c;
            cin>>c;
            arr[j]+=(1<<i)*(c-48);
        }
    }
    va=vector<ll>((1<<n),0);
    vb=vector<ll>((1<<n),0);
    for (i=0;i<m;i++) va[arr[i]]++;
    for (i=0;i<(1<<n);i++) vb[i]=min(__builtin_popcount(i),n-__builtin_popcount(i));
    vc=multiply(va,vb);
    t=1e9;
    for (i=0;i<(1<<n);i++) t=min(t,vc[i]);
    cout<<t;
}
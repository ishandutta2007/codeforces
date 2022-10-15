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
vector<ll> vec;
ll n,m,i,j,k,t,t1,u,v,a,b;
ll lw[1000001];
ll arr[200001];
ll pre[200001];
ll inv[1000001];
ll l[200001],r[200001],res[200001];
vector<ll> req[200001];
ll prv[1000001];
struct seg
{
	ll val[1000001];
	void reset(ll c, ll l, ll r)
	{
		val[c]=1;
		if (l<r)
		{
			ll mid=(l+r)/2;
			reset((c<<1),l,mid);
			reset((c<<1)+1,mid+1,r);
		}
	}
	void upd(ll c, ll l, ll r, ll tl, ll tr, ll x)
	{
		if ((tl>r)or(tr<l)) return;
		if ((l>=tl)and(r<=tr)) 
		{
			val[c]*=x;
			val[c]%=MOD;
		}
		else
		{
			ll mid=(l+r)/2;
			upd((c<<1),l,mid,tl,tr,x);
			upd((c<<1)+1,mid+1,r,tl,tr,x);
		}
	}
	ll get(ll c, ll l, ll r, ll t)
	{
		if ((l<=t)and(t<=r))
		{
			ll a=val[c],b;
			if (l<r)
			{
				ll mid=(l+r)/2;
				b=get((c<<1),l,mid,t); a*=b; a%=MOD;
				b=get((c<<1)+1,mid+1,r,t); a*=b; a%=MOD;
			}
			return a;
		}
		return 1;
	}
};
seg st;
int main()
{
	fio;
	pre[0]=1;
	for (i=2;i<=1000000;i++) for (j=i;j<=1000000;j+=i) 
	if (!lw[j]) lw[j]=i;
	for (i=1;i<=1000000;i++) inv[i]=INV(i,MOD);
	cin>>n;
	for (i=1;i<=n;i++) {cin>>arr[i]; pre[i]=(pre[i-1]*arr[i])%MOD;}
	cin>>m;
	for (i=1;i<=m;i++) {cin>>l[i]>>r[i]; req[r[i]].push_back(i);}
	st.reset(1,1,n);
	for (i=1;i<=n;i++)
	{
		u=arr[i];
		while(u>1)
		{
			v=lw[u];
			if (prv[v]<i)
			{
				st.upd(1,1,n,prv[v]+1,i,((v-1)*inv[v])%MOD);
				prv[v]=i;
			}
			u/=v;
		}
		for (auto g : req[i])
		{
			u=pre[r[g]]*INV(pre[l[g]-1],MOD);
			u%=MOD;
			u*=st.get(1,1,n,l[g]);
			u%=MOD;
			res[g]=u;
		}
	}
	for (i=1;i<=m;i++) cout<<res[i]<<endl;
}
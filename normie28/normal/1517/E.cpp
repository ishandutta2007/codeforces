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
vector<ll> vec;
ll n,m,i,j,k,t,t1,u,v,a,b,res,summ=0;
ll arr[200001];
ll odd[200001],cntodd;
ll even[200001],cnteven;
vector<ll> pt[2];
int main()
{
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n;
		summ=0;
		for (i=0;i<n;i++) {cin>>arr[i]; summ+=arr[i];}
		arr[n]=0;
		if (summ%2) summ/=2;
		else
		{
			summ/=2; summ--;
		}
		res=0;	
		if (n<=11)
		{
			for (i=0;i<(1<<n);i++)
			{
				pt[0].clear();
				pt[1].clear();
				u=0;
				v=0;
				for (j=0;j<(n);j++) if (i&(1<<j)) {pt[1].push_back(j); v+=arr[j];}
				else {pt[0].push_back(j); u+=arr[j];}
				a=1;
			//	cout<<pt[0].size()<<' '<<pt[1].size()<<endl;
				for (k=1;k<(ll)pt[0].size()-1;k++) if (2*pt[0][k]>pt[0][k+1]+pt[0][k-1]) a=0;
				for (k=1;k<(ll)pt[1].size()-1;k++) if (2*pt[1][k]<pt[1][k+1]+pt[1][k-1]) a=0;
			//	for (k=1;k<(ll)pt[0].size()-1;k++) cout<<k<<' '; cout<<endl;
			//	for (k=1;k<(ll)pt[1].size()-1;k++) cout<<k<<' '; cout<<endl;
				if ((a)and(u<v))
				{
					res++;
				}
			}
			cout<<res<<endl;
		}
		else
		{
			for (i=1;i<n;i++)
			{
				odd[i]=odd[i-1];
				even[i]=even[i-1];
				if (i%2) odd[i]+=arr[i];
				else even[i]+=arr[i];
			}
		for (int c0=0;c0<2;c0++)
		for (int cn=0;cn<2;cn++)
		{
			u=0;
			if (c0) u+=arr[0];
			if (cn) u+=arr[n-1];
			int l,r;
			if (c0) l=0;
			else l=1;
			if (cn) r=n-3;
			else r=n-2;
			for (i=l;i<=r;i++)
			{
				if ((u+odd[i]+even[i])>summ) break;
				if (i%2)
				{
					int x=upper_bound(odd,odd+r+1,summ-u-even[i])-odd-1;
					res+=(x-i)/2+1;
				}
				else
				{
					int x=upper_bound(even,even+r+1,summ-u-odd[i])-even-1;
					res+=(x-i)/2+1;
				}
		//		cout<<i<<' '<<res<<endl;
			}
		//	cout<<res<<endl;
		}
		u=0;
		for (i=n+1;i>=1;i--)
		{
			u+=arr[i-1];
			if ((u<=summ)) res++;
		}
		cout<<res%MOD<<endl;
		}
	}
}
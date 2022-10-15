
// Problem : D. Lucky Segments
// Contest : Codeforces - Codeforces Beta Round #91 (Div. 1 Only)
// URL : https://codeforces.com/contest/121/problem/D
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
	Normie's Template v2.0
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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
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

//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
 
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
typedef __int128 ll128;
//---------END-------//
vector<ll> luck;
vector<pii(ll128)> penl,penr;
void genn(ll x)
{
	if (x) {luck.push_back(x); penl.push_back({0,0});penr.push_back({0,0});}
	if (x<1e17)
	{
		genn(x*10+4);
		genn(x*10+7);
	}
}
ll l[100001],r[100001],sz;
ll n,m,i,j,k,t,t1,u,v,a,b;
ll check(ll x)
{
		ll128 m128=m,cnt=0;
	for (ll i=0;i+x<=luck.size();i++)
	{
		cnt=0;
		cnt+=penl[i].se-(ll128)luck[i]*penl[i].fi;
		cnt+=(ll128)luck[i+x-1]*penr[i+x-1].fi-penr[i+x-1].se;
		if ((cnt<=m128)and(luck[i+x-1]-luck[i]+1<=sz))
		{
	//		cout<<"YES "<<x<<' '<<luck[i]<<' '<<luck[i+x-1]<<endl;
			return 1;
		}
	}
	return 0;
}
ll bs(ll l, ll r)
{
//	cout<<l<<' '<<r<<endl;
	if (l==r) return l;
	int mid=(l+r)/2;
	if (check(mid+1)) return bs(mid+1,r); else return bs(l,mid);
}
int main()
{
	fio;
	genn(0);
	sort(luck.begin(),luck.end());
	cin>>n>>m;
	sz=1e18;
	for (i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		sz=min(sz,r[i]-l[i]+1);
		u=lower_bound(luck.begin(),luck.end(),l[i])-luck.begin();
		if (u>=0) 
		{
			penl[u-1].fi++;
			penl[u-1].se+=l[i];
		}
		u=lower_bound(luck.begin(),luck.end(),r[i])-luck.begin();
		if (u<luck.size())
		{
			penr[u].fi++;
			penr[u].se+=r[i];
		}
	}
		for (i=1;i<luck.size();i++)
		{
			penr[i].fi+=penr[i-1].fi;
			penr[i].se+=penr[i-1].se;
		}
		for (i=luck.size()-2;i>=0;i--)
		{
			penl[i].fi+=penl[i+1].fi;
			penl[i].se+=penl[i+1].se;
		}
	cout<<bs(0,luck.size());
}
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
//---------END-------//
ll bow(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=bow(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll fac[200001];
ll inv[200001];
ll n,m,i,j,k,t,t1,u,v,a,b,res,fin;
vector<ll> lis;
vector<ll> pre;
int main()
{
	fio;
	cin>>n>>m;
	fac[0]=1;
	for (i=1;i<=n;i++)
	{
		fac[i]=fac[i-1]*i;
		fac[i]%=MOD;
	}
	inv[n]=bow(fac[n],MOD-2,MOD);
	for (i=n-1;i>=0;i--)
	{
		inv[i]=inv[i+1]*(i+1);
		inv[i]%=MOD;
	}
	for (i=1;i<=n;i++)
	{
		cin>>u;
		lis.push_back(u);
	}
	lis.push_back(-1);
	pre.push_back(0);
	sort(lis.begin(),lis.end());
	for (i=1;i<=n;i++)
	pre.push_back(lis[i]+pre[i-1]);
	for (i=1;i<=m;i++)
	{
		cin>>a>>b;
		u=lower_bound(lis.begin(),lis.end(),b)-lis.begin()-1;
		fin=0;
		res=pre[u];
		res%=MOD;
		res*=max(0,(n-u)+1-a);
		res%=MOD;
		res*=bow((n-u)+1,MOD-2,MOD);
		fin+=res;
		res=pre[n]-pre[u];
		res%=MOD;
		res*=max(0,(n-u)-a);
		res%=MOD;
		res*=bow((n-u),MOD-2,MOD);
		fin+=res;
		cout<<fin%MOD<<endl;
	}
}
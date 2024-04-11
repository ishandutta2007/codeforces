
// Problem : E. Olympic Games
// Contest : Codeforces - Codeforces Round #235 (Div. 2)
// URL : https://codeforces.com/contest/401/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
//---------END-------//
ll dp[200001];
ll n,m,l,r,i,j,k,t,t1,u,v,a,b,p,nl,nr;
ll bound(ll n, ll m, ll x)
{
//	cout<<"bound "<<n<<' '<<m<<' '<<x<<endl;
	ll res=0,u;
	for (ll i=1;(i<=n)and(i*i<=x);i++)
	{
		u=floor(sqrt(x-i*i));
		u=min(u,m);
		if (i==0) res+=(n+1)*(m+1+(m-u+1))*(u+1)/2;
		else res+=(n-i+1)*((m+1+(m-u+1))*(u+1)-2*(m+1));
		res%=p;
	}
//	cout<<res<<endl;
	return res;
}
ll norm(ll n, ll m, ll l, ll r)
{
	ll a=bound(n,m,r);
	ll b=bound(n,m,l-1);
	return (a-b+p)%p;
}
int main()
{
	fio;
	cin>>n>>m;
	cin>>l>>r>>p;
	l*=l;
	r*=r;
	for (i=min(m,n);i>=1;i--)
	{
		nl=ceil(ld(l)/i/i);
		nr=floor(ld(r)/i/i);
		j=i;
		dp[i]+=norm((n+1)/j-1,(m+1)/j-1,nl,nr)*(j-(n+1)%j)%p*(j-(m+1)%j)%p;
		dp[i]+=norm((n+1)/j,(m+1)/j-1,nl,nr)*((n+1)%j)%p*(j-(m+1)%j)%p;
		dp[i]+=norm((n+1)/j-1,(m+1)/j,nl,nr)*(j-(n+1)%j)%p*((m+1)%j)%p;
		dp[i]+=norm((n+1)/j,(m+1)/j,nl,nr)*((n+1)%j)%p*((m+1)%j)%p;
		dp[i]%=p;
		//cout<<i<<' '<<dp[i]<<endl;
		for (j=2*i;j<=min(m,n);j+=i)
		{
			dp[i]=(dp[i]-dp[j]+p)%p;
		}
	}
	a=dp[1];
	if (l==1) 
	{
		a+=(n+1)*m;
		a+=(m+1)*n;
		a%=p;
	}
	cout<<a;
}
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
#pragma GCC optimize("Ofast,vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//File I/O.
#define FILE_IN "1463F.inp"
#define FILE_OUT "1463F.out"
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
ll dp[5000000],dp2[5000000];
ll cnt[55];
ll n,m,i,j,k,t,t1,u,v,a,b,z;
int main()
{
//	ofile;
//	fio;
	cin>>n>>a>>b;
	for (i=0;i<a+b;i++)
	{
		if (i<n%(a+b)) cnt[i]=n/(a+b)+1;
		else cnt[i]=n/(a+b);
	}
	for (i=0;i<(1<<22);i++) dp[i]=-1e9;
	dp[0]=0;
	for (i=0;i<(a+b);i++)
	{
		v=u;
		u=0;
		for (j=0;j<(1<<22);j++)
		{
			k=j;
			k<<=1;
			k&=(1<<22)-1;
			dp2[k]=max(dp2[k],dp[j]);
			if ((!(j&(1<<(a-1))))and(!(j&(1<<(b-1))))) 
			{
				k=j;
				k<<=1;
				k&=(1<<22)-1;
				k++;
				dp2[k]=max(dp2[k],dp[j]+cnt[i]);
			}
		}
		for (j=0;j<(1<<22);j++)
		{
		u=max(u,dp2[j]);
			dp[j]=dp2[j];
			dp2[j]=0;
		}
	}
	cout<<u;
}
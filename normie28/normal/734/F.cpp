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
ll b[200001];
ll c[200001];
ll sum[200001];
ll arr[200001];
ll cnt[31];
ll n,m,i,j,k,t,t1,u,v;
int main()
{
	fio;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for (i=1;i<=n;i++)
	{
		cin>>c[i];
		sum[i]=b[i]+c[i];
	}
	u=0;
	for (i=1;i<=n;i++) u+=sum[i];
	if (u%2*n) return cout<<-1,0;
	u/=2*n;
	for (i=1;i<=n;i++)
	{
		arr[i]=sum[i]-u;
		if ((arr[i]%n)or(arr[i]<0)) return cout<<-1,0;
		arr[i]/=n;
		for (j=0;j<30;j++) if (arr[i]&(1<<j)) cnt[j]++;
	}
	for (i=1;i<=n;i++)
	{
		u=0;
		for (j=0;j<30;j++)
		{
			if (arr[i]&(1<<j)) u+=cnt[j]*(1<<j);
		}
		if (u-b[i]) return cout<<-1,0;
		
		u=0;
		for (j=0;j<30;j++)
		{
			if (!(arr[i]&(1<<j))) u+=cnt[j]*(1<<j);
			else
			{
				u+=n*(1<<j);
			}
		}
		if (u-c[i]) return cout<<-1,0;
	}
	for (i=1;i<=n;i++) cout<<arr[i]<<' ';
}
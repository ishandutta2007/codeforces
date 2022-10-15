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
ll dp[300001];
ll arr[300001];
ll used[300001];
ll isroot[300001];
ll n,m,i,j,k,t,t1,u,v,a,b,maxx=-1e18,cnt=0;
vector<ll> gt[300001],gtd[300001];
ll nmax[300001];
ll ncnt[300001];
void dfs(int x)
{
	used[x]=1;
	dp[x]=arr[x];
	for (int g : gt[x]) if (!used[g])
	{
		dfs(g);
		dp[x]+=max(dp[g],0);
		if (dp[g]>0)
		{
		gtd[x].push_back(g);
		isroot[g]=0;
		}
	}
}
void dfs2(int x)
{
	used[x]=1;
	nmax[x]=-1e18;
	ncnt[x]=0;
	for (int g : gtd[x])
	{
		dfs2(g);
		if (nmax[x]<nmax[g])
		{
			nmax[x]=nmax[g];
			ncnt[x]=ncnt[g];
		}
		else if (nmax[x]==nmax[g])
		{
			ncnt[x]+=ncnt[g];;
		}
	}
	if (nmax[x]<dp[x])
	{
		nmax[x]=dp[x];
		ncnt[x]=1;
	}
}
int main()
{
	fio;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>arr[i];
		isroot[i]=1;
	}
	for (i=1;i<n;i++)
	{
		cin>>u>>v;
		gt[u].push_back(v);
		gt[v].push_back(u);
	}
	dfs(1);
	for (i=1;i<=n;i++) used[i]=0;
	for (i=1;i<=n;i++) if (isroot[i])
	{
		dfs2(i);
		if (nmax[i]>maxx)
		{
			maxx=nmax[i];
			cnt=ncnt[i];
		}
		else if (nmax[i]==maxx) cnt+=ncnt[i];
	}
	cout<<maxx*cnt<<' '<<cnt;
}
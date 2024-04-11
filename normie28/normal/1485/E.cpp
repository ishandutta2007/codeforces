
// Problem : E. Move and Swap
// Contest : Codeforces - Codeforces Round #701 (Div. 2)
// URL : https://codeforces.com/contest/1485/problem/E
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
ll n,m,i,j,k,t,t1,u,v,a,b,l;
vector<ll> dep[200001],gt[200001];
ll minn[200001][2];
ll maxx[200001][2];
ll dp[200001];
ll arr[200001];
void dfs(ll x, ll d)
{
	//cout<<"dfs "<<x<<' '<<d<<endl;
	dep[d].push_back(x);
	for (auto g : gt[x]) dfs(g,d+1);
	if (gt[x].size()==0) l=d;
}
int main()
{
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n;
		for (i=0;i<=n;i++)
		{
			dep[i].clear();
			minn[i][0]=-1e18;
			minn[i][1]=-1e18;
			maxx[i][0]=-1e18;
			maxx[i][1]=-1e18;
			dp[i]=-1e18;
			gt[i].clear();
		}
		for (i=2;i<=n;i++)
		{
			cin>>u;
			gt[u].push_back(i);
		}
		for (i=2;i<=n;i++)
		{
			cin>>arr[i];
		}
		dfs(1,0);
		for (auto g : dep[l]) 
		{
			dp[g]=0;
			minn[l][0]=max(minn[l][0],-arr[g]);
			maxx[l][0]=max(maxx[l][0],arr[g]);
			minn[l][1]=max(minn[l][1],dp[g]-arr[g]);
			maxx[l][1]=max(maxx[l][1],dp[g]+arr[g]);
		}
			//cout<<l<<' '<<minn[l][0]<<' '<<maxx[l][0]<<' '<<minn[l][1]<<' '<<maxx[l][1]<<endl;
		for (i=l-1;i>=0;i--)
		{
			for (auto g : dep[i])
			{
			for (auto gg : gt[g])
			{
				dp[g]=max(dp[g],dp[gg]+arr[gg]+minn[i+1][0]);
				dp[g]=max(dp[g],dp[gg]-arr[gg]+maxx[i+1][0]);
				dp[g]=max(dp[g],arr[gg]+minn[i+1][1]);
				dp[g]=max(dp[g],-arr[gg]+maxx[i+1][1]);
			}
			
			minn[i][0]=max(minn[i][0],-arr[g]);
			maxx[i][0]=max(maxx[i][0],arr[g]);
			minn[i][1]=max(minn[i][1],dp[g]-arr[g]);
			maxx[i][1]=max(maxx[i][1],dp[g]+arr[g]);
		//	cout<<g<<' '<<dp[g]<<' '<<arr[g]<<endl;
			}
		//	cout<<i<<' '<<minn[i][0]<<' '<<maxx[i][0]<<' '<<minn[i][1]<<' '<<maxx[i][1]<<endl;
		}
		cout<<dp[1]<<endl;
	}
}

// Problem : G. Yet Another DAG Problem
// Contest : Codeforces - Educational Codeforces Round 96 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1430/problem/G
// Memory Limit : 1024 MB
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
int dp[262144][18];
int ch1[262144][18];
int ch2[262144][18];
int cost[262144];
vector<pii(int)> gt[18];
int indeg[18];
int pos[18];
int req[18];
vector<int> ord;
int res[18];
int n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
	cin>>n>>m;
	for (i=0;i<m;i++)
	{
		cin>>u>>v>>a;
		u--;v--;
		gt[u].push_back({v,a});
		indeg[v]++;
	}
	for (i=0;i<n;i++) if (!indeg[i]) ord.push_back(i);
	for (j=0;j<ord.size();j++)
	{
		for (auto g : gt[ord[j]]) 
		{
			indeg[g.fi]--;
			if (!indeg[g.fi]) ord.push_back(g.fi);
		}
	}
	for (j=0;j<n;j++) pos[ord[j]]=j;
	//for (i=0;i<n;i++) cout<<ord[i]<<' '; cout<<endl;
	//for (i=0;i<n;i++) cout<<pos[i]<<' '; cout<<endl;
	
	for (i=0;i<n;i++) for (auto g : gt[ord[i]]) 
	{
		u=pos[g.fi];
		req[i]^=(1<<u);
		for (k=0;k<(1<<n);k++) if ((k&(1<<u))and(!(k&(1<<i)))) cost[k]+=g.se;
	}
	for (t=1;t<(1<<n);t++) for (i=0;i<n;i++) dp[t][i]=1e9;
	for (t=0;t<(1<<n);t++)
	{
		for (i=0;i<n;i++)
		{
			j=(i+n-1)%n;
			u=dp[t][j];
			if (i==0) u+=cost[t];
			if (u<dp[t][i])
			{
				ch1[t][i]=t;
				ch2[t][i]=j;
				dp[t][i]=u;
			}
			if ((t&(1<<j))and((t&req[j])==req[j]))
			{
				u=dp[t^(1<<j)][j];
				if (i==0) u+=cost[t];
				if (u<dp[t][i])
				{
					ch1[t][i]=t^(1<<j);
					ch2[t][i]=j;
				dp[t][i]=u;
				}
			}
		}
		
		
		for (i=0;i<n;i++)
		{
			j=(i+n-1)%n;
			u=dp[t][j];
			if (i==0) u+=cost[t];
			if (u<dp[t][i])
			{
				ch1[t][i]=t;
				ch2[t][i]=j;
				dp[t][i]=u;
			}
			if ((t&(1<<j))and((t&req[j])==req[j]))
			{
				u=dp[t^(1<<j)][j];
				if (i==0) u+=cost[t];
				if (u<dp[t][i])
				{
					ch1[t][i]=t^(1<<j);
					ch2[t][i]=j;
				dp[t][i]=u;
				}
			}
		}
	//	cout<<t<<":\n";
	//	for (i=0;i<n;i++) cout<<dp[t][i]<<' '; 
	//	cout<<endl;
	}
	t--;
	j=0;
	for (i=0;i<n;i++) if (dp[t][i]<dp[t][j]) j=i;
	i=j;
	u=1000;
	while(t)
	{
		if (i==0) u--;
		if (ch1[t][i]-t) res[(i+n-1)%n]=u;
		a=ch1[t][i];
		b=ch2[t][i];
		t=a;
		i=b;
	}
	for (i=0;i<n;i++) cout<<res[pos[i]]<<' ';
	/*
	*/
}
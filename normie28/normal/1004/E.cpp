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
vector<pii(int)> gt[100001];
int dis[100001];
int deg[100001];
struct cmp 
{
	int operator()(int a, int b)
	{
		return (dis[a]>dis[b]);
	}
};
priority_queue<int,vector<int>,cmp> pq;
int n,m,i,j,k,t,t1,u,v,a,b;
int cnt,bad;
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<n;i++)
	{
		cin>>u>>v>>a;
		gt[u].push_back({v,a});
		gt[v].push_back({u,a});
		deg[u]++;
		deg[v]++;
	}
	for (i=1;i<=n;i++)
	{
		cnt++;
		if (deg[i]>=3) bad++;
		if (deg[i]==1)
		{
			for (auto g : gt[i]) if (deg[g.fi])
			{
				dis[i]=g.se;
				pq.push(i);
			}
		}
	}
		if ((cnt<=m)and(!bad))
		{
			cout<<0;
         	 return 0;
		}
	while(pq.size())
	{
		u=pq.top();
      //	cout<<u<<' '<<dis[u];
		pq.pop();
		deg[u]=0; cnt--;
		for (auto g : gt[u]) if (deg[g.fi])
		{
       //   cout<<g.fi<<' '<<deg[g.fi]<<endl;
			deg[g.fi]--;
			if (deg[g.fi]==2) bad--;
			if (deg[g.fi]==1)
			{
				for (auto gg : gt[g.fi]) if (deg[gg.fi])
				{
					dis[g.fi]=dis[u]+gg.se;
					pq.push(g.fi);
				}
			}
		}
     // cout<<' '<<cnt<<' '<<bad<<endl;
		if ((cnt<=m)and(!bad))
		{
			cout<<dis[u];
         	 return 0;
		}
	}
}
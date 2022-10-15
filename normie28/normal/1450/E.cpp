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
int dis[201][201];
int edge[201][201];
int n,m,i,j,k,t,t1,u,v,a,b;
vector<pii(int)> pp;
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=n;i++) for (j=1;j<=n;j++) dis[i][j]=INT_MAX;
	for (i=1;i<=n;i++) dis[i][i]=0;
	for (i=1;i<=m;i++)
	{
		cin>>u>>v>>b;
		pp.emplace_back(u,v);
		if (b)
		{
		dis[u][v]=1;
		dis[v][u]=-1;
		}
		else
		{
		dis[u][v]=1;
		dis[v][u]=1;
		}
	}
	for (k=1;k<=n;k++)
	for (i=1;i<=n;i++)
	for (j=1;j<=n;j++)
	{
		if ((dis[i][k]!=INT_MAX)and(dis[k][j]!=INT_MAX))
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		if ((dis[i][j]<-1e9))
		{
			cout<<"NO";
			return 0;
		}
		if ((dis[i][i]<0))
		{
			cout<<"NO";
			return 0;
		}
	}
	u=1;
	v=1;
	for (i=1;i<=n;i++) for (j=1;j<=n;j++) if (dis[i][j]>dis[u][v])
	{
		u=i;
		v=j;
	}
	for (i=1;i<=m;i++) if (dis[u][pp[i-1].fi]%2==dis[u][pp[i-1].se]%2) 
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	cout<<dis[u][v]<<endl;
	v=1e9;
	for (i=1;i<=n;i++) v=min(v,dis[u][i]);
	for (i=1;i<=n;i++) cout<<dis[u][i]-v<<' ';
}
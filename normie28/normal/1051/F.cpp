
// Problem : F. The Shortest Statement
// Contest : Codeforces - Educational Codeforces Round 51 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1051/problem/F
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
//---------END-------//
struct cmp
{
	int operator()(pii(ll) a, pii(ll) b) const
	{
		return (a.se>b.se);
	}
};
priority_queue<pii(ll),vector<pii(ll)>,cmp> pq;
vector<pii(ll)> gt[100001];
ll eu[100001],ev[100001],ew[100001],intree[100001];
ll dep[100001],dep1[100001],dis[100001][43],par[100001][17];
ll n,m,i,j,k,t,t1,u,v,a,b,q,q1,res;
ll qu,qv;
void dfs(ll x, ll d, ll d1)
{
	dep[x]=d;
	dep1[x]=d1;
	for (int i=1;i<17;i++) par[x][i]=par[par[x][i-1]][i-1];
	for (auto g : gt[x]) if (dep[g.fi]==-1)
	{
		par[g.fi][0]=x;
		intree[g.se]=1;
		dfs(g.fi,d+ew[g.se],d1+1);
	}
}
void adds(int x)
{
	t++;
	for (int i=1;i<=n;i++) dis[i][t]=1e18;
	dis[x][t]=0;
	pq.push(pii(ll)(x,0));
	while(pq.size())
	{
		auto pp=pq.top(); pq.pop();
		if (dis[pp.fi][t]-pp.se) continue;
		for (auto g : gt[pp.fi]) if (ew[g.se]+pp.se<dis[g.fi][t])
		{
			dis[g.fi][t]=ew[g.se]+pp.se;
			pq.push(pii(ll)(g.fi,dis[g.fi][t]));
		}
	}
//	cout<<x<<endl;
//	for (int i=1;i<=n;i++) cout<<dis[i][t]<<' '; cout<<endl;
}
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>eu[i]>>ev[i]>>ew[i];
		gt[eu[i]].push_back({ev[i],i});
		gt[ev[i]].push_back({eu[i],i});
	}
	for (i=1;i<=n;i++) dep[i]=-1;
	for (i=0;i<17;i++) par[1][i]=1;
	dfs(1,0,0);
	for (i=1;i<=m;i++) if (!intree[i])
	{
	//	cout<<i<<endl;
		adds(eu[i]);
		adds(ev[i]);
	}
	cin>>q;
	for (q1=0;q1<q;q1++)
	{
		res=1e18;
		cin>>qu>>qv;
		u=qu;
		v=qv;
		for (i=16;i>=0;i--) if (dep1[u]-(1<<i)>=dep1[v]) u=par[u][i];
		for (i=16;i>=0;i--) if (dep1[v]-(1<<i)>=dep1[u]) v=par[v][i];
		for (i=16;i>=0;i--) if (par[u][i]-par[v][i])
		{
			u=par[u][i];
			v=par[v][i];
		}
		if (u-v) u=par[u][0];
		res=min(res,dep[qu]+dep[qv]-2*dep[u]);
		for (i=1;i<=t;i++) res=min(res,dis[qu][i]+dis[qv][i]);
		cout<<res<<endl;
	}
}
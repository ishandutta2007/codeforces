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
vector<int> gt[100001],down[100001],bk[100001];
int dis[100001];
int par[100001];
int marked[100001];
vector<int> cur,res;
int n,m,i,j,k,t,t1,u,v,a,b,tar;
void dfs(int x, int p, int d)
{
	dis[x]=d;
	par[x]=p;
	for (int g : gt[x]) 
	{
		if (dis[g])
		{
			if (dis[g]<dis[x]) bk[x].push_back(g);
			
		}
		else
		{
			down[x].push_back(g);
			dfs(g,x,d+1);
		}
	}
}
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>u>>v;
		gt[u].push_back(v);
		gt[v].push_back(u);
	}
	tar=ceil(sqrt(n));
	dfs(1,-1,1);
	for (i=1;i<=n;i++) cur.push_back(i);
	sort(cur.begin(),cur.end(),[](int a, int b){
		return (dis[a]<dis[b]);
	});
	for (t=n-1;t>=0;t--)
	{
		u=cur[t];
		if (bk[u].size()>=tar-1) 
		{
			sort(bk[u].begin(),bk[u].end(),[](int a, int b){
				return (dis[a]<dis[b]);
			});
			v=bk[u][0];
			while(u!=v)
			{
				res.push_back(u);
				u=par[u];
			}
			res.push_back(u);
			cout<<2<<' '<<res.size()<<endl;
			for (int g :res) cout<<g<<' ';
			return 0;
		}
		else
		{
			int fail=0;
			for (int g : gt[u]) if (marked[g]) fail=1;
			if (!fail) marked[u]=1;
		}
	}
	cout<<1<<endl;
	t=0;
	for (i=1;i<=n;i++) if (marked[i])
	{
		cout<<i<<' ';
		t++;
		if (t==tar) return 0;
	}
}
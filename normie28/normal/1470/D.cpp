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
vector<int> gt[300001],down[300001],down2[300001];
int n,m,i,j,k,t,t1,u,v,a,b,iter;
int arr[300001],used[300001];
vector<int> res;
void dfs(int x, int p)
{
	if(iter > 2*n) return;
	iter++;
//	cout<<"dfs "<<x<<' '<<p<<endl;
	used[x]=1;
	for (int g : gt[x]) if (g!=p)
	{
	//	cout<<x<<' '<<g<<endl;
		if (used[g]) down2[g].push_back(x);
		else {
		down[x].push_back(g); used[g]=1;}
	}
	gt[x].clear();
	for (int g : down[x])  dfs(g,x);
}
void calc(int x)
{
	if (arr[x]==-1) arr[x]=1;
	if (arr[x]==1)
	{
		for (int g : down[x]) arr[g]=0;
		for (int g : down2[x]) arr[g]=0;	
	} 
	else
	{
		for (int g : down[x]) if (arr[g]==-1) arr[g]=1;
	}
	for (int g : down[x]) calc(g);
}
int main()
{
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		iter=0;
		cin>>n;
		res.clear();
		for (i=1;i<=n;i++)
		{
			arr[i]=-1;
			used[i]=0;
			gt[i].clear();
			down[i].clear();
			down2[i].clear();
		}
		cin>>m;
		for (i=1;i<=m;i++)
		{
			cin>>u>>v;
			gt[u].push_back(v);
			gt[v].push_back(u);
		}
		dfs(1,-1);
		
		int fail=0;
		for (i=1;i<=n;i++) if (!used[i])
		{
			fail=1;
		}
		if (fail)
		{
			cout<<"NO\n";
		}
		else
		{
		
		cout<<"YES\n";
		calc(1);
		for (i=1;i<=n;i++) if (arr[i]) res.push_back(i);
		cout<<res.size()<<endl;
		for (int g :res) cout<<g<<' '; cout<<endl; 
		}
	}
}
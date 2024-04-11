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
int maxx[4200001];
int dep[500001];
int res[500001];
int subt[500001];
int mask[500001];
int n,m,i,j,k,t,t1,u,v,a,b;
vector<pii(int)> gt[500001];
void init(int x, int d, int m)
{
	subt[x]=1;
	dep[x]=d;
	mask[x]=m;
	for (auto g : gt[x])
	{
	init(g.fi,d+1,m^(1<<(g.se)));
	subt[x]+=subt[g.fi];
	}
}
void del(int x)
{
	maxx[mask[x]]=-1e9;
	for (auto g : gt[x])
	del(g.fi);
}
void plaincalc(int x, int tar)
{
	res[tar]=max(res[tar],dep[x]+maxx[mask[x]]-2*dep[tar]);
	for (int i=0;i<22;i++) res[tar]=max(res[tar],dep[x]+maxx[mask[x]^(1<<i)]-2*dep[tar]);
	for (auto g : gt[x])
	plaincalc(g.fi,tar);
}
void add(int x)
{
	maxx[mask[x]]=max(maxx[mask[x]],dep[x]);
	for (auto g : gt[x])
	add(g.fi);
}
void calc(int x)
{
//	cout<<"calc "<<x<<endl;
	if (gt[x].size())
	{
	sort(gt[x].begin(),gt[x].end(),[](pii(int) a, pii(int) b){
		return (subt[a.fi]>subt[b.fi]);
	});
	for (int i=1;i<gt[x].size();i++)
	{
		calc(gt[x][i].fi);
		del(gt[x][i].fi);
	}
	calc(gt[x][0].fi);
	for (int i=1;i<gt[x].size();i++)
	{
		plaincalc(gt[x][i].fi,x);
		add(gt[x][i].fi);
	}
	}
	res[x]=max(res[x],maxx[mask[x]]-dep[x]);
	for (int i=0;i<22;i++) res[x]=max(res[x],maxx[mask[x]^(1<<i)]-dep[x]);
	maxx[mask[x]]=max(maxx[mask[x]],dep[x]);
	for (auto g: gt[x]) res[x]=max(res[x],res[g.fi]);
}
int main()
{
	fio;
	for (i=0;i<(1<<22);i++)
	maxx[i]=-1e9;
	cin>>n;
	for (i=2;i<=n;i++)
	{
		char c;
		cin>>u>>c;
		v=c-97;
		gt[u].push_back({i,v});
	}
	init(1,0,0);
	calc(1);
	for (i=1;i<=n;i++) cout<<res[i]<<' ';
}
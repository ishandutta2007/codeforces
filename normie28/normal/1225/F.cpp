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
vector<int> gt[100001];
int p[100001],dep[100001],maxx[100001];
vector<piii(int)> bruh;
vector<int> lis;
int n,m,i,j,k,t,t1,u=-1,v=-1,a,b;
void dfs(int x, int d)
{
	dep[x]=d;
	maxx[x]=d;
	for (int g : gt[x]) 
	{
		dfs(g,d+1);
		maxx[x]=max(maxx[x],maxx[g]);
	}
	sort(gt[x].begin(),gt[x].end(),[](int a, int b){
		return (maxx[a]>maxx[b]);
	});
}
void build(int x)
{
//	cout<<"build "<<x<<endl;
	for (int i=0;i<gt[x].size();i++)
	{
		if (u!=-1) bruh.push_back({u,{x,gt[x][i]}});
		build(gt[x][i]);
	}
	if (v==-1) v=x;
	u=x;
}
int main()
{
	cin>>n;
	for (i=1;i<n;i++)
	{
		cin>>p[i];
		gt[p[i]].push_back(i);
	}
	dfs(0,1);
	build(0);
	for (auto g : bruh)
	{
//		cout<<g.fi<<' '<<g.se.fi<<' '<<g.se.se<<endl;
		p[g.fi]=g.se.se;
	}
	for (i=0;i<n;i++)
	{
		lis.push_back(v);
		v=p[v];
	}
	for (i=n-1;i>=0;i--) cout<<lis[i]<<' ';
	cout<<endl;
	cout<<bruh.size()<<endl;
	for (i=bruh.size()-1;i>=0;i--)
	{
		cout<<bruh[i].fi<<' ';
	}
}
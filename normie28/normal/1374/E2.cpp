
// Problem : E2. Reading Books (hard version)
// Contest : Codeforces - Codeforces Round #653 (Div. 3)
// URL : https://codeforces.com/contest/1374/problem/E2
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
int n,m,i,j,k,t,t1,u,v,a,b,res,minn=2e9+1e8,minna;
int arr[200001];
vector<int> gr[2][2];
struct cmp
{
	int operator()(int a, int b) const
	{
		if (arr[a]-arr[b]) return (arr[a]<arr[b]);
		return (a<b);
	}
};
set<int,cmp> cur,cur2;
int summ,lim;
void purge()
{
	while(cur.size()>lim)
	{
		auto g=(cur.end());
		g--;
		int u=(*g);
		cur.erase(u);
		cur2.insert(u);
		summ-=arr[u];
	}
}
void add(int x)
{
	cur.insert(x);
	summ+=arr[x];
	purge();
};
void rmv(int x)
{
	auto g=cur.lower_bound(x);
	if ((g!=cur.end())and((*g)==x))
	{
		int u=(*g);
		cur.erase(u);
		summ-=arr[u];
		while ((cur.size()<lim)and(cur2.size()))
		{
			u=*(cur2.begin());
			cur2.erase(u);
			cur.insert(u);
			summ+=arr[u];
		}
	}
	else
	{
		cur2.erase(u);
	}
}
int main()
{
	fio;
	cin>>n>>m>>k;
	for (i=1;i<=n;i++)
	{
		cin>>u>>a>>b;
		arr[i]=u;
		gr[a][b].push_back(i);
	}
	for (i=0;i<2;i++) for (j=0;j<2;j++) sort(gr[i][j].begin(),gr[i][j].end(),[](int a, int b)
	{
		if (arr[a]-arr[b]) return (arr[a]<arr[b]);
		return (a<b);
	});
	if (gr[1][1].size()+min(gr[1][0].size(),gr[0][1].size())<k) 
	{
		cout<<-1;
		return 0;
	}
	a=min(gr[1][1].size(),k);
	if (2*k-a>m)
	{
		cout<<-1;
		return 0;
	}
	
	
	
	cur.clear();
	cur2.clear();
	summ=0;
	res=0;
	lim=m-(2*k-a);
	
	for (i=0;i<a;i++) res+=arr[gr[1][1][i]];
	for (i=a;i<gr[1][1].size();i++) add(gr[1][1][i]);
	
	for (i=0;i<k-a;i++) res+=arr[gr[1][0][i]];
	for (i=k-a;i<gr[1][0].size();i++) add(gr[1][0][i]);
	
	for (i=0;i<k-a;i++) res+=arr[gr[0][1][i]];
	for (i=k-a;i<gr[0][1].size();i++) add(gr[0][1][i]);
	
	for (i=0;i<gr[0][0].size();i++) add(gr[0][0][i]);
	i=a;
	minn=res+summ;
	minna=a;
	//cout<<i<<' '<<res<<' '<<summ<<endl;
	//for (auto g : cur) cout<<g<<endl;
	//for (auto g : cur2) cout<<g<<endl;
	for (i=a-1;i>=0;i--) if ((2*k-i<=m)and(k-i<=gr[1][0].size())and(k-i<=gr[0][1].size()))
	{
		res-=arr[gr[1][1][i]];
		add(gr[1][1][i]);
		res+=arr[gr[1][0][k-i-1]];
		rmv(gr[1][0][k-i-1]);
		res+=arr[gr[0][1][k-i-1]];
		rmv(gr[0][1][k-i-1]);
		lim--;
		purge();
		if (minn>res+summ)
		{
			minn=res+summ;
			minna=i;
		}
	//cout<<i<<' '<<res<<' '<<summ<<endl;
	//for (auto g : cur) cout<<g<<endl;
	//for (auto g : cur2) cout<<g<<endl;
	}
	cout<<minn<<endl;
	
	
	
	cur.clear();
	cur2.clear();
	summ=0;
	res=0;
	lim=m-(2*k-a);
	
	for (i=0;i<a;i++) res+=arr[gr[1][1][i]];
	for (i=a;i<gr[1][1].size();i++) add(gr[1][1][i]);
	
	for (i=0;i<k-a;i++) res+=arr[gr[1][0][i]];
	for (i=k-a;i<gr[1][0].size();i++) add(gr[1][0][i]);
	
	for (i=0;i<k-a;i++) res+=arr[gr[0][1][i]];
	for (i=k-a;i<gr[0][1].size();i++) add(gr[0][1][i]);
	
	for (i=0;i<gr[0][0].size();i++) add(gr[0][0][i]);
	i=a;
	if (minna==i)
	{
		for (j=0;j<i;j++) cout<<gr[1][1][j]<<' ';
		for (j=0;j<(k-i);j++) cout<<gr[1][0][j]<<' ';
		for (j=0;j<(k-i);j++) cout<<gr[0][1][j]<<' ';
		for (auto g : cur) cout<<g<<' ';
	}
	for (i=a-1;i>=0;i--) if ((2*k-i<=m)and(k-i<=gr[1][0].size())and(k-i<=gr[0][1].size()))
	{
		res-=arr[gr[1][1][i]];
		add(gr[1][1][i]);
		res+=arr[gr[1][0][k-i-1]];
		rmv(gr[1][0][k-i-1]);
		res+=arr[gr[0][1][k-i-1]];
		rmv(gr[0][1][k-i-1]);
		lim--;
		purge();
	if (minna==i)
	{
		for (j=0;j<i;j++) cout<<gr[1][1][j]<<' ';
		for (j=0;j<(k-i);j++) cout<<gr[1][0][j]<<' ';
		for (j=0;j<(k-i);j++) cout<<gr[0][1][j]<<' ';
		for (auto g : cur) cout<<g<<' ';
	}
	}
}
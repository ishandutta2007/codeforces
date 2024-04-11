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
int ind[600001];
int pw27[5]={1,27,27*27,27*27*27,27*27*27*27};
vector<int> gt[100001];
int indeg[100001];
string str,pat;
int tar[100001];
int n,m,i,j,k,t,t1,u,v,a,b;
vector<int> res,lis;
vector<int> stacc;
void fail()
{
	cout<<"NO";
	exit(0);
}
void success()
{
	cout<<"YES\n";
	for (auto g : res) cout<<g<<' ';
	exit(0);
}
int main()
{
	fio;
	cin>>n>>m>>k;
	for (i=1;i<=n;i++)
	{
		cin>>pat;
    //  cout<<pat<<endl;
		u=0;
		for (j=0;j<k;j++)
		if (pat[j]!='_')
		u+=(pat[j]-96)*pw27[j];
		ind[u]=i;
	}
	for (i=1;i<=m;i++)
	{
		cin>>str;
		lis.clear();
		for (t=0;t<(1<<k);t++)
		{
			u=0;
			for (j=0;j<k;j++)
				if (t&(1<<j))
					u+=(str[j]-96)*pw27[j];
			if (ind[u]) lis.push_back(ind[u]);
		}
		u=0;
		cin>>a;
   //   	for (auto g : lis) cout<<g<<' '; cout<<endl;
		for (j=0;j<lis.size();j++) if (lis[j]==a) u=1;
		if (!u) fail();
		for (j=0;j<lis.size();j++) if (lis[j]!=a) 
		{
			gt[a].push_back(lis[j]);
			indeg[lis[j]]++;
		}
	}
	for (i=1;i<=n;i++) if (!indeg[i]) stacc.push_back(i);
	while(stacc.size())
	{
		u=stacc[stacc.size()-1]; stacc.pop_back();
		res.push_back(u);
		for (auto g : gt[u]) 
		{
			indeg[g]--;
			if (!indeg[g]) stacc.push_back(g);
		}
	}
	if (res.size()<n) fail();
	success();
}
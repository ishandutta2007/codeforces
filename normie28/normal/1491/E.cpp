
// Problem : E. Fib-tree
// Contest : Codeforces - Codeforces Global Round 13
// URL : https://codeforces.com/contest/1491/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
set<int> gt[200001];
int sz[200001],par[200001];
int fib[200001];
int n,m,i,j,k,t,t1,u,v,a,b;
map<int,int> mp;
int check(int x)
{
	//cout<<"check "<<x<<endl;
	vector<int> v;
	v.push_back(x);
	for (int i=0;i<v.size();i++)
	{
		sz[v[i]]=1;
		for (auto g : gt[v[i]]) if (!sz[g])
		{
			par[g]=v[i];
			v.push_back(g);
		}
	}
	if (v.size()==1) return 1;
	if (!mp[v.size()]) return 0;
	for (int i=v.size()-1;i>=1;i--)
	{
		sz[par[v[i]]]+=sz[v[i]];
	}
	int s,t,i,j;
//	cout<<"check "<<x<<endl;
//	for (auto g : v) cout<<g<<' '<<sz[g]<<endl;
	for (i=0;i<v.size();i++) if ((mp[sz[v[i]]])and(mp[v.size()-sz[v[i]]])) break;
	if (i==v.size()) return 0;
	i=v[i];
	j=par[i];
	gt[i].erase(j);
	gt[j].erase(i);
	for (int i=0;i<v.size();i++)
	{
		sz[v[i]]=0;
	}
	return ((check(i))and(check(j)));
}
int main()
{
	fio;
	cin>>n;
	for (i=1;i<n;i++)
	{
		cin>>u>>v;
		gt[u].insert(v);
		gt[v].insert(u);
	}
	fib[0]=1;
	fib[1]=1;
	for (i=2;;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		if (fib[i]>=n) break;
	}
	for (j=1;j<=i;j++) mp[fib[j]]=j;
	if (check(1)) cout<<"YES"; else cout<<"NO";
}
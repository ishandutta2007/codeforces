// Problem: E. Flights
// Contest: Codeforces - Bayan 2012-2013 Elimination Round (ACM ICPC Rules, English statements)
// URL: https://codeforces.com/contest/241/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
	Normie's Template v2.1
	Changes:
	Added vectorization optimizations.
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
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
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

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
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
vector<int> gt[1001],gtr[1001];
vector<pii(int)> gtd[1001];
int n,m,i,j,k,t,t1,u,v,a,b;
int dis[1001];
int inn[1001][1001];
int eu[5001],ev[5001];
void dfs(int x)
{
	inn[x][1]=1;
	for (auto g : gt[x]) if (!inn[g][1]) dfs(g);
}
void dfsr(int x)
{
	inn[x][n]=1;
	for (auto g : gtr[x]) if (!inn[g][n]) dfsr(g);
}
int main()
{
	fio;
	cin>>n;
	cin>>m;
	for (i=1;i<=m;i++)
	{
		cin>>u>>v;
		eu[i]=u;
		ev[i]=v;
		gt[u].push_back(v);
		gtr[v].push_back(u);
	}
	dfs(1);
	dfsr(n);
	for (i=1;i<=n;i++) for (auto g : gt[i]) if ((inn[i][1])and(inn[i][n])and(inn[g][1])and(inn[g][n]))
	{
		gtd[i].emplace_back(g,2);
		gtd[g].emplace_back(i,-1);
	}
	for (t=1;t<=2*n+1;t++)
	{
		a=0;
		for (i=1;i<=n;i++) for (auto g : gtd[i]) 
		if (dis[i]+g.se<dis[g.fi])
		{
			a=1;
			dis[g.fi]=dis[i]+g.se;
		}
	}
	if (a)
	{
		cout<<"No";
	}
	else
	{
		cout<<"Yes\n";
	for (i=1;i<=m;i++)
	{
		if ((inn[eu[i]][1])and(inn[eu[i]][n])and(inn[ev[i]][1])and(inn[ev[i]][n]))
		cout<<dis[ev[i]]-dis[eu[i]];
		else cout<<1;
		cout<<endl;
	}
	}
}
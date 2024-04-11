
// Problem : E. Minimal Labels
// Contest : Codeforces - Educational Codeforces Round 25
// URL : https://codeforces.com/contest/825/problem/E
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
#include <bits/stdc++.h> 
using namespace std;
vector<int> gt[100001];
int p[100001];
int minn[100001];
int n,m,i,j,k,t,t1,u,v,a,b;
priority_queue<int> cur;
int oudeg[100001];
void calc(int x)
{
	minn[x]=x;
	for (auto g : gt[x])
	{
		if (minn[g]==1e9) calc(g);
		minn[x]=min(minn[x],minn[g]);
	}
}
void dfs(int x)
{
	for (auto g : gt[x]) if (!p[g]) dfs(g);
	t++;
	p[x]=t;
}
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>v>>u;
		gt[u].push_back(v);
		oudeg[v]++;
	}
	for (i=1;i<=n;i++) if (!oudeg[i]) cur.push(i);
	while(cur.size())
	{
		u=cur.top();
		cur.pop();
		t++;
		p[u]=n+1-t;
		for (auto g : gt[u])
		{
			oudeg[g]--;
			if (!oudeg[g]) cur.push(g);
		}
	}
	for (i=1;i<=n;i++) cout<<p[i]<<' ';
}
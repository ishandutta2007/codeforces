// Problem: C. Tournament
// Contest: Codeforces - Codeforces Round #443 (Div. 1)
// URL: https://codeforces.com/problemset/problem/878/C
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
const int MAXN=200007;
struct edge{
	int v,nxt;
}e[MAXN<<1];
int n,cnt;
int head[MAXN],a[MAXN];
ll dp[MAXN][2];
vector<pii(int)>ans[MAXN][2];
void add (int u,int v)
{
	e[++cnt].v=v,e[cnt].nxt=head[u],head[u]=cnt;
}
void dfs1 (int u,int ff)
{
	ll sum=0,Min=1e18;
	for (int i=head[u];i!=0;i=e[i].nxt)
		if (e[i].v!=ff)
		{
			dfs1 (e[i].v,u);
			sum+=dp[e[i].v][0];
			Min=min (Min,dp[e[i].v][1]-dp[e[i].v][0]);
		}
	int tot=0;
	for (int i=head[u];i!=0;i=e[i].nxt)
		if (e[i].v!=ff&&dp[e[i].v][1]-dp[e[i].v][0]==Min)
			ans[u][1].push_back (pii(int) (e[i].v,1)),tot++;
	for (int i=head[u];i!=0;i=e[i].nxt)
		if (e[i].v!=ff&&(tot!=1||dp[e[i].v][1]-dp[e[i].v][0]!=Min))
			ans[u][1].push_back (pii(int) (e[i].v,0));
	if (Min==1e18)
	{
		dp[u][0]=a[u];
		ans[u][0].push_back (pii(int) (u,-1));
		dp[u][1]=0;
		return;
	}
	dp[u][1]=sum+Min;
	if (sum<=dp[u][1]+a[u])
	{
		dp[u][0]=sum;
		for (int i=head[u];i!=0;i=e[i].nxt)
			if (e[i].v!=ff)
				ans[u][0].push_back (pii(int) (e[i].v,0));
    }
	if (dp[u][1]+a[u]<=sum)
	{
		dp[u][0]=dp[u][1]+a[u];
		ans[u][0].push_back (pii(int) (u,1));
		ans[u][0].push_back (pii(int) (u,-1));
	}
}
bool used[MAXN][2];
set<int>Ans;
void dfs2 (pii(int) u)
{
	if (u.second==-1) return Ans.insert (u.first),void ();
	if (used[u.first][u.second]) return;
	used[u.first][u.second]=1;
	for (pii(int) nxt:ans[u.first][u.second]) dfs2 (nxt);
}
int main()
{
    fio;
    cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		add (u,v),add (v,u);
	}
	dfs1 (1,0);
	dfs2 (pii(int) (1,0));
	cout<<dp[1][0]<<' '<<Ans.size ()<<endl;
	for (int i:Ans) cout<<i<<' ';
}
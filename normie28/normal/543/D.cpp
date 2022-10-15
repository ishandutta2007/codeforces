
// Problem : D. Road Improvement
// Contest : Codeforces - Codeforces Round #302 (Div. 1)
// URL : https://codeforces.com/contest/543/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
#define MOD (ll(1000000007))
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
ll dp[200001],dpup[200001];
ll res[200001];
vector<ll> gt[200001];
ll n,m,i,j,k,t,t1,u,v,a,b;
void dfs(ll x)
{
	dp[x]=1;
	for (auto g : gt[x])
	{
		dfs(g);
		dp[x]*=dp[g];
		dp[x]%=MOD;
	}
	dp[x]++;
	dp[x]%=MOD;
}
void dfs1(ll x)
{
	res[x]=(dp[x]+MOD-1)%MOD*dpup[x]%MOD;
	vector<ll> fl,fr;
	ll u=1;
	for (int i=0;i<gt[x].size();i++)
	{
		u*=dp[gt[x][i]];
		u%=MOD;
		fl.push_back(u);
	}
	u=1;
	for (int i=gt[x].size()-1;i>=0;i--)
	{
		u*=dp[gt[x][i]];
		u%=MOD;
		fr.push_back(u);
	}
	reverse(fr.begin(),fr.end());
	for (int i=0;i<gt[x].size();i++)
	{
		u=1;
		if (i) u=(u*fl[i-1])%MOD;
		if (i+1<gt[x].size()) 
		u=(u*fr[i+1])%MOD;
		u=u*dpup[x];
		u++;
		u%=MOD;
		dpup[gt[x][i]]=u;
		dfs1(gt[x][i]);
	}
}
int main()
{
	fio;
	dpup[1]=1;
	cin>>n;
	for (i=2;i<=n;i++)
	{
		cin>>u;
		gt[u].push_back(i);
	}
	dfs(1);
	dfs1(1);
	for (i=1;i<=n;i++) cout<<res[i]<<' ';
}
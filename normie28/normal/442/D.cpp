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
#define FILE_IN "treecoloring.inp"
#define FILE_OUT "treecoloring.out"
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
int par[1000011];
int dp[1000011];
vector<pii(int)> bruh[1000011];
int n,m,i,j,k,t,t1,u,v,a,b;
void upd(int x)
{
	int a=par[x];
	for (int i=0;i<bruh[a].size();i++) if (bruh[a][i].se==x)
	{
		bruh[a].erase(bruh[a].begin()+i);
		break;
	}
	bruh[a].push_back({dp[x],x});
	sort(bruh[a].begin(),bruh[a].end(),[](pii(int) a, pii(int) b){
		return (a.fi>b.fi);
	});
	while(bruh[a].size()>2) bruh[a].pop_back();
	int b=max(bruh[a][0].fi,bruh[a][1].fi+1);
	if (b>dp[a])
	{
		dp[a]=b;
		if (a>1) upd(a);
	}
}
int main()
{
   // ofile;
	fio;
	cin>>n;
	for (i=1;i<=n+1;i++) bruh[i].emplace_back(0,0);
	for (i=1;i<=n+1;i++) bruh[i].emplace_back(0,-1);
	for (i=2;i<=n+1;i++)
	{
		cin>>par[i];
		dp[i]=1;
		upd(i);
		cout<<bruh[1][0].fi<<' ';
	}
}
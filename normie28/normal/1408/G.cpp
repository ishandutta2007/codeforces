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
vector<ll> buc[200001],dp[200001],cur;
ll par[200001],cnt[200001];
ll n,m,i,j,k,t,u,v,a,b;
ll arr[1501][1501];
vector<piii(ll)> edges;
int main()
{
	fio;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++) cin>>arr[i][j];
		par[i]=i;
		buc[i].push_back(i);
		dp[i].push_back(1);
	}
	for (i=1;i<=n;i++)
	for (j=i+1;j<=n;j++) edges.push_back({arr[i][j],{i,j}});
	sort(edges.begin(),edges.end(),[](piii(ll) a, piii(ll) b){
		return (a.p1<b.p1);
	});
	for (piii(ll) g : edges)
	{
		u=par[g.p2];
		v=par[g.p3];
		if (u==v) cnt[u]++;
		else
		{
			cur.clear();
			for (i=0;i<buc[u].size()+buc[v].size();i++) cur.push_back(0);
			for (i=0;i<buc[u].size();i++) for (j=0;j<buc[v].size();j++) 
			{
				cur[i+j+1]+=dp[u][i]*dp[v][j];
				cur[i+j+1]%=MOD;
			}
			dp[u]=cur;
			for (int g : buc[v])
			{
				buc[u].push_back(g);
				par[g]=u;
			}
			buc[v].clear();
			cnt[u]+=cnt[v]+1;
		}
		if (cnt[u]==buc[u].size()*(buc[u].size()-1)/2) {dp[u][0]++; dp[u][0]%=MOD;}
	}
	for (i=1;i<=n;i++) if (buc[i].size()) break;
	for (int g : dp[i]) cout<<g<<' ';
}

// Problem : F. AND Segments
// Contest : Codeforces - Educational Codeforces Round 84 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1327/problem/F
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
vector<piii(ll)> req;
vector<piii(ll)> red;
ll n,m,i,j,k,t,t1,u,v,a,b,res=1;
ll dp[500001];
ll pre[500001];
ll cur[500001];
ll act[500001];
ll maxx[500001];
ll work()
{
	ll i,j,k;
	for (i=0;i<=n;i++)
	{
		dp[i]=0;
		pre[i]=0;
		cur[i]=0;
		act[i]=0;
		maxx[i]=-1;
	}
	for (i=0;i<m;i++) if (red[i].p3)
	{
//		cout<<1<<' '<<red[i].p1<<' '<<red[i].p2<<endl;
		cur[red[i].p1]++;
		if (red[i].p2<n) cur[red[i].p2+1]--;
	}
	else
	{
//		cout<<0<<' '<<red[i].p1<<' '<<red[i].p2<<endl;
	}
	k=0;
	for (i=1;i<=n;i++)
	{
		k+=cur[i];
		if (k) act[i]=act[i-1];
		else act[i]=act[i-1]+1;
	}
	//for (i=0;i<=n;i++) cout<<act[i]<<' ';
	//cout<<endl;
	dp[0]=1;
	pre[0]=1;
	for (i=0;i<m;i++) if (!(red[i].p3))
	{
		if (act[red[i].p2]==act[red[i].p1-1]) return 0;
		else
		{
			maxx[act[red[i].p2]]=max(maxx[act[red[i].p2]],act[red[i].p1-1]);
		}
	}
//	for (i=0;i<=act[n];i++) cout<<maxx[i]<<' ';
//	cout<<endl;
	k=-1;
	for (i=1;i<=act[n];i++)
	{
		k=max(k,maxx[i]);
		if (k==-1) dp[i]=pre[i-1]+1;
		else if (k==0) dp[i]=pre[i-1]; else dp[i]=pre[i-1]-pre[k-1]+MOD;
		dp[i]%=MOD;
		pre[i]=pre[i-1]+dp[i];
		pre[i]%=MOD;
	}
	return dp[act[n]];
}
int main()
{
	fio;
	cin>>n>>k>>m;
	for (i=0;i<m;i++)
	{
		cin>>u>>v>>a;
		req.push_back({u,{v,a}});
	}
	for (i=0;i<k;i++)
	{
		red.clear();
		for (j=0;j<m;j++)
		{
			red.push_back({req[j].p1,{req[j].p2,((req[j].p3)>>i)%2}});
		}
		u=work();
	//	cout<<u<<endl;
		res*=u;
		res%=MOD;
	}
	cout<<res;
}
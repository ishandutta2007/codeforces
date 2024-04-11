
// Problem : E2. Rotate Columns (hard version)
// Contest : Codeforces - Codeforces Round #584 - Dasha Code Championship - Elimination Round (rated, open for everyone, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1209/problem/E2
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
int dp[4096][13];
int maxx[4096][12];
int col[2000][12];
vector<int> subm[4096];
vector<pii(int)> lis;
int n,m,i,j,k,t,t1,u,v,a,b,f;
int main()
{
	fio;
	for (i=0;i<4096;i++) for (j=0;j<4096;j++)
	if (!(i&j)) subm[i].push_back(j);
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n>>m;
		for (i=0;i<n;i++) for (j=0;j<m;j++) cin>>col[j][i];
		lis.clear();
		for (i=0;i<m;i++)
		{
			u=0;
			for (j=0;j<n;j++) u=max(u,col[i][j]);
			lis.push_back({i,u});
		}
		sort(lis.begin(),lis.end(),[](pii(int) a, pii(int) b){
			return (a.se>b.se);
		});
		f=min(m,n);
		for (i=0;i<f;i++)
		{
			for (a=0;a<(1<<n);a++)
			{
				maxx[a][i]=0;
				for (j=0;j<n;j++) if (a&(1<<j)) maxx[a][i]+=col[lis[i].fi][j];
			}
			for (j=0;j<n;j++) for (a=0;a<(1<<n);a++)
			{
				b=a;
				if (b%2) {b>>=1;b+=1<<(n-1);}
				else b>>=1;
				maxx[a][i]=max(maxx[a][i],maxx[b][i]);
			}
		//	cout<<lis[i].fi<<endl;
			//for (a=0;a<(1<<n);a++) cout<<maxx[a][i]<<' ';
		//	cout<<endl;
		}
		for (i=1;i<=f;i++)
		{
		 for (j=0;j<(1<<n);j++)
		{
			dp[j][i]=0;
		}
		 for (j=0;j<(1<<n);j++)
		{
			for (auto g : subm[j]) if (j+g<(1<<n)) dp[j+g][i]=max(dp[j+g][i],dp[j][i-1]+maxx[g][i-1]);
		}
	//	 for (j=0;j<(1<<n);j++)
	//	{
	//		cout<<dp[j][i]<<' ';
	//	}
	//	cout<<endl;
		}
		cout<<dp[(1<<n)-1][f]<<endl;
	}
}
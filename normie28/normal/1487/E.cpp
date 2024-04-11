
// Problem : E. Cheap Dinner
// Contest : Codeforces - Educational Codeforces Round 104 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1487/problem/E
// Memory Limit : 512 MB
// Time Limit : 4000 ms
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
ll minn[5][200001][18];
ll cost[5][200001];
ll n[5];
ll m[5];
ll lg2[200001];
vector<ll> banlist[5][200001];
ll i,j,k,t,t1,u,v,a,b,l,r;
int main()
{
	fio;
	lg2[1]=0;
	for (i=2;i<=200000;i++) lg2[i]=lg2[i/2]+1;
	for (i=1;i<=4;i++) cin>>n[i];
	
	for (i=1;i<=4;i++) 
	{
		for (j=1;j<=n[i];j++) cin>>cost[i][j];
		
	}
	for (i=1;i<=3;i++)
	{
		cin>>m[i];
		for (j=1;j<=m[i];j++)
		{
			cin>>u>>v;
			banlist[i][u].push_back(v);
		}
	}
	
	for (j=1;j<=n[4];j++) minn[4][j][0]=cost[4][j];
	for (t=3;t>=1;t--)
	{
		for (i=1;i<18;i++)
		{
			for (j=1;j<=n[t+1];j++)
			{
				minn[t+1][j][i]=minn[t+1][j][i-1];
				if (j+(1<<(i-1))<=n[t+1])
				minn[t+1][j][i]=min(minn[t+1][j][i],minn[t+1][j+(1<<(i-1))][i-1]);
			}
		}
		for (i=1;i<=n[t];i++)
		{
			minn[t][i][0]=1e18;
			sort(banlist[t][i].begin(),banlist[t][i].end());
			if (banlist[t][i].size())
			{
				for (j=0;j+1<banlist[t][i].size();j++)
				{
					l=banlist[t][i][j]+1;
					r=banlist[t][i][j+1]-1;
					if (l<=r)
					{
						u=lg2[r-l+1];
						minn[t][i][0]=min(minn[t][i][0],minn[t+1][l][u]);
						minn[t][i][0]=min(minn[t][i][0],minn[t+1][r-(1<<u)+1][u]);
					}
				}
					l=1;
					r=banlist[t][i][0]-1;
					if (l<=r)
					{
						u=lg2[r-l+1];
						minn[t][i][0]=min(minn[t][i][0],minn[t+1][l][u]);
						minn[t][i][0]=min(minn[t][i][0],minn[t+1][r-(1<<u)+1][u]);
					}
					
					l=banlist[t][i][banlist[t][i].size()-1]+1;
					r=n[t+1];
					if (l<=r)
					{
						u=lg2[r-l+1];
						minn[t][i][0]=min(minn[t][i][0],minn[t+1][l][u]);
						minn[t][i][0]=min(minn[t][i][0],minn[t+1][r-(1<<u)+1][u]);
					}
			}
			else
			{
				l=1;
				r=n[t+1];
					if (l<=r)
					{
						u=lg2[r-l+1];
						minn[t][i][0]=min(minn[t][i][0],minn[t+1][l][u]);
						minn[t][i][0]=min(minn[t][i][0],minn[t+1][r-(1<<u)+1][u]);
					}
			}
			minn[t][i][0]+=cost[t][i];
		}
	}
	for (i=1;i<=4;i++)
	{
	//	cout<<n[i]<<endl;
	//	for (j=1;j<=n[i];j++) cout<<minn[i][j][0]<<" ";
	//	cout<<endl;
	}
	a=1e18;
	for (i=1;i<=n[1];i++) a=min(a,minn[1][i][0]);
	if (a>=1e17) cout<<-1; else cout<<a;
}
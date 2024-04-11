
// Problem : D. Greg and Caves
// Contest : Codeforces - Codeforces Round #179 (Div. 1)
// URL : https://codeforces.com/problemset/problem/295/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
	const ll p=1000000007;
	const int N=2010;
	int n,m;
	ll res,dp[N][N],sum[N][N],sumk[N][N];
	
	inline void Mod(ll &x) {x=(x>=p?x-p:x);}
	
int main()
	{
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			dp[1][i]=1;
			if(i!=1)
			{
				sum[1][i]=sum[1][i-1]+1;
				sumk[1][i]=sumk[1][i-1]+i;
			}
		}
		for(int i=2;i<=n;i++)
		{
			dp[i][1]=1;
			for(int j=2;j<=m;j++)
			{
				Mod(dp[i][j]=(sum[i-1][j]*(j+1)%p-sumk[i-1][j]+1+p));
				Mod(sum[i][j]=sum[i][j-1]+dp[i][j]);
				Mod(sumk[i][j]=sumk[i][j-1]+dp[i][j]*j%p);
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=2;j<=m;j++)
				Mod(res+=(dp[i][j]-dp[i-1][j]+p)*dp[n-i+1][j]%p*(m-j+1)%p);
				cout<<res<<endl;
	}
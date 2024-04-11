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
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,decltype(cmp),rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;


int a[1010][1010],tmpa[1010][1010];
long long f[1010][1010],tmpf[1010][1010],sum[1010][1010][7];
int n,m,K;
void rotate()
{
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)tmpa[i][j]=a[i][j];
	}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			a[m-j+1][i]=tmpa[i][j];
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			tmpf[i][j]=f[i][j];
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			f[m-j+1][i]=tmpf[i][j];
	swap(n, m);
}
int main()
{
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int T=1; T<=4; T++)
	{
		int mx=max(n, m);
		for (int i=1; i<=mx; i++)
			for (int j=1; j<=mx; j++)
				for (int k=1; k<=5; ++k)
					sum[i][j][k]=0;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
			{
				sum[i][j][1]=sum[i-1][j][1]+a[i][j];
				long long up=(i-1>=K? sum[i-1-K][j][1]:0);
				sum[i][j][2]=sum[i-1][j][2]-(sum[i-1][j][1]-up)+1ll*K*a[i][j];
				sum[i][j][3]=sum[i-1][j+1][3]+a[i][j];
				up=(i>=K? sum[i-K][j][3]:0);
				long long L;
				if (j-1>=K) L=sum[i][j-K][3];
				else
					L=(i-(K-(j-1))>0? sum[i-(K-(j-1))][1][3]:0);
				sum[i][j][4]=sum[i][j-1][4]-(L-up)+sum[i][j][1]-(i>=K? sum[i-K][j][1]:0);
				sum[i][j][5]=sum[i][j-1][5]-sum[i][j-1][4]+sum[i][j][2];
			}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				f[i][j]+=sum[i][j][5]-sum[i][j][2];
			}
		}
		rotate();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)f[i][j]+=a[i][j]*K;
	}
	int pos1=0,pos2=0;
	for(int i=K;i<=n-K+1;i++)
	{
		for(int j=K;j<=m-K+1;j++)
		{
			if(!pos1||f[i][j]>f[pos1][pos2])pos1=i,pos2=j;
		}
	}
	printf("%d %d\n",pos1,pos2);
	return 0;
}
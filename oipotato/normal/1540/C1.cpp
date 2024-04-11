#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cassert>
#include<set>
#include<map>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int MOD=(int)1e9+7;
const int N=110;
int f[N][N*N],ssb[N],sc[N],b[N],c[N],n,q;
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&c[i]),sc[i]=sc[i-1]+c[i];
	rep(i,n-1)scanf("%d",&b[i+1]),ssb[i+1]=ssb[i]+b[i+1];
	rep(i,n)ssb[i]+=ssb[i-1];
	scanf("%d",&q);
	rep(Q,q)
	{
		int x;scanf("%d",&x);
		rep(i,n)
		{
			if(i==1)for(int j=max(0,x);j<=c[1];j++)f[1][j]=1;
			else
			{
				rep(j,sc[i])(f[i-1][j]+=f[i-1][j-1])%=MOD;
				for(int j=max(0,i*x+ssb[i]);j<=sc[i];j++)f[i][j]=(f[i-1][j]-(j-c[i]-1>=0?f[i-1][j-c[i]-1]:0)+MOD)%MOD;
			}
		}
		int ans=0;
		for(int i=0;i<=sc[n];i++)(ans+=f[n][i])%=MOD;
		printf("%d\n",ans);
	}
    return 0;
}
#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;
const int maxt=50005,maxn=33;
bool dp[maxn][maxn][maxt],use[maxn][maxn][maxt];
unsigned short pre[maxn][maxn][maxt];
int n,a[maxt],b[maxn],lg[maxn],id[maxt],mod;
int main()
{
	scanf("%d%d",&n,&mod);
	int cnt=0;
	lg[0]=1;
	for(int i=1;i<=n;i++)lg[i]=lg[i/10]*10%mod;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		if(a[i]<=31)
		{
			id[++cnt]=i;
			b[cnt]=a[i];
		}
	}
	n=min(n,31);
	dp[0][0][0]=true;
	for(int i=1;i<=n;i++)
	{
		dp[i][b[i]][b[i]%mod]=true;
		use[i][b[i]][b[i]%mod]=true;
		for(int j=0;j<=31;j++)
			for(int k=0;k<=mod;k++)
			{
				if(dp[i-1][j][k])
				{
					dp[i][j][k]=true;
					dp[i][j^b[i]][(k*lg[b[i]]+b[i])%mod]=true;
					use[i][j^b[i]][(k*lg[b[i]]+b[i])%mod]=true;
					pre[i][j^b[i]][(k*lg[b[i]]+b[i])%mod]=k;
				}
			}
	}
	int x=n,y=0,z=0;
	int ans[maxn],tot=0;
	while(x!=0)
	{
		if(use[x][y][z])
		{
			ans[tot++]=id[x];
			y^=b[x];
			z=pre[x][y^b[x]][z];
		}
		x--;
	}
	if(tot==0)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	printf("%d\n",tot);
	for(int i=tot-1;i>=0;i--)
		printf("%d ",ans[i]);
	return 0;
}
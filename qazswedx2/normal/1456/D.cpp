#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,dp[5005][5005];
ll f[5005],a[5005][2];
ll F(ll x)
{
	return x>=0?x:-x;
}
ll getdis(int x,int y)
{
	return F(a[x][1]-a[y][1]);
}
int main()
{
	memset(f,0x3f,sizeof(f));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i][0],&a[i][1]);
	f[0]=0;
	for(int i=0;i<n;i++)
	{
		if(f[i]<=a[i][0])
		{
			f[i+1]=min(f[i+1],max(f[i]+getdis(i,i+1),a[i][0]));
			for(int j=i+2;j<=n;j++)
				if(max(f[i]+getdis(i,j),a[i][0])+getdis(j,i+1)<=a[i+1][0])
					dp[i+1][j]=1;
		}
		for(int j=i+2;j<=n;j++)
			if(dp[i][j]&&getdis(i,i+1)<=a[i+1][0]-a[i][0])
				dp[i+1][j]=1;
		if(dp[i][i+1]&&i+2<=n)
		{
			f[i+2]=min(f[i+2],max(a[i][0]+getdis(i,i+2),a[i+1][0]));
			for(int j=i+3;j<=n;j++)
				if(max(a[i][0]+getdis(i,j),a[i+1][0])+getdis(j,i+2)<=a[i+2][0])
					dp[i+2][j]=1;
		}
	}
	if(dp[n-1][n]||f[n]<=a[n][0])
		printf("YES\n");
	else printf("NO\n");
	return 0;
}
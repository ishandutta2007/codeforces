#include<cstdio>
#include<cstring>

int n,a[2002],f[2002][2002],g[2002][2002],ans1[2002][2002][2],ans2[2002][2002][2],t,ma0,ma1,ans,s[2002];

int getmax(int a,int b) {return a<b?b:a;}

int main()
{
	scanf("%d",&n); s[0]=0;
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),a[i]--,s[i]=s[i-1]+a[i];
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	memset(ans1,0,sizeof(ans1));
	memset(ans2,0,sizeof(ans2));
	for (int i=1; i<=n; i++)
	{
		ma0=0; ma1=0;
		for (int j=i; j<=n; j++)
		{
			if (a[j]==1) f[i][j]=getmax(ma0,ma1)+1,ma1=f[i][j];
			else f[i][j]=ma0+1,ma0=f[i][j];
			ans1[i][j][0]=ma0; ans1[i][j][1]=ma1;
		}
	}
	for (int i=1; i<=n/2; i++) t=a[i],a[i]=a[n-i+1],a[n-i+1]=t;
	for (int i=1; i<=n; i++)
	{
		ma0=0; ma1=0;
		for (int j=i; j<=n; j++)
		{
			if (a[j]==1) g[i][j]=getmax(ma0,ma1)+1,ma1=g[i][j];
			else g[i][j]=ma0+1,ma0=g[i][j];
			ans2[i][j][0]=ma0; ans2[i][j][1]=ma1;
		}
	}
	ans=0;
	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j++)
		{
			ans=getmax(ans,ans1[1][i-1][0]+ans2[n-j+1][n-i+1][1]+s[n]-s[j]);
			ans=getmax(ans,ans1[1][i-1][0]+ans2[n-j+1][n-i+1][0]+ans1[j+1][n][1]);
			ans=getmax(ans,ans1[1][i-1][0]+ans2[n-j+1][n-i+1][0]+ans1[j+1][n][0]);
			ans=getmax(ans,ans1[1][i-1][1]+s[n]-s[i-1]);
		}
	printf("%d\n",ans);
	return 0;
}
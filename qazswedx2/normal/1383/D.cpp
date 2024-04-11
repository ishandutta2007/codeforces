#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,a[305][305],ans[305][305],rt,ct,ft,gt,nwf,nwg;
int f[100005][2],g[100005][2],vis[100005];
vector<int> r[305],c[305];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	{
		int mx=-1;
		for(int j=1;j<=m;j++)
			if(a[i][j]>mx)
				mx=a[i][j];
		vis[mx]|=1;
	}
	for(int i=1;i<=m;i++)
	{
		int mx=-1;
		for(int j=1;j<=n;j++)
			if(a[j][i]>mx)
				mx=a[j][i];
		vis[mx]|=2;
	}
	ft=gt=0;
	nwf=nwg=1;
	for(int i=n*m;i>=0;i--)
	{
		if(vis[i]==3)
		{
			ct++;
			rt++;
			ans[rt][ct]=i;
			for(int j=ct-1;j;j--)
			{
				f[++ft][0]=rt;
				f[ft][1]=j;
			}
			for(int j=rt-1;j;j--)
			{
				g[++gt][0]=j;
				g[gt][1]=ct;
			}
		}
		else if(vis[i]==2)
		{
			ct++;
			ans[rt][ct]=i;
			for(int j=rt-1;j;j--)
			{
				g[++gt][0]=j;
				g[gt][1]=ct;
			}
		}
		else if(vis[i]==1)
		{
			rt++;
			ans[rt][ct]=i;
			for(int j=ct-1;j;j--)
			{
				f[++ft][0]=rt;
				f[ft][1]=j;
			}
		}
		else
		{
			if(nwf<=ft)
			{
				ans[f[nwf][0]][f[nwf][1]]=i;
				nwf++;
			}
			else
			{
				ans[g[nwg][0]][g[nwg][1]]=i;
				nwg++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}
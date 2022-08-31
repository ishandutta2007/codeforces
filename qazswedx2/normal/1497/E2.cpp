#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m,f[200005][22],a[10000005],pn=1e7,pt,p[10000005],prime[2000005];
int c[200005],b[105],bt,vis[10000005];
int main()
{
	a[1]=1;
	for(int i=2;i<=pn;i++)
	{
		if(!p[i]) prime[++pt]=i,a[i]=i;
		for(int j=1;j<=pt&&i*prime[j]<=pn;j++)
		{
			int u=i*prime[j];
			p[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				if(a[i]%prime[j]) a[u]=a[i]*prime[j];
				else a[u]=a[i]/prime[j];
				break;
			}
			a[u]=a[i]*prime[j];
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&c[i]);
			c[i]=a[c[i]];
		}
		bt=1;
		b[1]=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[c[i]])
			{
				int u=vis[c[i]],id=bt+1;
				for(int j=1;j<=bt;j++)
					if(b[j]<=u)
					{
						id=j;
						break;
					}
				for(int k=bt+1;k>id;k--)
					b[k]=b[k-1];
				b[id]=u;
				bt=min(bt+1,m+1);
			}
			vis[c[i]]=i;
			for(int j=0;j<=m;j++)
			{
				f[i][j]=1e9;
				for(int k=1;k<=min(j+1,bt);k++)
				{
					int l=b[k],u=j-k+1;
					f[i][j]=min(f[i][j],f[l][u]+1);
				}
			}
		}
		for(int i=1;i<=n;i++)
			vis[c[i]]=0;
		printf("%d\n",f[n][m]);
	}
	return 0;
}
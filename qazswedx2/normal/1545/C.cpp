#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int T,n,a[1005][1005],vis[1005],c[1005],tans[1005],t;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		t=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		int ans=1;
		while(1)
		{
			int id=-1;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
					c[j]=0;
				for(int j=1;j<=2*n;j++)
					if(!vis[j])
						c[a[j][i]]++;
				for(int j=1;j<=n;j++)
					if(c[j]==1)
					{
						for(int k=1;k<=2*n;k++)
							if(!vis[k]&&a[k][i]==j)
							{
								id=k;
								break;
							}
						break;
					}
				if(id!=-1) break;
			}
		//	printf("id=%d\n",id);
			if(id==-1)
			{
				for(int i=1;i<=2*n;i++)
					if(!vis[i])
					{
						id=i;
						ans=ans*2%mod;
						break;
					}
			}
			if(id==-1) break;
			for(int i=1;i<=2*n;i++)
				if(!vis[i])
				{
					int fl=0;
					for(int j=1;j<=n;j++)
						if(a[i][j]==a[id][j])
						{
							fl=1;
							break;
						}
					if(fl) vis[i]=1;
				}
			tans[++t]=id;
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			printf("%d ",tans[i]);
		printf("\n");
	}
	return 0;
}
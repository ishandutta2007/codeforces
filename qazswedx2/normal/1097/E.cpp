#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int t,n,a[100005],tans[100005],tt,f[100005],ft;
int b[100005],bt,g[100005],gt,pre[100005],ppre[100005],vis[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		tt=ft=gt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			vis[i]=0;
		int m=n;
		while(1)
		{
		/*	printf("n=%d\n",n);
			for(int i=1;i<=n;i++)
				printf("%d ",a[i]);
			printf("\n");*/
			for(int i=1;i<=m;i++)
				pre[i]=ppre[i]=0;
			gt=0;
			for(int i=1;i<=n;i++)
			{
				int u=lower_bound(g+1,g+gt+1,a[i])-g;
				if(u<=gt) pre[a[i]]=g[u];
				ppre[a[i]]=g[u-1];
				g[u]=a[i];
				if(u>gt) gt++;
			}
			if(1ll*gt*(gt+1)/2<=n)
			{
				for(int i=1;i<=gt;i++)
				{
					f[++ft]=tt+1;
					int nw=g[i];
					while(nw)
					{
						tans[++tt]=nw;
						nw=pre[nw];
					}
					reverse(tans+f[ft],tans+tt+1);
				}
				break;
			}
			f[++ft]=tt+1;
			int nw=g[gt];
			while(nw)
			{
				tans[++tt]=nw;
				vis[nw]=1;
				nw=ppre[nw];
			}
			reverse(tans+f[ft],tans+tt+1);
			bt=0;
			for(int i=1;i<=n;i++)
				if(!vis[a[i]])
					b[++bt]=a[i];
			n=bt;
			for(int i=1;i<=n;i++)
				a[i]=b[i];
			if(!n) break;
		}
		printf("%d\n",ft);
		f[ft+1]=tt+1;
		for(int i=1;i<=ft;i++)
		{
			printf("%d ",f[i+1]-f[i]);
			for(int j=f[i];j<f[i+1];j++)
				printf("%d ",tans[j]);
			printf("\n");
		}
	}
	return 0;
}
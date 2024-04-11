#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,f[100005],ft,g[100005][2],h[100005],a[100005],b[100005],vis[100005],pre[100005];
int len[100005],c[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	sort(b+1,b+m+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=-1)
		{
			int u=lower_bound(f+1,f+ft+1,a[i])-f;
			f[u]=a[i];
			h[u]=i;
			pre[i]=h[u-1];
			len[i]=u;
			if(u==ft+1) ft++;
		}
		else
		{
			int nw=ft+1;
			for(int j=m;j>=1;j--)
			{
				while(nw>1&&f[nw-1]>=b[j]) nw--;
				if(f[nw]==b[j]) continue;
				if(nw>ft) ft=nw;
				f[nw]=b[j];
				h[nw]=i;
			}
		}
	}
	int nw=h[ft];
	if(a[nw]==-1)
	{
		c[nw]=b[m];
		vis[m]=1;
	}
	for(int i=ft;i>1;i--)
	{
	//	printf("i=%d,nw=%d,a=%d,c=%d\n",i,nw,a[nw],c[nw]);
		if(a[nw]!=-1)
		{
			int id=pre[nw];
			if(a[id]==-1)
			{
				int u=lower_bound(b+1,b+m+1,a[nw])-b-1;
				c[id]=b[u];
				vis[u]=1;
			}
			nw=id;
			continue;
		}
		int id=0;
		for(int j=1;j<nw;j++)
			if(a[j]!=-1&&len[j]==i-1&&a[j]<c[nw])
			{
				id=j;
				break;
			}
		if(!id)
		{
			int u=lower_bound(b+1,b+m+1,c[nw])-b-1;
			for(int j=nw-1;j>0;j--)
				if(a[j]==-1)
				{
					id=j;
					break;
				}
		//	printf("id=%d,u=%d\n",id,u);
			c[id]=b[u];
			vis[u]=1;
		}
		nw=id;
	}
	int bnw=1;
	for(int i=1;i<=n;i++)
		if(a[i]==-1)
		{
		//	printf("i=%d,a=%d,c=%d\n",i,a[i],c[i]);
			if(c[i]) a[i]=c[i];
			else
			{
				while(vis[bnw]) bnw++;
				a[i]=b[bnw];
				bnw++;
			}
		}
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}
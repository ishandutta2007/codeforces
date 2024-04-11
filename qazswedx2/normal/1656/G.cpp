#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,a[1000005],f[1000005],c[1000005][2],vis[1000005],ct;
int p[1000005],rp[1000005];
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void link(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	f[x]=y;
}
int main()
{
//	freopen("G.in","r",stdin);
//	freopen("G.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0;i<=n+1;i++)
		{
			vis[i]=p[i]=0;
			f[i]=i;
		}
		ct=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			if(vis[a[i]])
			{
				ct++;
				c[ct][0]=vis[a[i]];
				c[ct][1]=i;
				vis[a[i]]=0;
			}
			else vis[a[i]]=i;
		}
		if(ct!=n/2)
		{
			printf("NO\n");
			continue;
		}
	//	printf("---\n");
		for(int i=1;i<=ct;i++)
		{
			p[c[i][0]]=i;
			p[c[i][1]]=n-i+1;
		}
		/*for(int i=1;i<=n;i++)
			printf("%d ",p[i]);
		printf("\n");*/
		for(int i=1;i<=n;i++)
			if(!p[i]) p[i]=(n+1)/2;
		for(int i=1;i<=n;i++)
			link(i,p[i]);
		for(int i=0;i<=n+1;i++)
			vis[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[a[i]])
			{
				int v=vis[a[i]];
				if(find(v)!=find(i))
				{
					swap(p[v],p[i]);
					link(i,v);
				}
			}
			vis[a[i]]=i;
		}
		for(int i=1;i<=n;i++)
			rp[p[i]]=i;
		ct=0;
		for(int i=1;i<=n/2;i++)
		{
			c[++ct][0]=rp[i];
			c[ct][1]=rp[n-i+1];
		}
		for(int i=2;i<=ct;i++)
		{
			int u=c[i][0],v=c[i][1];
			int x=c[i-1][0],y=c[i-1][1];
			if(find(u)!=find(x))
			{
				int pu=p[u],pv=p[v],px=p[x],py=p[y];
			/*	printf("u=%d,v=%d,x=%d,y=%d\n",u,v,x,y);
				for(int j=1;j<=n;j++)
					printf("%d ",p[j]);
				printf("\n"); */
				p[u]=px;
				p[v]=py;
				p[x]=pv;
				p[y]=pu;
			/*	for(int j=1;j<=n;j++)
					printf("%d ",p[j]);
				printf("\n"); */
				link(u,x);
			}
		}
		int fl=1;
		for(int i=2;i<=n;i++)
			if(find(i)!=find(i-1)) fl=0;
		if(!fl) printf("NO\n");
		else 
		{
			printf("YES\n");
			for(int i=1;i<=n;i++)
				rp[p[i]]=i;
			for(int i=1;i<=n;i++)
				printf("%d ",rp[i]);
			printf("\n");
			
			for(int i=1;i<=n;i++)
				if(a[rp[i]]!=a[rp[n-i+1]])
				{
					for(int j=1;j<=n;j++)	
						fprintf(stderr,"%d ",a[j]);
					printf("\n");
					fprintf(stderr,"error1\n");
					return 5;
				}
			int u=1,nw=n;
			for(int i=1;i<=n;i++)
				vis[i]=0;
			while(nw--)
			{
				if(vis[u])
				{
					fprintf(stderr,"error2\n");
					return 5;
				}
				vis[u]=1;
				u=rp[u];
			}
		/*	
			printf("a=");
			for(int i=1;i<=n;i++)
			{
				printf("%d ",a[rp[i]]);
			}
			printf("\n");
			int u=1,nw=n;
			while(nw--) printf("%d ",u),u=rp[u];
			printf("\n");*/
		}
	}
}
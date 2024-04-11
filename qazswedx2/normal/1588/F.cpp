#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int B=450;
ll h[500005],c[500005];
int n,m,a[500005],p[500005],q[500005][3],f[500005],b[500005],bt,d[500005],dt,rb[500005],rp[500005];
int g[2005][2005],vis[500005],ct;
ll sum[500005];
vector<int> val[500005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		h[i]=a[i];
	for(int i=1;i<=n;i++)
		c[i]=c[i-1]+h[i];
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&q[i][0],&q[i][1],&q[i][2]);
	for(int i=1;(i-1)*B+1<=m;i++)
	{
		int l=(i-1)*B+1,r=min(i*B,m);
		bt=0;
		for(int j=l;j<=r;j++)
			if(q[j][0]==3)
			{
				b[++bt]=q[j][1];
				b[++bt]=q[j][2];
			}
		for(int j=1;j<=n;j++)
			f[j]=0;
		for(int j=1;j<=n;j++)
			rp[p[j]]=j;
		for(int j=1;j<=bt;j++)
			f[b[j]]=b[j];
		for(int j=1;j<=bt;j++)
		{
			int v=rp[b[j]];
			while(!f[v])
			{
				f[v]=b[j];
				v=rp[v];
			}
		}
		for(int j=1;j<=n;j++)
			if(!f[j])
			{
				int v=j;
				while(!f[v])
				{
					f[v]=j;
					v=p[v];
				}
			}
		for(int j=l;j<=r;j++)
			if(q[j][0]==2) b[++bt]=f[q[j][1]];
		sort(b+1,b+bt+1);
		bt=unique(b+1,b+bt+1)-b-1;
		for(int j=1;j<=n;j++)
			rb[j]=0;
		for(int j=1;j<=bt;j++)
			rb[b[j]]=j;
		dt=0;
		for(int j=l;j<=r;j++)
			if(q[j][0]==1)
			{
				d[++dt]=q[j][1]-1;
				d[++dt]=q[j][2];
			}
		sort(d+1,d+dt+1);
		dt=unique(d+1,d+dt+1)-d-1;
		for(int j=1;j<=bt;j++)
			val[j].clear();
		for(int j=1;j<=n;j++)
			if(rb[f[j]])
				val[rb[f[j]]].push_back(j);
		for(int j=1;j<=bt;j++)
		{
			int sz=val[j].size(),nw=1;
			for(int k=0;k<sz;k++)
			{
				while(nw<=dt&&d[nw]<val[j][k])
				{
					g[j][nw]=k;
					nw++;
				}
			}
			while(nw<=dt)
			{
				g[j][nw]=sz;
				nw++;
			}
		}
	/*	printf("bt=%d,",bt);
		for(int j=1;j<=bt;j++)
			printf("%d ",b[j]);
		printf("\n");
		for(int j=1;j<=n;j++)
			printf("%d ",f[j]);
		printf("\n");*/
		for(int j=1;j<=bt;j++)
			sum[b[j]]=0;
		for(int j=l;j<=r;j++)
		{
			if(q[j][0]==3)
			{
				swap(p[q[j][1]],p[q[j][2]]);
			}
			else if(q[j][0]==2)
			{
				int u=f[q[j][1]];
				ct++;
				while(vis[u]!=ct)
				{
					vis[u]=ct;
					sum[u]+=q[j][2];
					u=f[p[u]];
				}
			}
			else
			{
				int l,r;
				l=lower_bound(d+1,d+dt+1,q[j][1]-1)-d;
				r=lower_bound(d+1,d+dt+1,q[j][2])-d;
				ll ans=c[q[j][2]]-c[q[j][1]-1];
			//	printf("i=%d,j=%d,l=%d,r=%d,ans=%lld\n",i,j,l,r,ans);
				for(int k=1;k<=bt;k++)
				{
					ans+=1ll*(g[k][r]-g[k][l])*sum[b[k]];
			//		printf("k=%d,g=%d,%d,sum=%lld\n",k,g[k][r],g[k][l],sum[b[k]]);
				}
				printf("%lld\n",ans);
			}
		}
		for(int j=1;j<=n;j++)
		{
		//	printf("j=%d,f=%d,sum=%lld\n",j,f[j],sum[f[j]]);
			h[j]+=sum[f[j]];
		}
		for(int j=1;j<=n;j++)
			sum[f[j]]=0;
		for(int j=1;j<=n;j++)
			c[j]=c[j-1]+h[j];
	}
	return 0;
}
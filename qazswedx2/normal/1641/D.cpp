#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct pt
{
	int v[10],w;
	bool operator<(const pt p) const
	{
		return w<p.w; 
	}
}a[1000005];
int n,m,ans=2e9+100,vis[1000005],b[1000005],bt;
unsigned f[1000005];
int main()
{
//	freopen("D.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i].v[j]);
			b[++bt]=a[i].v[j];
		}
		scanf("%d",&a[i].w);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+bt+1);
	bt=unique(b+1,b+bt+1)-b-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i].v[j]=lower_bound(b+1,b+bt+1,a[i].v[j])-b;
		}
	}
	for(int i=1;i<=n;i+=32)
	{
	//	printf("i=%d\n",i);
		int r=min(i+31,n);
		unsigned mx=((1u<<(r-i))<<1)-1;
	//	for(int j=1;j<=bt;j++)
	//		f[j]=0;
	//	printf("i=%d\n",i);
		for(int j=i;j<=r;j++)
		{
			for(int k=1;k<=m;k++)
			{
		//		printf("j=%d,k=%d,a=%d\n",j,k,a[j].v[k]);
				f[a[j].v[k]]|=(1u<<(j-i));
			}
		}
		//printf("i=%d\n",i);
		for(int j=1;j<=n;j++)
			if(!vis[j])
			{
				unsigned nw=f[a[j].v[1]]|f[a[j].v[2]]|f[a[j].v[3]]|f[a[j].v[4]]|f[a[j].v[5]];
				if(nw!=mx)
				{
					vis[j]=1;
					for(int k=0;k<32;k++)
						if(!(nw&(1u<<k)))
						{
					//		printf("ans=%d,%d\n",ans,a[j].w+a[k+i].w);
							ans=min(ans,a[j].w+a[k+i].w);
							break;
						}
				}
			}
		for(int j=i;j<=r;j++)
		{
			for(int k=1;k<=m;k++)
				f[a[j].v[k]]=0;
		}
	//	printf("i=%d\n",i);
	}
	if(ans>2e9) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
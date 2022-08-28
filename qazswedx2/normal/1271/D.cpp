#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k,a[100005],b[100005],c[100005],f[100005],g[100005];
int s[100005];
bool cmp(const int x,const int y)
{
	return c[x]>c[y];
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i],&b[i],&c[i]),s[i]=i;
	int nw=k;
	for(int i=1;i<=n;i++)
	{
		f[i]=nw-a[i];
		if(f[i]<0)
		{
			printf("-1");
			return 0;
		}
		nw+=b[i];
	}
	for(int i=n-1;i>0;i--)
		f[i]=min(f[i],f[i+1]);
	//for(int i=1;i<=n;i++)
	//	printf("%d ",f[i]);
	//printf("\n");
	for(int i=1;i<=n;i++)
		g[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[v]=max(g[v],u);
	}
	sort(s+1,s+n+1,cmp);
	f[n+1]=nw;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int tnw=g[s[i]],fl=1;
		for(int j=tnw;j<=n;j++)
			if(!f[j+1]) fl=0;
		if(fl)
		{
			for(int j=tnw;j<=n;j++)
				f[j+1]--;
			ans+=c[s[i]];
		}
	}
	printf("%d",ans);
	return 0;
}
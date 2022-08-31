#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int t,n,m,a[200005],b[200005],f[200005],g[200005];
int find(int x)
{
	if(f[x]==x) return x;
	int q=find(f[x]);
	g[x]=g[f[x]]^g[x];
	return f[x]=q;
}
void link(int x,int y)
{
	int xx=x,yy=y;
	x=find(x),y=find(y);
	if(x==y) return;
	f[x]=y;
	g[x]=g[xx]^g[yy]^1;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			f[i]=i,g[i]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		int fl=1;
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			find(u),find(v);
			if(f[u]==f[v]&&g[u]==g[v]) fl=0;
			link(u,v);
		}
		ll ans1=0,ans2=0;
		for(int i=1;i<=n;i++)
		{
			find(i);
			if(!g[i]) ans1+=a[i],ans2+=b[i];
			else ans1-=a[i],ans2-=b[i];
		//	printf("i=%d,g=%d\n",i,g[i]);
		}
		if(fl==0)
		{
			if((ans1&1)==(ans2&1)) printf("YES\n");
			else printf("NO\n");
		}
		else
		{
			if(ans1==ans2) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
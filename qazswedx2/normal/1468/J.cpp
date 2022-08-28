#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int u,v,w;
}e[1000005];
bool operator<(const edge x,const edge y)
{
	return x.w<y.w;
}
int t,n,m,k,f[500005],ct;
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int link(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return 0;
	f[x]=y;
	ct--;
	return 1;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int nw=2e9;
		scanf("%d%d%d",&n,&m,&k);
		ct=n-1;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
			nw=min(nw,e[i].w-k<0?k-e[i].w:e[i].w-k);
		}
		sort(e+1,e+m+1);
		for(int i=1;i<=n;i++)
			f[i]=i;
		ll ans=0;
		for(int i=1;i<=m;i++)
		{
			if(link(e[i].u,e[i].v)&&e[i].w>k) ans+=e[i].w-k;
			if(!ct)
			{
				ans=max(ans,(ll)nw);
				break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
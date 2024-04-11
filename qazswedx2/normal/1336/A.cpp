#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int v,nxt;
}e[2000005];
int n,m,h[500005],t,size[500005],d[500005],a[500005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int dep)
{
	d[u]=dep;
	size[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+1);
		size[u]+=size[v];
	}
}
bool cmp(const int x,const int y)
{
	return x>y;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0,0);
	for(int i=1;i<=n;i++)
		a[i]=d[i]-size[i]+1;
	sort(a+1,a+n+1,cmp);
	ll ans=0;
	for(int i=1;i<=m;i++)
		ans+=a[i];
	printf("%I64d",ans);
	return 0;
}
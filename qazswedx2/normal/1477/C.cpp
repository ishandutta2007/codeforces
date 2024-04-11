#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct pt
{
	int x,y;
	pt(int x=0,int y=0):x(x),y(y){} 
};
pt operator-(pt a,pt b)
{
	return pt(a.x-b.x,a.y-b.y);
}
ll Dot(pt a,pt b)
{
	return 1ll*a.x*b.x+1ll*a.y*b.y;
}
struct edge
{
	int u,v;
	ll w;
	bool operator<(const edge &x) const
	{
		return w<x.w;
	}
}e[13000005];
pt a[5005];
int n,t,tans[100005],m,vis[100005];
ll getlen(int i,int j)
{
	return 1ll*(a[i].x-a[j].x)*(a[i].x-a[j].x)+1ll*(a[i].y-a[j].y)*(a[i].y-a[j].y);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			e[++t].u=i;
			e[t].v=j;
			e[t].w=getlen(i,j);
		}
	sort(e+1,e+t+1);
	for(int i=t;i>0;i--)
	{
		int u=e[i].u,v=e[i].v;
		if(vis[u]||vis[v]) continue;
		vis[u]=vis[v]=1;
		if(m&&Dot(a[tans[m]]-a[u],a[v]-a[u])>0) swap(u,v);
		tans[++m]=v;
		tans[++m]=u;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]) tans[++m]=i;
	for(int i=1;i<=m;i++)
		printf("%d ",tans[i]);
	return 0;
}
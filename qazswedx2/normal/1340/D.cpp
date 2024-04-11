#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[500005];
int n,h[100005],t,a[100005],tans[1000005][2],tt;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int val)
{
	tans[++tt][0]=u;
	tans[tt][1]=val;
	int mx,id;
	if(a[u]<=val) mx=val,id=val-a[u];
	else id=0,mx=a[u];
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		if(val==mx)
		{
			tans[++tt][0]=u;
			tans[tt][1]=id;
			val=id;
		}
		dfs(v,u,val+1);
		val++;
		tans[++tt][0]=u;
		tans[tt][1]=val;
	}
	//printf("u=%d,val=%d,mx=%d,id=%d\n",u,val,mx,id);
	if(val==mx&&u!=1)
	{
		tans[++tt][0]=u;
		tans[tt][1]=id;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		a[u]++,a[v]++;
	}
	dfs(1,0,0);
	printf("%d\n",tt);
	for(int i=1;i<=tt;i++)
		printf("%d %d\n",tans[i][0],tans[i][1]);
	return 0;
}
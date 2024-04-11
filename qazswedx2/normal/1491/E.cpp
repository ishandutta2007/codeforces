#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,vis,nxt;
}e[2000005];
int n,h[500005],t=1,f[105],fl=1,sz[500005],nww;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int x)
{
	sz[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||e[i].vis) continue;
		dfs(v,u,x);
		sz[u]+=sz[v];
		if(sz[v]==f[x-1]||sz[v]==f[x-2]) nww=i;
	}
}
void bfz(int u,int x)
{
	if(x==1||x==2||fl==0) return;
	nww=-1;
	dfs(u,0,x);
	if(nww==-1)
	{
		fl=0;
		return;
	}
	int l=e[nww].v,r=e[nww^1].v;
	e[nww].vis=e[nww^1].vis=1;
	if(sz[l]==f[x-1])
	{
		bfz(l,x-1);
		bfz(r,x-2);
	}
	else
	{
		bfz(l,x-2);
		bfz(r,x-1);
	}
}
int main()
{
	f[1]=f[2]=1;
	for(int i=3;i<=30;i++)
	{
		f[i]=f[i-1]+f[i-2];
	//	printf("i=%d,f=%d\n",i,f[i]);
	}
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	int id=-1;
	for(int i=1;i<=30;i++)
		if(f[i]==n)
		{
			id=i;
		}
	if(id==-1) fl=0;
	else bfz(1,id);
	if(fl) printf("YES\n");
	else printf("NO\n");
	return 0;
}
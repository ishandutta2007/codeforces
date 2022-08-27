#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[2000005];
int T,n,m,h[1000005],t,vis[1000005],deg[1000005],f[1000005],fl,tans[1000005];
int b[1000005],bt,a[1000005],at;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	a[++at]=u;
	vis[u]=1;
	f[u]=fa;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		if(vis[v])
		{
			fl=1;
			int nw=u;
			while(nw!=v)
			{
				b[++bt]=nw;
				nw=f[nw];
			}
			b[++bt]=v;
			return;
		}
		dfs(v,u);
		if(fl) return;
	}
}
void print()
{
	printf("YES\n");
	for(int i=1;i<=n;i++)
		printf("%d ",tans[i]);
	printf("\n");
}
int dfs2(int u,int fa,int to)
{
	if(u==to)
	{
		b[++bt]=u;
		return 1;
	}
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		if(dfs2(v,u,to))
		{
			b[++bt]=u;
			return 1;
		}
	}
	return 0;
}
vector<int> val[3];
void dfs3(int u,int fa,int id)
{
	val[id].push_back(u);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs3(v,u,id);
	}
}
int solve()
{
	int ct3=0,u=-1,v=-1;
	for(int i=1;i<=at;i++)
		if(deg[a[i]]==3)
		{
			ct3++;
			if(u==-1) u=a[i];
			else v=a[i];
		}
	if(ct3>=2)
	{
		for(int i=h[u];i;i=e[i].nxt)
		{
			int vv=e[i].v;
			tans[vv]=1;
		}
		for(int i=h[v];i;i=e[i].nxt)
		{
			int vv=e[i].v;
			tans[vv]=1;
		}
		dfs2(u,0,v);
	//	printf("u=%d,v=%d,bt=%d\n",u,v,bt); 
		for(int i=1;i<=bt;i++)
			tans[b[i]]=2;
		return 1;
	}
	if(!ct3) return 0;
	int nw=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		val[nw].clear();
		dfs3(v,u,nw);
		nw++;
	}
	if(val[0].size()>val[1].size()) swap(val[0],val[1]);
	if(val[0].size()>val[2].size()) swap(val[0],val[2]);
	if(val[1].size()>val[2].size()) swap(val[1],val[2]);
	int sz0=val[0].size(),sz1=val[1].size(),sz2=val[2].size();
	if(sz1<=1) return 0;
	if(sz0>=2)
	{
		tans[u]=3;
		for(int i=0;i<3;i++)
			tans[val[i][0]]=2,tans[val[i][1]]=1;
		return 1;
	}
	if(sz1>=3)
	{
		tans[u]=4;
		tans[val[0][0]]=2;
		for(int i=1;i<3;i++)
			tans[val[i][0]]=3,tans[val[i][1]]=2,tans[val[i][2]]=1;
		return 1;
	}
	if(sz2>=5)
	{
		tans[u]=6;
		tans[val[0][0]]=3;
		tans[val[1][0]]=4;
		tans[val[1][1]]=2;
		for(int i=1;i<6;i++)
			tans[val[2][i-1]]=(6-i);
		return 1;
	}
	return 0;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		t=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n+1;i++)
			h[i]=vis[i]=deg[i]=tans[i]=0;
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
			deg[u]++;
			deg[v]++;
		}
		fl=0;
		//printf("---\n");
		for(int i=1;i<=n;i++)
			if(deg[i]>=4)
			{
				int ct=0;
				tans[i]=2;
				for(int j=h[i];j;j=e[j].nxt)
				{
					int v=e[j].v;
					tans[v]=1;
					ct++;
					if(ct==4) break;
				}
				fl=1;
				break;
			}
		if(fl)
		{
			print();
			continue;
		}
		//printf("---\n");
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				at=bt=0;
			//	printf("i=%d\n",i);
				dfs(i,0);
			//	printf("i=%d\n",i);
				if(fl)
				{
					for(int j=1;j<=bt;j++)
						tans[b[j]]=1;
					break;
				}
				if(solve())
				{
					fl=2;
					break;
				}
			}
		if(fl) print();
		else printf("NO\n");
	}
	return 0;
}
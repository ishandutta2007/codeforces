#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
struct pt
{
	int x,y;
	pt(int x=0,int y=0):x(x),y(y){}
	bool operator<(const pt xx) const
	{
		return x==xx.x?y<xx.y:x<xx.x;
	}
};
struct edge
{
	int v,nxt;
}e[500005];
int n,m,h[100005],f[100005],vis[100005],a[1005],at,g[1005][1005];
int tf[100005],tans,t;
set<pt> st;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
int find(int x)
{
	if(x==tf[x]) return x;
	return tf[x]=find(tf[x]);
}
void link(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	tf[x]=y;
	tans--;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		f[u]++,f[v]++;
		st.insert(pt(u,v));
		st.insert(pt(v,u));
	}
	int nw=n+1,id=0;
	for(int i=1;i<=n;i++)
		if(f[i]<nw)
		{
			nw=f[i];
			id=i;
		}
	for(int i=h[id];i;i=e[i].nxt)
	{
		int v=e[i].v;
		a[++at]=v;
		vis[v]=1;
	}
	at++;
	tans=at-1;
	/*printf("id=%d,at=%d\n",id,at);
	for(int i=1;i<=at;i++)
		printf("%d ",a[i]);
	printf("\n");*/
	for(int i=1;i<=at;i++)
		tf[i]=i;
	for(int i=1;i<=at;i++)
		for(int j=i+1;j<=at;j++)
		{
			if(j<at) 
			{
				if(st.find(pt(a[i],a[j]))!=st.end()) g[i][j]=g[j][i]=1;
				else g[i][j]=g[j][i]=0;	
			}
			else
			{
				int ct=0;
				for(int k=h[a[i]];k;k=e[k].nxt)
				{
					int v=e[k].v;
					if(!vis[v]) ct++;
				}
				if(ct==n-at+1) g[i][j]=g[j][i]=1;
				else g[i][j]=g[j][i]=0;	
			}
		}
	for(int i=1;i<=at;i++)
		for(int j=i+1;j<=at;j++)
		{
			if(!g[i][j]) link(i,j);
			//printf("i=%d,j=%d,g=%d\n",i,j,g[i][j]);
		}
	printf("%d",tans);
	return 0;
}
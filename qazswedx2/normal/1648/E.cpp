#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
struct DSU
{
	int f[1000005];
	vector<int> val[1000005];
	int find(int x)
	{
		if(f[x]==x) return x;
		return f[x]=find(f[x]);
	}
	int link(int x,int y)
	{
		x=find(x),y=find(y);
		if(x==y) return 0;
		if((int)val[x].size()>(int)val[y].size()) swap(x,y);
		f[x]=y;
		for(int i=0;i<(int)val[x].size();i++)
			val[y].push_back(val[x][i]);
		return 1;
	}
	void build(int n)
	{
		for(int i=1;i<=n;i++)
		{
			f[i]=i;
			val[i].clear();
			val[i].push_back(i);
		}
	}
}T[2];
set<pair<int,int> > st;
struct edge
{
	int u,v,w,id;
	bool operator<(const edge e) const
	{
		return w<e.w;
	}
}e1[2000005];
struct edge2
{
	int v,w,nxt;
}e2[2000005];
int h[2000005],t,f[1000005][22],c[1000005][22];
void add(int u,int v,int w)
{
//	printf("add:u=%d,v=%d,w=%d\n",u,v,w);
	e2[++t].v=v;
	e2[t].w=w;
	e2[t].nxt=h[u];
	h[u]=t;
}
inline int F(int x,int y)
{
	return st.find(make_pair(x,y))==st.end();
}
int b[1000005][2],bt;
int getans(int x,int y,int w)
{
	x=T[0].find(x),y=T[0].find(y);
	//printf("getans:x=%d,y=%d,w=%d\n",x,y,w);
	for(int i=0;i<(int)T[0].val[x].size();i++)
	{
		int u=T[0].val[x][i];
		for(int j=0;j<(int)T[0].val[y].size();j++)
		{
			int v=T[0].val[y][j];
			
			//	printf("---link:u=%d,v=%d\n",u,v);
			if(F(u,v))
			{
		//		printf("link:u=%d,v=%d\n",u,v);
			//	T[0].link(u,v);
				b[++bt][0]=u;
				b[bt][1]=v;
				add(u,v,w);
				add(v,u,w);
				return 1;
			}
		}
	}
	return 0;
}
int bb[1000005][2],bbt,cc[1000005],cct;
void tlink(int x,int y,int w)
{
	x=T[1].find(x),y=T[1].find(y);
	if(x==y) return;
	T[1].f[x]=y;
	bt=bbt=cct=0;
	for(int i=0;i<(int)T[1].val[x].size();i++)
	{
		int u=T[1].val[x][i];
		int las=bt,lasy=-1;
		for(int j=0;j<(int)T[1].val[y].size();j++)
		{
			int v=T[1].val[y][j];
		//	printf("tlink:u=%d,v=%d\n",u,v);
			if(getans(v,u,w))
			{
				lasy=T[1].val[y][j];
				swap(T[1].val[y][j],T[1].val[y][(int)T[1].val[y].size()-1]);
				T[1].val[y].pop_back();
				j--;
			}
		}
		if(lasy!=-1)
		{
			T[1].val[y].push_back(lasy);
			bb[++bbt][0]=b[bt][0];
			bb[bbt][1]=b[bt][1];
			for(int i=las+1;i<bt;i++)
				T[0].link(b[i][0],b[i+1][0]);
		}
		else
		{
			cc[++cct]=u;
		}
	//	T[1].val[y].push_back(u);
	}
	for(int i=1;i<=bbt;i++)
		T[0].link(bb[i][0],bb[i][1]);
	for(int i=1;i<=cct;i++)
		T[1].val[y].push_back(cc[i]);
}
int T2,n,m,d[1000005],qans[1000005];
void dfs(int u,int fa,int dep,int ww)
{
	c[u][0]=fa;
	f[u][0]=ww;
	d[u]=dep;
	//printf("dfs:u=%d,fa=%d,dep=%d,ww=%d\n",u,fa,dep,ww);
	for(int i=1;i<=18;i++)
	{
		c[u][i]=c[c[u][i-1]][i-1];
		f[u][i]=max(f[u][i-1],f[c[u][i-1]][i-1]);
	}
	for(int i=h[u];i;i=e2[i].nxt)
	{
		int v=e2[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+1,e2[i].w);
	}
}
int query(int u,int v)
{
	int ans=0;
	if(d[u]<d[v]) swap(u,v);
	for(int i=18;i>=0;i--)
		if(d[c[u][i]]>=d[v])
		{
			ans=max(ans,f[u][i]);
			u=c[u][i];
		}
	if(u==v) return ans;
	for(int i=18;i>=0;i--)
		if(c[u][i]!=c[v][i])
		{
			ans=max(ans,max(f[u][i],f[v][i]));
			u=c[u][i];
			v=c[v][i];
		}
	ans=max(ans,max(f[u][0],f[v][0]));
	return ans;
}
int main()
{
	scanf("%d",&T2);
	while(T2--)
	{
		scanf("%d%d",&n,&m);
		t=0;
		for(int i=0;i<=n+1;i++)
			h[i]=0;
		st.clear();
		for(int i=1;i<=m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			e1[i].u=u,e1[i].v=v,e1[i].w=w;
			e1[i].id=i;
			st.insert(make_pair(u,v));
			st.insert(make_pair(v,u));
		}
		sort(e1+1,e1+m+1);
		T[0].build(n);
		T[1].build(n);
		for(int i=1;i<=m;i++)
		{
			tlink(e1[i].u,e1[i].v,e1[i].w);
		}
		dfs(1,0,1,0);
		for(int i=1;i<=m;i++)
		{
			qans[e1[i].id]=query(e1[i].u,e1[i].v);
		}
		for(int i=1;i<=m;i++)
			printf("%d ",qans[i]);
		printf("\n");
	}
	return 0;
}
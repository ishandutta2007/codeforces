#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn=300111;
int n,m,q;

struct tree
{
	int nxt[maxn<<1],to[maxn<<1],head[maxn],etot;
	int fa[20][maxn],dep[maxn],dfn[maxn],timer,seq[maxn],edfn[maxn];
	
	tree()
	{
		memset(head,0,sizeof(head));
		etot=1;
	}
	
	void addedge(int u,int v)
	{
		if(u==v)return;
//		printf("%d %d\n",u,v);
		nxt[++etot]=head[u];head[u]=etot;
		to[etot]=v;
		nxt[++etot]=head[v];head[v]=etot;
		to[etot]=u;
	}
	
	void dfs(int x,int f,int d)
	{
		dfn[x]=++timer;seq[timer]=x;fa[0][timer]=dfn[f];dep[timer]=d;
		for(int i=1;i<20;i++)fa[i][timer]=fa[i-1][fa[i-1][timer]];
		
		for(int i=head[x];i;i=nxt[i])if(to[i]!=f)
			dfs(to[i],x,d+1);
		edfn[x]=timer;
	}
	
	int getlca(int u,int v)//x -> dfn[x]
	{
		if(dep[u]<dep[v])swap(u,v);
		for(int i=19;i>=0;i--)if(dep[u]-dep[v]>>i)u=fa[i][u];
		if(u==v)return u;
		for(int i=19;i>=0;i--)if(fa[i][u]!=fa[i][v])
		{
			u=fa[i][u];
			v=fa[i][v];
		}
		return fa[0][u];
	}
	
	void prework(int n)
	{
		timer=0;
		for(int i=1;i<=n;i++)if(!dfn[i])
			dfs(i,0,1);
//		printf("dep ");for(int i=1;i<=n;i++)printf("%d ",dep[dfn[i]]);puts("");
	}
	
	int stk[maxn],top;
	vector<pii> extract(vi&vs)
	{
		for(auto&x:vs)x=dfn[x];
		sort(vs.begin(),vs.end());
		for(int i=vs.size()-1;i>0;i--)
		{
			int l=getlca(vs[i],vs[i-1]);
//			printf("vs %d %d l= %d\n",seq[vs[i]],seq[vs[i-1]],seq[l]);
			if(l)vs.pb(l);
		}
		sort(vs.begin(),vs.end());vs.erase(unique(vs.begin(),vs.end()),vs.end());
		for(auto&x:vs)x=seq[x];
//		printf("extract ");for(auto x:vs)printf("%d ",x);puts("");
		
		top=0;
		vector<pii> ret;
		for(auto x:vs)
		{
			while(top&&edfn[stk[top]]<dfn[x])top--;
			if(top)ret.pb(mp(stk[top],x));
			stk[++top]=x;
		}
//		for(auto e : ret)printf("edge %d %d\n",e.ff,e.ss);
		return ret;
	}
};

struct graph
{
	int nxt[maxn<<2],to[maxn<<2],head[maxn],etot;
	bool bridge[maxn<<1];
	void addedge(int u,int v)
	{
		if(u==v)return;
//		printf("Edge %d %d\n",u,v);
		nxt[++etot]=head[u];head[u]=etot;to[etot]=v;
		nxt[++etot]=head[v];head[v]=etot;to[etot]=u;
	}
	
	void clear(int n)
	{
		for(int i=1;i<=n;i++)head[i]=0;
		etot=1;
	}
	
	int dfn[maxn],low[maxn],timer,bcc[maxn],btot;
	int stk[maxn],top;
	void dfs(int x,int fid)
	{
		dfn[x]=low[x]=++timer;
		stk[++top]=x;
		for(int i=head[x];i;i=nxt[i])if(i!=fid)
		{
			if(!dfn[to[i]])
			{
				dfs(to[i],i^1);
				low[x]=min(low[x],low[to[i]]);
			}
			else low[x]=min(low[x],dfn[to[i]]);
		}
		if(low[x]==dfn[x])
		{
			btot++;
			while(true)
			{
				bcc[stk[top]]=btot;
				if(stk[top--]==x)break;
			}
			if(fid)bridge[fid>>1]=1;
		}
	}
	void shrink(int n)
	{
		timer=btot=0;
		for(int i=1;i<=n;i++)dfn[i]=0;
		for(int i=1;i<=(etot)>>1;i++)bridge[i]=0;
		for(int i=1;i<=n;i++)if(!dfn[i])dfs(i,0);
//		printf("bcc ");for(int i=1;i<=n;i++)printf("%d ",bcc[i]);
//		puts("");
	}
	void construct_tree(tree&T)
	{
		for(int i=1;i<=(etot)>>1;i++)if(bridge[i])
		{
			int u=to[i<<1],v=to[i<<1|1];
			T.addedge(bcc[u],bcc[v]);
		}
		T.prework(btot);
	}
};

graph G1,G2;
tree T;
int id[maxn];
int va[maxn],eu[maxn],ev[maxn];

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	G1.clear(n);
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		G1.addedge(u,v);
	}
	G1.shrink(n);
//	puts("tree");
	G1.construct_tree(T);
	
//	for(int i=1;i<=n;i++)printf("i= %d bcc= %d\n",i,G1.bcc[i]);
	
	int R=n-1;
	for(int qq=1;qq<=q;qq++)
	{
		int N,M;
		scanf("%d%d",&N,&M);
		vector<int> vs;
		for(int i=1;i<=N;i++)
		{
			scanf("%d",va+i);
			va[i]=(va[i]+R)%n+1;
			vs.pb(G1.bcc[va[i]]);
		}
		for(int i=1;i<=M;i++)
		{
			scanf("%d%d",eu+i,ev+i);
			eu[i]=(eu[i]+R)%n+1;
			ev[i]=(ev[i]+R)%n+1;
			vs.pb(G1.bcc[eu[i]]);
			vs.pb(G1.bcc[ev[i]]);
		}
		
		sort(vs.begin(),vs.end());vs.erase(unique(vs.begin(),vs.end()),vs.end());
		vector<pii> es=T.extract(vs);
//		printf("vs ");for(auto x:vs)printf("%d ",n+1-x);puts("");
		
		int sz=(int)vs.size();
		for(int i=0;i<sz;i++)id[vs[i]]=i+1;
		G2.clear(sz);
		for(auto e:es)
		{
//			printf("Edge %d %d\n",e.ff,e.ss);
			G2.addedge(id[e.ff],id[e.ss]);
		}
		for(int i=1;i<=M;i++)G2.addedge(id[G1.bcc[eu[i]]],id[G1.bcc[ev[i]]]);
		
		G2.shrink(sz);
		bool ok=1;int piv=G2.bcc[id[G1.bcc[va[1]]]];
		for(int i=2;i<=N&&ok;i++)ok&=(G2.bcc[id[G1.bcc[va[i]]]]==piv);
		if(ok)
		{
			puts("YES");
			R=(R+qq)%n;
		}
		else puts("NO");
	}
	return 0;
}
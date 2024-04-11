// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=1000111;
const int maxm=1000111;

struct max_flow
{
	struct edge{int to,cap;};
	int head[maxn],nxt[maxm<<1],iter[maxn],tot;
	edge e[maxm<<1];
	void clear()
	{
		memset(head,0,sizeof(head));
		tot=1;
	}
	max_flow(){clear();}
	void addedge(int u,int v,int cap)
	{
		nxt[++tot]=head[u];
		head[u]=tot;
		e[tot]=edge{v,cap};
		nxt[++tot]=head[v];
		head[v]=tot;
		e[tot]=edge{u,0};
	}
	
	int lvl[maxn],q[maxn];
	bool bfs(int s,int t)
	{
		memset(lvl,-1,sizeof(lvl));
		lvl[s]=0;int rr=0;q[rr++]=s;
		for(int fr=0;fr<rr;fr++)
		{
			int x=q[fr];if(x==t)return true;
			for(int i=head[x];i;i=nxt[i])if(e[i].cap&&lvl[e[i].to]==-1)
			{
				lvl[e[i].to]=lvl[x]+1;
				q[rr++]=e[i].to;
			}
		}
		return false;
	}
	int dfs(int x,int t,int f)
	{
		if(x==t||f==0)return f;
		int ret=0;
		for(int&i=iter[x];i;i=nxt[i])if(e[i].cap&&lvl[e[i].to]==lvl[x]+1)
		{
			int d=dfs(e[i].to,t,min(f,e[i].cap));
			e[i].cap-=d;e[i^1].cap+=d;
			f-=d;ret+=d;
			if(!f)break;
		}
		return ret;
	}
	int maxflow(int s,int t)
	{
		int flow=0;
		while(bfs(s,t))
		{
			memcpy(iter,head,sizeof(head));
			flow+=dfs(s,t,inf);
		}
		return flow;
	}
}thor;

vector<int>g[20111],ie[20111];
int f[15][20111],id[15][20111],fid[20111],dep[20111],tot,n,m;

void dfs(int x)
{
	for(int i=1;i<15;i++)f[i][x]=f[i-1][f[i-1][x]];
	for(int i=0;i<15;i++)if(f[i][x])id[i][x]=++tot;
	for(int i=0;i<(int)g[x].size();i++)if(g[x][i]!=f[0][x])
	{
		f[0][g[x][i]]=x;fid[g[x][i]]=ie[x][i];dep[g[x][i]]=dep[x]+1;
		dfs(g[x][i]);
	}
}

int main()
{
	get2(n,m);
	for(int i=1,u,v;i<n;i++)
	{
		get2(u,v);
		g[u].pb(v);g[v].pb(u);
		ie[u].pb(i);ie[v].pb(i);
	}
	dfs(1);
	int S=tot+m+1,T=S+1;
	for(int i=2;i<=n;i++)
	{
		thor.addedge(id[0][i],T,1);
		for(int j=1;j<15;j++)if(f[j][i])
		{
			thor.addedge(id[j][i],id[j-1][i],100000);
			thor.addedge(id[j][i],id[j-1][f[j-1][i]],100000);
		}
	}
	for(int i=1,u,v;i<=m;i++)
	{
		get2(u,v);
		thor.addedge(S,tot+i,1);
		if(dep[u]<dep[v])swap(u,v);
		for(int j=14;j>=0;j--)if(dep[u]-dep[v]>>j)
		{
			thor.addedge(tot+i,id[j][u],1);
			u=f[j][u];
		}
		if(u==v)continue;
		for(int j=14;j>=0;j--)if(f[j][u]!=f[j][v])
		{
			thor.addedge(tot+i,id[j][u],1);
			thor.addedge(tot+i,id[j][v],1);
			u=f[j][u];v=f[j][v];
		}
		thor.addedge(tot+i,id[0][u],1);thor.addedge(tot+i,id[0][v],1);
	}
	printf("%d\n",thor.maxflow(S,T));
	vector<int> v1,v2;
	for(int i=1;i<=m;i++)if(thor.lvl[tot+i]==-1)v1.pb(i);
	for(int i=2;i<=n;i++)if(thor.lvl[id[0][i]]!=-1)v2.pb(fid[i]);
	printf("%d ",(int)v1.size());for(auto v:v1)printf("%d ",v);puts("");
	printf("%d ",(int)v2.size());for(auto v:v2)printf("%d ",v);puts("");
	return 0;
}
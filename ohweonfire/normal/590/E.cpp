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
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int mod=1e9+7;
inline void add(int&x,int y){x+=y;if(x>=mod)x-=mod;}

const int N=2;
const int maxv=10000111;

int go[maxv][N],tot,rt,have[maxv],fa[maxv];
namespace ac
{
	int q[maxv],fr,rr,fail[maxv];
	void construct()
	{
		fr=rr=0;q[rr++]=rt;
		for(;fr<rr;fr++)
		{
			int x=q[fr];
			if(!have[x])have[x]=have[fail[x]];
			for(int i=0;i<N;i++)if(go[x][i])
			{
				int&f=fail[go[x][i]];
				if(x==rt)f=x;
				else
				{
					f=fail[x];
					while(f!=rt&&!go[f][i])f=fail[f];
					if(go[f][i])f=go[f][i];
				}
				q[rr++]=go[x][i];
			}
		}
		
	}
};

const int maxn=1511;
const int maxm=600111;

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
			int x=q[fr];
			for(int i=head[x];i;i=nxt[i])if(e[i].cap&&lvl[e[i].to]==-1)
			{
				lvl[e[i].to]=lvl[x]+1;
				q[rr++]=e[i].to;
			}
		}
		return lvl[t]!=-1;
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

int n,pos[1111],id[1111];
bool con[1111][1111];
char s[maxv];

int main()
{
	tot=rt=1;
	scanf("%d",&n);int nn=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		int cur=rt;
		for(int j=1;s[j];j++)
		{
			if(!go[cur][s[j]-'a'])
			{
				go[cur][s[j]-'a']=++tot;
				fa[tot]=cur;
			}
			cur=go[cur][s[j]-'a'];
		}
		if(!have[cur])
		{
			pos[++nn]=cur;
			have[cur]=nn;
			id[nn]=i;
		}
	}
	n=nn;
	
	ac::construct();
	for(int i=1;i<=n;i++)
	{
		int cur=pos[i];
		while(cur!=rt)
		{
			if(cur==pos[i]&&have[ac::fail[cur]])con[i][have[ac::fail[cur]]]=1;
			else if(cur!=pos[i]&&have[cur])con[i][have[cur]]=1;
			cur=fa[cur];
		}
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)con[i][j]|=con[i][k]&con[k][j];
	
	int S=n+n+1,T=n+n+2;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(con[i][j])thor.addedge(i,j+n,inf);
	for(int i=1;i<=n;i++)
	{
		thor.addedge(S,i,1);
		thor.addedge(i+n,T,1);
	}
	printf("%d\n",n-thor.maxflow(S,T));
	for(int i=1;i<=n;i++)if(thor.lvl[i]!=-1&&thor.lvl[i+n]==-1)printf("%d ",id[i]);
	return 0;
}
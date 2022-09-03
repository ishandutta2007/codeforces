// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
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

const int maxn=200111;
const int maxm=500111;

struct max_flow
{
	struct edge{int to,cap;};
	int head[maxn],nxt[maxm<<1],iter[maxn],tot=1;
	edge e[maxm<<1];
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
	void bfs(int s)
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
	}
	int dfs(int x,int t,int f)
	{
		if(x==t||f==0)return f;if(lvl[x]==lvl[t])return 0;
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
		int f,flow=0;
		for(;;)
		{
			bfs(s);if(lvl[t]==-1)return flow;
			memcpy(iter,head,sizeof(head));
			flow+=dfs(s,t,inf);
		}
	}
};

max_flow m1;
struct edge{int u,v,b,c;};
vector<edge>es;
int flow[maxn],ans[maxn];
int n,m,r,b,x[maxn],y[maxn],dx[maxn],dy[maxn],cx[maxn],cy[maxn],xtot,ytot;

int maxflow(int s,int t)
{
	int S=t+1,T=S+1;
	for(int i=0;i<(int)es.size();i++)
	{
		edge&e=es[i];
		m1.addedge(e.u,e.v,e.c-e.b);
		flow[e.v]+=e.b;
		flow[e.u]-=e.b;
		if(e.b>e.c)
		{
			puts("-1");
			exit(0);
		}
	}
	int sum=0,f=0;
	m1.addedge(t,s,10000000);
	for(int i=0;i<S;i++)
	{
		if(flow[i]>0)
		{
			m1.addedge(S,i,flow[i]);
			sum+=flow[i];
		}
		else if(flow[i]<0)m1.addedge(i,T,-flow[i]);
	}
//	int tmp=m1.maxflow(S,T);printf("tmp= %d sum= %d\n",tmp,sum);
	if(m1.maxflow(S,T)<sum)
	{
		puts("-1");
		exit(0);
	}
	f+=m1.maxflow(s,t);
	for(int i=1;i<=n;i++)ans[i]=m1.e[i<<1].cap^1;
	return f;
}

int main()
{
	get2(n,m);get2(r,b);
	vector<int>vx,vy;
	for(int i=1;i<=n;i++)
	{
		get2(x[i],y[i]);
		vx.pb(x[i]);vy.pb(y[i]);
	}
	
	sort(vx.begin(),vx.end());sort(vy.begin(),vy.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	vy.erase(unique(vy.begin(),vy.end()),vy.end());
	xtot=(int)vx.size();ytot=(int)vy.size();
	int s=xtot+ytot+1,t=s+1;
	for(int i=1;i<=n;i++)
	{
		x[i]=upper_bound(vx.begin(),vx.end(),x[i])-vx.begin();
		y[i]=upper_bound(vy.begin(),vy.end(),y[i])-vy.begin();
		es.pb(edge{x[i],y[i]+xtot,0,1});
		cx[x[i]]++;cy[y[i]]++;
		dx[x[i]]++;dy[y[i]]++;
//		printf("i= %d x= %d y= %d\n",i,x[i],y[i]);
	}
	
	for(int i=1,t,l,d;i<=m;i++)
	{
		get3(t,l,d);
		if(t==1)
		{
			int x=upper_bound(vx.begin(),vx.end(),l)-vx.begin();
			if(x>xtot||x==0||vx[x-1]!=l)continue;
			dx[x]=min(dx[x],d);
		}
		else
		{
			int y=upper_bound(vy.begin(),vy.end(),l)-vy.begin();
			if(y>ytot||y==0||vy[y-1]!=l)continue;
			dy[y]=min(dy[y],d);
		}
	}
	for(int i=1;i<=xtot;i++)es.pb(edge{s,i,(cx[i]-dx[i]+1)>>1,(cx[i]+dx[i])>>1});
	for(int i=1;i<=ytot;i++)es.pb(edge{i+xtot,t,(cy[i]-dy[i]+1)>>1,(cy[i]+dy[i])>>1});
	int tmp=maxflow(s,t);
	printf("%I64d\n",1ll*tmp*min(r,b)+1ll*(n-tmp)*max(r,b));
	for(int i=1;i<=n;i++)if(ans[i]^(r>b))putchar('r');else putchar('b');
	return 0;
}
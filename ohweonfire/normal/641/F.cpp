// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
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
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

struct two_sat
{
	int head[2111],nxt[2000111],to[2000111],tot=1,scc[2111],cnt;
	void addedge(int u,int v)
	{
		if(u==v)return;
		nxt[++tot]=head[u];
		head[u]=tot;to[tot]=v;
	}
	int dfn[2111],low[2111],timer,stk[2111],top;
	void dfs(int x)
	{
		dfn[x]=low[x]=++timer;stk[++top]=x;
		for(int i=head[x];i;i=nxt[i])
		{
			if(!dfn[to[i]])
			{
				dfs(to[i]);
				low[x]=min(low[x],low[to[i]]);
			}
			else if(!scc[to[i]])
				low[x]=min(low[x],dfn[to[i]]);
		}
		if(low[x]==dfn[x])
		{
			cnt++;
			while(true)
			{
				top--;
				scc[stk[top+1]]=cnt;
				if(stk[top+1]==x)break;
			}
		}
	}
	bitset<2111>con[2111];
	int rk[2111],q[2111],rear,dgr[2111];
	bool solve(int n)
	{
		for(int i=0;i<2111;i++)con[i].reset();
		timer=cnt=top=0;memset(scc,0,sizeof(scc));memset(dfn,0,sizeof(dfn));memset(dgr,0,sizeof(dgr));
		for(int i=0;i<n;i++)if(!dfn[i])dfs(i);
		
		for(int i=0;i<n;i++)for(int j=head[i];j;j=nxt[j])
			con[scc[i]].set(scc[to[j]]);
		for(int i=1;i<=cnt;i++)for(int j=1;j<=cnt;j++)if(con[i][j]&&i!=j)dgr[i]++;
		rear=0;
		for(int i=1;i<=cnt;i++)if(dgr[i]==0)q[rear++]=i;
		for(int _=0;_<rear;_++)
		{
			int x=q[_];rk[x]=_;
			for(int i=1;i<=cnt;i++)if(con[i][x]&&i!=x)
			{
				dgr[i]--;
				if(dgr[i]==0)q[rear++]=i;
			}
		}
		
		for(int i=0;i<n;i++)if(scc[i]==scc[i^1])return false;
		return true;
	}
	void getans(int n)
	{
		for(int i=0;i<n;i+=2)
		{
			if(rk[scc[i]]>rk[scc[i^1]])printf("0 ");
			else printf("1 ");
		}
		exit(0);
	}
	void work()
	{
		for(int i=0;i<cnt;i++)
		{
			for(int j=1;j<=cnt;j++)
				if(q[i]!=j&&con[j][q[i]])con[j]|=con[q[i]];
		}
	}
}f,g;

int n,m1,m2;
bool fix[2111];
int main()
{
	get3(n,m1,m2);
	for(int i=1,u,v;i<=m1;i++)
	{
		get2(u,v);
		if(u<0)u=(-u)*2-1;
		else u=u*2-2;
		if(v<0)v=(-v)*2-1;
		else v=v*2-2;
		f.addedge(u^1,v);
		f.addedge(v^1,u);
	}
	for(int i=1,u,v;i<=m2;i++)
	{
		get2(u,v);
		if(u<0)u=(-u)*2-1;
		else u=u*2-2;
		if(v<0)v=(-v)*2-1;
		else v=v*2-2;
		g.addedge(u^1,v);
		g.addedge(v^1,u);
	}
	bool f1=f.solve(n<<1),f2=g.solve(n<<1);
	if(!f1&&!f2)puts("SIMILAR");
	else if(f1&&!f2)f.getans(n<<1);
	else if(f2&&!f1)g.getans(n<<1);
	else
	{
		f.work();g.work();
		for(int i=0;i<n+n;i++)
		{
			if(f.con[f.scc[i]][f.scc[i^1]]||g.con[g.scc[i]][g.scc[i^1]])
				fix[i]=fix[i^1]=1;
			if(f.con[f.scc[i]][f.scc[i^1]]&&!g.con[g.scc[i]][g.scc[i^1]])
			{
				g.addedge(i^1,i);
				g.solve(n<<1);
				g.getans(n<<1);
			}
			if(g.con[g.scc[i]][g.scc[i^1]]&&!f.con[f.scc[i]][f.scc[i^1]])
			{
				f.addedge(i^1,i);
				f.solve(n<<1);
				f.getans(n<<1);
			}
		}
		for(int i=0;i<n+n;i++)for(int j=0;j<n+n;j++)
		{
			if(fix[i]||fix[j])continue;
			if(i==j)continue;
			if(f.con[f.scc[i]][f.scc[j]]&&!g.con[g.scc[i]][g.scc[j]])
			{
				g.addedge(i^1,i);
				g.addedge(j,j^1);
				if(!g.solve(n<<1))puts("baojing");
				g.getans(n<<1);
			}
			if(!f.con[f.scc[i]][f.scc[j]]&&g.con[g.scc[i]][g.scc[j]])
			{
				f.addedge(i^1,i);
				f.addedge(j,j^1);
				if(!f.solve(n<<1))puts("baojing");
				f.getans(n<<1);
			}
		}
		puts("SIMILAR");
	}
	return 0;
}
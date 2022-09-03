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
	short a[25]= {},sz=0;
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

int cnt,n,ex[25],ey[25],piv[7],num[7],to[7][7],k,cur[7],tx[200111],ty[200111];
char s[10],t[10];

int f[7];int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
bool tree(int msk)
{
	for(int i=1;i<=cnt;i++)f[i]=i;
	for(int i=0;i<k;i++)
	{
		if(!((msk>>i)&1))continue;
		if(gf(ex[i])==gf(ey[i]))return false;
		if(to[ex[i]][ey[i]]==0)return false;
		f[gf(ex[i])]=gf(ey[i]);
	}
	return true;
}
struct max_flow
{
	struct edge
	{
		int to,cap,rev;
		edge(int to,int cap,int rev)
		{
			this->to=to;
			this->cap=cap;
			this->rev=rev;
		}
	};
	vector<edge> g[233];
	void clear()
	{
		for(int i=0;i<233;i++)g[i].clear();
	}
	void addedge(int from,int to,int cap)
	{
		g[from].pb(edge(to,cap,(int)g[to].size()));
		g[to].pb(edge(from,0,(int)g[from].size()-1));
	}
	int q[233],front,rear,level[233],iter[233];
	void bfs(int s)
	{
		front=rear=0;
		q[rear++]=s;
		memset(level,-1,sizeof(level));
		level[s]=0;
		while(front!=rear)
		{
			int x=q[front++];
			for(int i=0;i<(int)g[x].size();i++)
			{
				edge &e=g[x][i];
				if(e.cap>0&&level[e.to]==-1)
				{
					q[rear++]=e.to;
					level[e.to]=level[x]+1;
				}
			}
		}
	}
	int dfs(int x,int t,int f)
	{
		if(x==t)return f;
		for(int &i=iter[x];i<(int)g[x].size();i++)
		{
			edge &e=g[x][i];
			if(e.cap>0&&level[e.to]==level[x]+1)
			{
				int d=dfs(e.to,t,min(f,e.cap));
				if(d>0)
				{
					e.cap-=d;
					g[e.to][e.rev].cap+=d;
					return d;
				}
			}
		}
		return 0;
	}
	int maxflow(int s,int t)
	{
		int f,flow=0;
		for(;;)
		{
			bfs(s);
			if(level[t]==-1)return flow;
			memset(iter,0,sizeof(iter));
			while(f=dfs(s,t,inf))flow+=f;
		}
	}
}m1;
bool check()
{
	m1.clear();
	int s=k+cnt+1,t=k+cnt+2;
	for(int i=0;i<k;i++)
	{
		m1.addedge(s,i,to[ex[i]][ey[i]]);
		m1.addedge(i,ex[i]+k,inf);
		if(ex[i]!=ey[i])m1.addedge(i,ey[i]+k,inf);
	}
	for(int i=1;i<=cnt;i++)m1.addedge(i+k,t,num[i]-1);
	if(m1.maxflow(s,t)==n-cnt)return true;
	return false;
}
vector<int> v[7][7];
int ansx[200111],ansy[200111],id[7][7];
void setedge(int x,int y,int xx,int yy)
{
	if(x>y)
	{
		swap(x,y);
		swap(xx,yy);
	}
	if(id[x][y]>=(int)v[x][y].size()){id[x][y]++;return;}
	int eid=v[x][y][id[x][y]];
	ansx[eid]=xx;ansy[eid]=yy;
	if(x!=tx[eid])swap(ansx[eid],ansy[eid]);
	id[x][y]++;
}
int main()
{
	get1(n);
	if(n>=100000)num[6]=n-99999;
	if(n>=10000)num[5]=min(90000,n-9999);
	if(n>=1000)num[4]=min(9000,n-999);
	if(n>=100)num[3]=min(900,n-99);
	if(n>=10)num[2]=min(90,n-9);
	num[1]=min(9,n);piv[1]=1;for(int i=2;i<=6;i++)piv[i]=piv[i-1]*10;
	for(int i=1;i<=6;i++)if(num[i])cnt++;
	
	for(int i=1,sl,tl;i<n;i++)
	{
		scanf("%s%s",s,t);
		sl=strlen(s);tl=strlen(t);tx[i]=sl;ty[i]=tl;
		if(sl>tl)swap(sl,tl);to[sl][tl]++;
		v[sl][tl].pb(i);
	}
	for(int i=1;i<=cnt;i++)for(int j=i;j<=cnt;j++)
	{
		ex[k]=i;
		ey[k++]=j;
	}
	for(int mask=0;mask<(1<<k);mask++)
	{
		if(__builtin_popcount(mask)!=cnt-1)continue;
		if(!tree(mask))continue;
		for(int i=0;i<k;i++)if((mask>>i)&1)to[ex[i]][ey[i]]--;
		if(check())
		{
			memcpy(cur,piv,sizeof(cur));
			for(int i=0;i<k;i++)if((mask>>i)&1)
				setedge(ex[i],ey[i],piv[ex[i]],piv[ey[i]]);
			for(int i=0;i<k;i++)
			{
				for(int j=0;j<(int)m1.g[i].size();j++)
				{
					if(m1.g[i][j].to<=k+cnt&&m1.g[i][j].cap<inf)
					{
						int v=m1.g[i][j].to-k,t=inf-m1.g[i][j].cap;
						while(t--)
							setedge(ex[i]+ey[i]-v,v,piv[ex[i]+ey[i]-v],++cur[v]);
					}
				}
			}
			for(int i=1;i<n;i++)printf("%d %d\n",ansx[i],ansy[i]);
			return 0;
		}
		for(int i=0;i<k;i++)if((mask>>i)&1)to[ex[i]][ey[i]]++;
	}
	puts("-1");
	return 0;
}
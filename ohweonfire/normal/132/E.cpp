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
struct mincost_flow
{
	struct edge
	{
		int to,cap,cost,rev;
		edge(int to,int cap,int cost,int rev)
		{
			this->to=to;
			this->cap=cap;
			this->cost=cost;
			this->rev=rev;
		}
	};
	vector<edge> g[1024];
	int q[1024],front,rear,pre[1024],pree[1024],dist[1024];
	bool inq[1024];
	void addedge(int from,int to,int cap,int cost)
	{
//		printf("%d %d %d\n",from,to,cap,cost);
		g[from].pb(edge(to,cap,cost,(int)g[to].size()));
		g[to].pb(edge(from,0,-cost,(int)g[from].size()-1));
	}
	int mincostflow(int s,int t,int f)
	{
		int ret=0;
		while(f>0)
		{
			for(int i=0;i<1024;i++)dist[i]=inf;
			dist[s]=0;
			front=rear=0;q[rear++]=s;
			while(front!=rear)
			{
				int x=q[front++];front&=(1024-1);
				inq[x]=0;
				for(int i=0;i<(int)g[x].size();i++)
				{
					edge &e=g[x][i];
					if(e.cap>0&&dist[e.to]>dist[x]+e.cost)
					{
						dist[e.to]=dist[x]+e.cost;
						pre[e.to]=x;
						pree[e.to]=i;
						if(!inq[e.to])
						{
							inq[e.to]=1;
							q[rear++]=e.to;
							rear&=(1024-1);
						}
					}
				}
			}
			if(dist[t]==inf)return -1;
			int d=f,cur;
			for(cur=t;cur!=s;cur=pre[cur])
				d=min(d,g[pre[cur]][pree[cur]].cap);
			f-=d;
			ret+=d*dist[t];
			for(cur=t;cur!=s;cur=pre[cur])
			{
				edge &e=g[pre[cur]][pree[cur]];
				e.cap-=d;
				g[cur][e.rev].cap+=d;
			}
		}
		return ret;
	}
}thor;
int n,m,a[255],tot,match[255],cur[255],now[30];
int main()
{
	get2(n,m);
	for(int i=1;i<=n;i++)get1(a[i]);
	int S=n+n+m+1,T=S+1;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
		thor.addedge(i,j+n,1,a[i]==a[j]?0:__builtin_popcount(a[j]));
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)
		thor.addedge(i+n+n,j+n,1,__builtin_popcount(a[j]));
	for(int i=1;i<=n;i++)
	{
		thor.addedge(S,i,1,0);
		thor.addedge(i+n,T,1,0);
	}
	for(int i=1;i<=m;i++)thor.addedge(S,i+n+n,1,0);
	int ans=thor.mincostflow(S,T,n);
	for(int i=1;i<=n;i++)for(int j=0;j<(int)thor.g[i+n].size();j++)
		if(thor.g[i+n][j].to!=T&&thor.g[i+n][j].cap==1)match[i]=thor.g[i+n][j].to;
	vector<pii>cmd;
	for(int i=1;i<=n;i++)
	{
		if(match[i]>n)
		{
			cur[i]=match[i]-n-n;
			now[cur[i]]=a[i];
			cmd.pb(mp(cur[i],a[i]));
		}
		else
		{
			cur[i]=cur[match[i]];
			if(now[cur[i]]!=a[i])
			{
				cmd.pb(mp(cur[i],a[i]));
				now[cur[i]]=a[i];
			}
		}
		cmd.pb(mp(0,cur[i]));
	}
	printf("%d %d\n",(int)cmd.size(),ans);
	for(int i=0;i<(int)cmd.size();i++)
	{
		if(cmd[i].ff==0)printf("print(%c)\n",cmd[i].ss+'a'-1);
		else printf("%c=%d\n",cmd[i].ff+'a'-1,cmd[i].ss);
	}
	return 0;
}
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

int head[100111],nxt[100111],from[100111],to[100111],cost[100111],tot;
void addedge(int u,int v,int w)
{
	nxt[++tot]=head[u];head[u]=tot;
	from[tot]=u;to[tot]=v;cost[tot]=w;
}

LL dist[100111];
void dijkstra(int s)
{
	memset(dist,-1,sizeof(dist));
	priority_queue<pair<LL,int> >q;
	q.push(mp(0,s));dist[s]=0;
	while(!q.empty())
	{
		int x=q.top().ss;LL d=-q.top().ff;q.pop();
		if(dist[x]!=d)continue;
		for(int i=head[x];i;i=nxt[i])
		{
			if(dist[to[i]]==-1||dist[to[i]]>d+cost[i])
			{
				dist[to[i]]=d+cost[i];
				q.push(mp(-dist[to[i]],to[i]));
			}
		}
	}
}

int n,m,q,sum,tdist[100111];

vector<int> vs[1000111];
void update(int s)
{
	if(sum==0)return;
	memset(tdist,-1,sizeof(tdist));
	tdist[s]=0;vs[0].pb(s);
	int d=0;
	while(true)
	{
		while(d<=sum&&(int)vs[d].size()==0)d++;
		if(d==sum+1)break;
		int x=vs[d][(int)vs[d].size()-1];vs[d].pop_back();
		if(tdist[x]!=d)continue;
		for(int i=head[x];i;i=nxt[i])if(d+cost[i]<=sum)
		{
			if(tdist[to[i]]==-1||tdist[to[i]]>d+cost[i])
			{
				tdist[to[i]]=d+cost[i];
				vs[tdist[to[i]]].pb(to[i]);
			}
		}
	}
	sum=0;
	for(int i=1;i<=m;i++)if(dist[from[i]]!=-1)cost[i]=tdist[from[i]]+cost[i]-tdist[to[i]];
	for(int i=1;i<=n;i++)if(dist[i]!=-1)dist[i]+=tdist[i];
}

int main()
{
	get3(n,m,q);
	for(int i=1,u,v,w;i<=m;i++)
	{
		get3(u,v,w);
		addedge(u,v,w);
	}
	
	dijkstra(1);
	for(int i=1;i<=m;i++)if(dist[from[i]]!=-1)cost[i]=dist[from[i]]+cost[i]-dist[to[i]];
	
	for(int i=1,op,x,y;i<=q;i++)
	{
		get2(op,x);
		if(op==1)
		{
			if(dist[x]==-1)puts("-1");
			else
			{
				update(1);
				printf("%I64d\n",dist[x]);
			}
		}
		else
		{
			sum+=x;
			while(x--)
			{
				get1(y);
				cost[y]++;
			}
		}
	}
	return 0;
}
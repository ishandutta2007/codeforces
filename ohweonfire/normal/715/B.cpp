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

template<typename T> inline void updmax(T &x,const T y){if(x<y)x=y;}
template<typename T> inline void updmin(T &x,const T y){if(x>y)x=y;}

int cost[23333],nxt[23333],head[1111],to[23333],cnt;
void addedge(int x,int y,int z)
{
	cnt++;
	nxt[cnt]=head[x];head[x]=cnt;
	to[cnt]=y;cost[cnt]=z;
}
LL dist[1111];
priority_queue<pair<LL,int> > pq;
LL dijkstra(int s,int t)
{
	memset(dist,-1,sizeof(dist));
	dist[s]=0;
	pq.push(mp(0,s));
	LL d;int u,v;
	while(!pq.empty())
	{
		u=pq.top().ss;d=-pq.top().ff;pq.pop();
		if(d!=dist[u])continue;
		for(int i=head[u];i;i=nxt[i])
			if(dist[to[i]]==-1||dist[to[i]]>d+cost[i])
			{
				dist[to[i]]=d+cost[i];
				pq.push(mp(-dist[to[i]],to[i]));
			}
	}
	return dist[t]==-1?inf:dist[t];
}
int n,m,L,s,t;
int main()
{
	get3(n,m,L);get2(s,t);
	for(int i=1,u,v,w;i<=m;i++)
	{
		get3(u,v,w);
		if(w==0)w=inf;
		addedge(u,v,w);
		addedge(v,u,w);
	}
	LL tt=dijkstra(s,t);
	if(tt<L)
	{
		puts("NO");
		return 0;
	}
	else if(tt==L)
	{
		puts("YES");
		for(int u=0;u<n;u++)
			for(int k=head[u];k;k=nxt[k])if(k&1)
			{
				printf("%d %d %d\n",u,to[k],cost[k]);
				if(cost[k]==0)for(;;);
			}
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		if(cost[i+i-1]==inf)
		{
			cost[i+i-1]=cost[i+i]=1;
			if(dijkstra(s,t)>L)continue;
			int l=1,r=L,mid;
			while(l<=r)
			{
				mid=(l+r)>>1;
				cost[i+i-1]=cost[i+i]=mid;
				LL tt=dijkstra(s,t);
				if(tt==L)break;
				if(tt>L)r=mid-1;
				else l=mid+1;
			}
			if(dijkstra(s,t)!=L)for(;;);
			puts("YES");
			for(int u=0;u<n;u++)
				for(int k=head[u];k;k=nxt[k])if(k&1)
				{
					printf("%d %d %d\n",u,to[k],cost[k]);
					if(cost[k]==0)for(;;);
				}
			return 0;
		}
	}
	puts("NO");
	return 0;
}
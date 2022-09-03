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

const int maxn=300111;
vector<int>g[maxn];

int n,m,dist[maxn],q[maxn],fa[maxn],fr,rr;

void bfs(int x)
{
	memset(dist,-1,sizeof(dist));
	q[rr++]=x;dist[x]=0;
	for(;fr<rr;fr++)
	{
		x=q[fr];
		for(auto&v:g[x])if(dist[v]==-1)
		{
			dist[v]=dist[x]+1;
			fa[v]=x;
			q[rr++]=v;
		}
	}
}

int vs[maxn],tot;
bool use[maxn];
void dfs(int x)
{
	vs[++tot]=x;use[x]=1;
	for(auto&v:g[x])if(!use[v])dfs(v);
}

int main()
{
	get2(n,m);
	if(n==1)
	{
		puts("0\n1");
		return 0;
	}
	for(int i=1,u,v;i<=m;i++)
	{
		get2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	bfs(1);
	if(dist[n]==1)printf("1\n%d %d\n",1,n);
	else if(dist[n]==2)printf("2\n%d %d %d\n",1,fa[n],n);
	else if(dist[n]==3)printf("3\n%d %d %d %d\n",1,fa[fa[n]],fa[n],n);
	else if(dist[q[rr-1]]>1)
	{
		for(int i=1;i<=n;i++)if(dist[i]==2)
		{
			printf("4\n%d %d %d %d %d\n",1,fa[i],i,1,n);
			return 0;
		}
	}
	else
	{
		for(int i=1;i<rr;i++)if(!use[q[i]])
		{
			tot=0;dfs(q[i]);
			for(int j=1;j<=tot;j++)
			{
				int x=vs[j];
				if(tot!=(int)g[x].size()-1)
				{
					memset(use,0,sizeof(use));
					for(auto&y:g[x])use[y]=1;use[x]=1;
					for(auto&y:g[x])if(y>1)
					{
						for(auto&z:g[y])if(!use[z])
						{
							printf("5\n%d %d %d %d %d %d\n",1,x,y,z,x,n);
							return 0;
						}
					}
				}
			}
		}
		puts("-1");
	}
	return 0;
}
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cassert>
#include<set>
#include<map>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=200010;
struct Edge
{
	int x,y,z,typ;
	bool operator<(const Edge&a)const{return z<a.z;}
}E[N];
vector<int>g[N];
int fa[N],n,m,q[N];
set<int>s;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
bool bfs(int x)
{
	int cnt=0,w;
	q[w=1]=x;s.erase(x);
	rep(i,w)
	{
		int u=q[i];
		fa[u]=x;cnt++;
		auto it=s.begin();
		for(auto i:g[u])
		{
			for(;it!=s.end()&&(*it)<i;)
			{
				int x=*it;it++;
				q[++w]=x;
				s.erase(x);
			}
			if(it!=s.end()&&(*it)==i)it++;
		}
		for(;it!=s.end();)
		{
			int x=*it;it++;
			q[++w]=x;
			s.erase(x);
		}
	}
	int m=0;
	rep(i,w)for(auto j:g[q[i]])if(fa[j]==x)m++;
	return 1ll*cnt*(cnt-1)/2-m/2>=cnt;
}
int main()
{
	scanf("%d%d",&n,&m);
	int val=0;
	rep(i,m)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		g[x].pb(y);
		g[y].pb(x);
		val^=z;
		E[i]={x,y,z,0};
	}
	bool flag=0;
	rep(i,n)fa[i]=i,s.insert(i),sort(g[i].begin(),g[i].end());
	rep(i,n)if(fa[i]==i)flag|=bfs(i);
	sort(E+1,E+m+1);
	LL ans=0;
	rep(i,m)
	{
		int a=find(E[i].x),b=find(E[i].y);
		if(a==b)continue;
		ans+=E[i].z;
		fa[a]=b;
		E[i].typ=1;
	}
	rep(i,n)fa[i]=i;
	rep(i,m)if(E[i].typ==1)fa[find(E[i].x)]=find(E[i].y);
	rep(i,m)if(!E[i].typ&&find(E[i].x)==find(E[i].y))E[i].typ=2;
	if(flag)val=0;
	else rep(i,m)if(!E[i].typ)val=min(val,E[i].z);
	printf("%lld\n",ans+val);
    return 0;
}
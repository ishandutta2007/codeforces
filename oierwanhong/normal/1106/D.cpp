#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstdlib> 
typedef long long ll;
const ll INF=1ll<<60;
#define maxn 100001
#define maxm 200003


std::priority_queue<ll,std::vector<ll>,std::greater<ll> >q;

struct Edge
{
	ll v,nxt;
}e[maxm];
ll last[maxn],cnt=0;
void adde(ll u,ll v)
{
	++cnt;
	e[cnt].v=v;
	e[cnt].nxt=last[u];last[u]=cnt;
}

ll n,m;
bool vis[maxn];
int main()
{
	std::cin>>n>>m;
	ll u,v;
	for(ll i=1;i<=m;++i)
	{
		std::cin>>u>>v;
		adde(u,v);
		adde(v,u);
	}
	q.push(1);
	for(ll i=1;i<=n;++i)
	{
		while(vis[q.top()])q.pop();
		u=q.top();q.pop();
		std::cout<<u<<" ";
		vis[u]=1;
		for(ll i=last[u];i;i=e[i].nxt)
		{
			if(!vis[e[i].v])q.push(e[i].v);
		}
	}
	return 0;
}
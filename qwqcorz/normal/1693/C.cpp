#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

vector<int>e[N];
bool vis[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
int dis[N],tot[N];

signed main()
{
	int n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		e[v].push_back(u);
		tot[u]++;
	}
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	q.push({dis[n]=0,n});
	while (!q.empty())
	{
		int now=q.top().second; q.pop();
		if (vis[now]) continue;
		vis[now]=1;
		for (int to:e[now])
		if (dis[to]>dis[now]+(tot[to]--))
		{
			dis[to]=dis[now]+tot[to]+1;
			q.push({dis[to],to});
		}
	}
	print(dis[1]);
	
	return 0;
}
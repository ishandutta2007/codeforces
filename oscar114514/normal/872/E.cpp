#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define maxn 200005
#define ll long long
using namespace std;
struct edge
{
	int u, v;
	edge *next;
}pool[maxn << 1], *h[maxn];
int egcnt = 0;
void addedge(int u, int v)
{
//	cout<<"ADDEDGE"<<u<<" "<<v<<endl;
	edge *new1 = &pool[egcnt++];
	new1->u = u, new1->v = v, new1->next = h[u], h[u] = new1;
}
int size[maxn];
int dfn[maxn], low[maxn], stack[maxn], top = 0;
bool vis[maxn];
int dfcnt = 1;
bool inq[maxn];
int bccnt = 1;
int bcnum[maxn];
void dfs1(int a, int fa)
{
	dfn[a] = low[a] = dfcnt++;
	vis[a] = 1;
	stack[top++] = a, inq[a] = 1;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(!vis[p->v])
			dfs1(p->v, a), low[a] = min(low[a], low[p->v]);
		else
			if(inq[p->v] && p->v != fa)
				low[a] = min(low[a], dfn[p->v]);
	}
	if(dfn[a] == low[a])
	{
		int j;
		do
		{
			j = stack[top - 1];
			top--, 
			inq[j] = 0, 
			size[bccnt]++;
			bcnum[j] = bccnt;
		}while(j != a);
		bccnt++;
	}
}
map<int, int> id[2];
ll dp[2][maxn];
int tp[maxn];
ll pw[maxn];
const ll mod = 1000000007;
void dfs2(int a, int fa)
{
	vis[a] = 1;
	for(edge *p = h[a]; p; p = p->next)
		if(p->v != fa)
			dfs2(p->v, a);
	dp[1][a] = 1;
	for(edge *p = h[a]; p; p = p->next)
		if(p->v != fa)
			dp[1][a] *= dp[1][p->v], 
			dp[1][a] %= mod;
	dp[0][a] = dp[1][a];
	ll ns = 1;
	for(edge *p = h[a]; p; p = p->next)
		if(p->v != fa)
			ns *= (dp[1][p->v] - dp[0][p->v]), 
			ns %= mod;
	if(!tp[a]) 
		dp[0][a] *= 2, 
		dp[0][a] %= mod,
		dp[1][a] *= 2, 
		dp[1][a] %= mod,
		dp[0][a] -= ns, 
		dp[0][a] %= mod;
	else 
		dp[1][a] *= pw[size[a]], 
		dp[1][a] %= mod,
		dp[0][a] = dp[1][a]; 
	if(dp[0][a] < 0) dp[0][a] += mod;	
//	cout<<a<<" "<<fa<<" "<<dp[0][a]<<" "<<dp[1][a]<<" "<<tp[a]<<" "<<size[a]<<endl;
} 
int u[maxn], v[maxn];

int main()
{
	pw[0] = 1;
	for(int i = 1; i < maxn; i++)
		pw[i] = pw[i - 1] * 2, pw[i] %= mod;
	int n;
	scanf("%d", &n);
	int idcnt = 1;
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if(!id[0][x]) id[0][x] = idcnt++;
		if(!id[1][y]) id[1][y] = idcnt++;
		addedge(id[0][x], id[1][y]), 
		addedge(id[1][y], id[0][x]);
	}
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i < idcnt; i++)
		if(!vis[i])
			dfs1(i, 0);
//	cout<<bccnt<<endl;
//	for(int i = 1; i < idcnt; i++)
//		cout<<i<<" "<<bcnum[i]<<endl;
	for(int i = 1; i < bccnt; i++)
		if(size[i] >= 2)
			tp[i] = 1;
	int neg = 0;
	for(int i = 1; i < idcnt; i++)
		for(edge *p = h[i]; p; p = p->next)
			if(bcnum[p->v] != bcnum[i])
				u[neg] = bcnum[p->v], 
				v[neg++] = bcnum[i];
	egcnt = 0;
	for(int i = 0; i < maxn; i++)
		h[i] = NULL;
	for(int i = 0; i < neg; i++)
		addedge(u[i], v[i]);
//		cout<<"ADE"<<u[i]<<" "<<v[i]<<endl;
	ll ans = 1;
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i < bccnt; i++)
		if(!vis[i])
			dfs2(i, 0), ans *= dp[0][i], ans %= mod;
	printf("%I64d\n", ans);
	return 0;
}
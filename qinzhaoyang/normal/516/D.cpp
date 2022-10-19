#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
typedef long long ll;

struct Edge {int nxt , to; ll w;} e[N << 1];
int first[N] , cur;
void connect(int x , int y , ll z) {e[++cur] = (Edge){first[x] , y , z} , first[x] = cur;}

int n , q;
ll dis[N] , dp[N];

void dfs1(int x , int fa)
{
	for(int i = first[x]; i; i = e[i].nxt)
		if(e[i].to != fa)
			dfs1(e[i].to , x) , dis[x] = max(dis[x] , dis[e[i].to] + e[i].w);
}

void dfs2(int x , int fa , ll f)
{
	ll max1 = f , max2 = 0 , s = fa;
	dp[x] = f;
	for(int i = first[x]; i; i = e[i].nxt)
		if(e[i].to != fa)
		{
			ll t = dis[e[i].to] + e[i].w;
			dp[x] = max(dp[x] , t);
			if(t > max1)
				max2 = max1 , max1 = t , s = e[i].to;
			else if(t > max2)
				max2 = t;
		}
	for(int i = first[x]; i; i = e[i].nxt)
		if(e[i].to != fa)
				dfs2(e[i].to , x , e[i].w + (e[i].to == s ? max2 : max1));
}

int wh[N];

void get(int x , int fa)
{
	wh[x] = fa;
	for(int i = first[x]; i; i = e[i].nxt)
		if(e[i].to != fa)
			get(e[i].to , x); 
}

int fa[N] , siz[N];
int find(int x)
{
	if(fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

void connect(int x , int y)
{
	if(find(x) != find(y))
	{
		siz[fa[y]] += siz[fa[x]];
		fa[fa[x]] = fa[y];
	}
}

int v[N];
bool cmp(int x , int y)
{
	if(dp[x] == dp[y])
		return x < y;
	return dp[x] < dp[y];
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int u , v; ll w; cin >> u >> v >> w;
		connect(u , v , w) , connect(v , u , w);
	}
	dfs1(1 , 0) , dfs2(1 , 0 , 0);
	ll root = 0 , Min = 1000000000000000000;
	for(int i = 1; i <= n; i++)
		if(dp[i] < Min)
			Min = dp[i] , root = i;
	for(int i = 1; i <= n; i++)
		v[i] = i;
	sort(v + 1 , v + n + 1 , cmp);
	get(root , root);
	cin >> q;
	while(q--)
	{
		ll L , ans = 0; cin >> L;
		for(int i = 1; i <= n; i++)
			fa[i] = i , siz[i] = 1;
		for(int i = n , now = n; i >= 1; i--)
		{
			while(dp[v[now]] - dp[v[i]] > L)
				--siz[find(v[now])] , now--;
			ans = max(ans , (ll)siz[find(v[i])]);
			connect(v[i] , wh[v[i]]);
		}
		cout << ans << endl;
	}
	return 0;
}
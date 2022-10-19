#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;

struct Hash {int f , s;};
int MOD1 = 1004535809 , MOD2 = 167772161;
int s1[N] , s2[N] , v1[N] , v2[N];

int add(int x , int y , int MOD) {return x + y >= MOD ? x + y - MOD : x + y;}
int sub(int x , int y , int MOD) {return x < y ? x + MOD - y : x - y;}
int mul(int x , int y , int MOD) {return 1ll * x * y % MOD;} 
int Pow(int x , int y , int MOD) {int ret = 1;while(y){if(y & 1)ret = mul(ret , x , MOD);x = mul(x , x , MOD) , y >>= 1;}return ret;}

Hash operator + (Hash H1 , Hash H2) {return (Hash){add(H1.f , H2.f , MOD1) , add(H1.s , H2.s , MOD2)};}
Hash operator - (Hash H1 , Hash H2) {return (Hash){sub(H1.f , H2.f , MOD1) , sub(H1.s , H2.s , MOD2)};}
Hash operator * (Hash H1 , Hash H2) {return (Hash){mul(H1.f , H2.f , MOD1) , mul(H1.s , H2.s , MOD2)};}
int operator == (Hash H1 , Hash H2) {return (H1.f == H2.f) && (H1.s == H2.s);} 
Hash operator << (Hash H1 , int t) {return (Hash){mul(H1.f , s1[t] , MOD1) , mul(H1.s , s2[t] , MOD2)};}
Hash operator >> (Hash H1 , int t) {return (Hash){mul(H1.f , v1[t] , MOD1) , mul(H1.s , v2[t] , MOD2)};}

struct Edge {int nxt , to;} e[N << 1];
int first[N] , cur;

void con(int x, int y)
{
	e[++cur] = (Edge){first[x], y};
	first[x] = cur;
}

int lg2[N << 1];

void init(int n)
{
	s1[0] = s2[0] = 1;
	s1[1] = 233 , s2[1] = 239;
	for(int i = 2; i <= n; i++)
		s1[i] = mul(s1[i - 1] , s1[1] , MOD1);
	for(int i = 2; i <= n; i++)
		s2[i] = mul(s2[i - 1] , s2[1] , MOD2);
	for(int i = 0; i <= n; i++)
		v1[i] = Pow(s1[i] , MOD1 - 2 , MOD1);
	for(int i = 0; i <= n; i++)
		v2[i] = Pow(s2[i] , MOD2 - 2 , MOD2);
	for(int i = 1; i <= 2 * n; i++)
		lg2[i] = log2(i);
}

int n , m;
char s[N];

int fa[N][21] , dep[N] , dfn[N] , top[N] , son[N] , dis[N] , cur_dfn , mp[N];
vector <int> up[N] , down[N];
int d[N << 1] , rmq[N << 1][21] , tot , wh[N];

void dfs1(int x , int f)
{
	int Max = 0;
	fa[x][0] = f , dep[x] = dep[f] + 1 , dis[x] = 1;
	for(int i = first[x]; i; i = e[i].nxt)
		if(e[i].to != f)
		{
			dfs1(e[i].to , x);
			dis[x] = max(dis[x] , dis[e[i].to] + 1);
			if(dis[e[i].to] > Max)
				Max = dis[e[i].to] , son[x] = e[i].to;
		}
}

void dfs2(int x , int t)
{
	if(x == t)
	{
		down[x].push_back(x) , up[x].push_back(x);
		for(int i = 1 , tmp = son[x]; i <= dis[x]; i++ , tmp = son[tmp])
			down[x].push_back(tmp);
		for(int i = 1 , tmp = fa[x][0]; i <= dis[x]; i++ , tmp = fa[tmp][0])
			up[x].push_back(tmp);
	}
	top[x] = t , dfn[x] = ++cur_dfn , mp[cur_dfn] = x;
	d[++tot] = x , wh[x] = tot;
	if(son[x])
		dfs2(son[x] , t) , d[++tot] = x;
	for(int i = first[x]; i; i = e[i].nxt)
		if(e[i].to != fa[x][0] && e[i].to != son[x])
			dfs2(e[i].to , e[i].to) , d[++tot] = x;
}

int query(int x , int y)
{
	if(x > y)
		swap(x , y);
	int t = lg2[y - x + 1];
	return min(rmq[x][t] , rmq[y - (1 << t) + 1][t]);
}

int LCA(int u , int v)
{
	return mp[query(wh[u] , wh[v])];
}

Hash h1[N] , h2[N];

void get_hash(int x)
{
	h1[x] = ((Hash){s[x] , s[x]} << (dep[x] - 1)) + h1[fa[x][0]];
	h2[x] = (h2[fa[x][0]] << 1) + (Hash){s[x] , s[x]};
	for(int i = first[x]; i; i = e[i].nxt)
		if(e[i].to != fa[x][0])
			get_hash(e[i].to);
}

int kfa(int x , int k)
{
	if(dep[x] <= k)
		return 0;
	if(k == 0)
		return x;
	x = fa[x][lg2[k]] , k -= (1 << lg2[k]);
	int tmp = dep[x] - dep[top[x]];
	if(tmp >= k)
		return down[top[x]][tmp - k];
	else
		return up[top[x]][k - tmp];
}

Hash get(int u , int v)
{
	if(dep[u] >= dep[v])
		return (h1[u] - h1[v]) >> dep[v];
	else if(dep[u] < dep[v])
		return h2[v] - (h2[u] << (dep[v] - dep[u]));
}

int main()
{
	scanf("%d" , &n) , init(n);
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	for(int i = 1 , u , v; i < n; i++)
	{
		scanf("%d%d" , &u , &v);
		con(u , v) , con(v , u);
	}
	dfs1(1 , 0) , dfs2(1 , 1);
	for(int j = 1; j <= 20; j++)
		for(int i = 1; i <= n; i++)
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
	for(int i = 1; i <= tot; i++)
		rmq[i][0] = dfn[d[i]];
	for(int j = 1; (1 << j) <= tot; j++)
		for(int i = 1; i + (1 << j) <= tot; i++)
			rmq[i][j] = min(rmq[i][j - 1] , rmq[i + (1 << j - 1)][j - 1]);
	get_hash(1);
	scanf("%d" , &m);
	while(m--)
	{
		int u1 , v1 , u2 , v2;
		scanf("%d%d%d%d" , &u1 , &v1 , &u2 , &v2);
		int lca1 = LCA(u1 , v1) , lca2 = LCA(u2 , v2);
		int l = 0 , r = min(dep[u1] + dep[v1] - 2 * dep[lca1] + 1 , dep[u2] + dep[v2] - 2 * dep[lca2] + 1);
		while(l <= r)
		{
			int mid = (l + r) >> 1;
			Hash H1 , H2;
			if(mid <= dep[u1] - dep[lca1] + 1)
				H1 = get(u1 , kfa(u1 , mid));
			else
				H1 = (get(u1 , fa[lca1][0]) << (mid - (dep[u1] - dep[lca1] + 1))) + get(lca1 , kfa(v1 , dep[v1] - dep[lca1] - (mid - (dep[u1] - dep[lca1] + 1))));
			if(mid <= dep[u2] - dep[lca2] + 1)
				H2 = get(u2 , kfa(u2 , mid));
			else
				H2 = (get(u2 , fa[lca2][0]) << (mid - (dep[u2] - dep[lca2] + 1))) + get(lca2 , kfa(v2 , dep[v2] - dep[lca2] - (mid - (dep[u2] - dep[lca2] + 1))));
			if(H1 == H2)
				l = mid + 1;
			else
				r = mid - 1;
		}
		printf("%d\n" , r);
	}
	return 0;
}
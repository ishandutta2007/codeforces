
// Problem : C. Digit Tree
// Contest : Codeforces - Codeforces Round #372 (Div. 1)
// URL : https://codeforces.com/problemset/problem/715/C
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
map<ll, int> app;
int lst[100005], to[200005], pre[200005], w[200005], tot; 
int sz[100005], mx[100005], seq[100005], cnt, n, m; 
ll p[100005], inv[100005], res; 
bool vis[100005];  
inline void add_edge(int u, int v, int _w)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	w[tot] = _w; 
	lst[u] = tot++; 
}
void dfs(int u, int fa = -1)
{
	mx[u] = 0; 
	sz[u] = 1;
	seq[cnt++] = u; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (vis[to[i]] || to[i] == fa)
			continue;
		dfs(to[i], u); 
		sz[u] += sz[to[i]]; 
		mx[u] = max(mx[u], sz[to[i]]); 
	}
}
ll calc(int u, int fa, int dep, ll cur, bool f)
{
	ll res = 0; 
	if (!cur && f)
		res++; 
	res += app[((m - inv[dep] * cur % m) % m + m) % m]; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (to[i] == fa || vis[to[i]])
			continue; 
		res += calc(to[i], u, dep + 1, (cur * 10 + w[i]) % m, f); 
	}
	return res; 
}
void add(int u, int fa, int dep, ll cur)
{
	app[cur]++;  
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (to[i] == fa || vis[to[i]])
			continue; 
		add(to[i], u, dep + 1, (cur + p[dep] * w[i]) % m); 
	}
}
void calc_tree(int u)
{
	cnt = 0; 
	dfs(u); 
	int rt = seq[0]; 
	for (int i = 1; i < cnt; i++)
	{
		if (max(mx[seq[i]], cnt - mx[seq[i]] - 1) < max(mx[rt], cnt - mx[rt] - 1))
			rt = seq[i]; 
	}
	vis[rt] = true; 
	cnt = 0; 
	app.clear(); 
	for (int i = lst[rt]; ~i; i = pre[i])
	{
		if (vis[to[i]])
			continue; 
		seq[cnt++] = i; 
		res += calc(to[i], rt, 1, w[i], true); 
		add(to[i], rt, 1, w[i]); 
	}
	res += app[0]; 
	app.clear(); 
	for (int i = cnt - 1; i >= 0; i--)
	{
		res += calc(to[seq[i]], rt, 1, w[seq[i]], false);
		add(to[seq[i]], rt, 1, w[seq[i]]); 
	}
	for (int i = lst[rt]; ~i; i = pre[i])
	{
		if (!vis[to[i]])
			calc_tree(to[i]); 
	}
}
void ex_gcd(ll a, ll b, ll &x, ll &y)
{
	if (!b)
	{
		x = 1;
		y = 0; 
		return; 
	}
	ll x0, y0; 
	ex_gcd(b, a % b, x0, y0); 
	x = y0; 
	y = x0 - a / b * y0; 
}
int main()
{
	fio;
	memset(lst, -1, sizeof(lst)); 
	cin>>n>>m;
	ll x, y; 
	ex_gcd(10, m, x, y); 
	x = (x + m) % m; 
	p[0] = inv[0] = 1; 
	for (int i = 1; i < 100005; i++)
	{
		p[i] = p[i - 1] * 10 % m; 
		inv[i] = inv[i - 1] * x % m; 
	}
	for (int i = 1; i < n; i++)
	{
		int u, v, w; 
		cin>>u>>v>>w;
		add_edge(u, v, w % m); 
		add_edge(v, u, w % m); 
	}
	calc_tree(0); 
	cout<<res;
}
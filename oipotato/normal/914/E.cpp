#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
#define pb push_back
#define x0 fuckcjb
#define x1 fuckshb
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define y0 fucksub
#define y1 fuckjtjl
#define rep(i, x, y) for(int i = x; i <= y; i ++)
const int M = 2e6 + 10;
const int INF = 1e9 + 7;
const int N = 2e5 + 10;
inline int getint()
{
	int x = 0, f = 1;
	char ch;
	for (ch=getchar();ch < '0' || ch > '9';ch=getchar())if (ch == '-') f = -1; 
	for (;ch >= '0' && ch <= '9';ch=getchar())x = x * 10 + ch - '0';
	return x * f;
}
struct vec
{
	long long to, next;
}edge[N * 2];
long long g[N], cnt, n, root, rootf, sum, ct[N],size[N];
bool tag[N];
long long tim[M],gtmcjb[M], T;
char s[N];
long long potatoANS[N], tedge[N], tot;
inline void insert(long long x,long long y)
{
	edge[++ cnt].to = y;
	edge[cnt].next = g[x];
	g[x] = cnt;
}
inline void inserteroot(long long x,long long y){insert(x, y);insert(y, x);}
void getroot(long long x, long long fa)
{
	size[x] = 1;
	ct[x] = 0;
	long long i,y;
	for(i = g[x]; i; i = edge[i].next)
	{
		y = edge[i].to;
		if(!tag[y] && y != fa)
		{
			getroot(y, x);
			size[x] += size[y];
			ct[x] = max(ct[x], size[y]);
		}
	}
	ct[x] = max(ct[x], sum - size[x]);
	if(ct[x] < ct[root]) root = x, rootf = fa;
}
long long oipotato(long long x)
{
	if(tim[x] != T) gtmcjb[x] = 0;
	return gtmcjb[x];
}
long long dfs1(long long x, long long fa, long long now)
{
	long long i,y;
	long long res = 0;
	now ^= (1 << s[x]);
	res += oipotato(now);
	rep(i, 0, 19)
		(res += oipotato(now ^ (1 << i)));
	for(i = g[x]; i; i = edge[i].next)
	{
		y=edge[i].to;
		if(!tag[y] && y != fa)
			res += dfs1(y, x, now);
	}
	potatoANS[x] += res;
	return res;
}
void add(long long x, long long y)
{
	if(tim[x] != T)	gtmcjb[x] = 0;
	gtmcjb[x] += y;
	tim[x] = T;
}
void dfs2(long long x, long long fa, long long now)
{
	long long i,y;
	now ^= (1 << s[x]);
	add(now, 1);
	for(i = g[x]; i; i = edge[i].next)
	{
		y = edge[i].to;
		if(!tag[y] && y != fa)
			dfs2(y, x, now);
	}
}
void work(long long x)
{
	long long i,y;
	tag[x] = 1;
	T ++;
	add(0, 1);
	tot = 0;
	for(i = g[x]; i; i = edge[i].next)
	{
		y = edge[i].to;
		if(!tag[y])
		{
			tedge[++ tot] = y;
			potatoANS[x] += dfs1(y, x, 1 << s[x]);
			dfs2(y, x, 0);
		}
	}
	T ++;
	for(i = tot; i; i --)
	{
		y = tedge[i];
		dfs1(y, x, 1 <<s[x]);
		dfs2(y, x, 0);
	}
	for(i = g[x]; i; i = edge[i].next)
	{
		y = edge[i].to;
		if(!tag[y])
		{
			sum = size[y];
			root = 0;
			getroot(y, x);
			size[rootf] = sum - size[root];
			work(root);
		}
	}
}
int main()
{
	n = getint();
	rep(i, 1, n - 1)
	{
		int x = getint();
		int y = getint();
		inserteroot(x,y);
	}
	scanf("%s",s + 1);
	rep(i, 1, n) s[i] -= 'a';
	ct[0] = INF;
	sum = n;
	getroot(1, 0);
	work(root);
	rep(i, 1, n)
		printf("%lld%c", potatoANS[i] + 1,i==n?'\n':' ');
	return 0;
}
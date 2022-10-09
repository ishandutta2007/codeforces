#include <bits/stdc++.h>

const int N = 6e5 + 50;
typedef long long ll;

int rt, n, k, a[N], d[N], f[N], g[N], head[N], nxt[N], ver[N], pr[N], cnt;
int ans[N], tot;
bool vis[N];

inline void add(int u, int v)
{
	nxt[++cnt] = head[u];
	ver[cnt] = v;
	++d[v];
	head[u] = cnt;
}

inline void topo()
{
	std::queue<int> que;
	if (!d[rt] && !vis[rt]) que.push(rt);
	while (!que.empty())
	{
		int x = que.front(); que.pop();
		for (int t = x; t; t = pr[t])
		{	
			ans[++tot] = t;
			for (int i = head[t]; i; i = nxt[i])
			{
				int y = ver[i];
				if (!--d[y]) que.push(y);
			}
		}
	}
}

template <int T>
struct fast_io
{
	char p[T], q[T], * p1, * p2, * q1, * q2;
	fast_io()
	{
		p1 = p2 = p;
		q1 = q, q2 = q + T;
	}
	inline char gc()
	{
		return p1 == p2 && (p2 = (p1 = p) + fread(p, 1, T, stdin), p1 == p2) ? EOF : *p1++;
	}
	inline void pc(char c)
	{
		if (q1 == q2) q2 = (q1 = q) + fwrite(q, 1, T, stdout);
		*q1++ = c;
	}
	~fast_io()
	{
		fwrite(q, 1, q1 - q, stdout);
	}
};
fast_io<1 << 18> io;
inline ll read()
{
	ll res = 0;
	char ch;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return res;
}
inline void read(char *s)
{
	char ch;
	do ch = io.gc(); while (!isalpha(ch));
	do *s++ = ch, ch = io.gc(); while (isalpha(ch));
	*s = 0;
}
inline int rb()
{
	char ch;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	return ch - 48;
}
inline void put(ll x)
{
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) put(x / 10);
	io.pc(48 + x % 10);
}
inline void output(ll x, char ch = ' ')
{
	put(x);
	io.pc(ch);
}

int main()
{ 
	n = read(), k = read();
	for (int i = 1; i <= n; ++i)
	{
		f[i] = read();
		if (!f[i]) rt = i;
	}
	for (int i = 1; i <= k; ++i)
	{
		int x = read(), y = read();
		pr[x] = y;		
		vis[y] = true;
	}
	for (int i = 1; i <= n; ++i)
		if (!vis[i])
		{

			for (int k = i; k; k = pr[k])
			{
				g[k] = i;
				if (f[k] && g[f[k]] != i) add(f[k], i);
			}
		}
	topo();
	if (tot != n) output(0);
	else for (int i = 1; i <= n; ++i) output(ans[i]);
	return 0;
}
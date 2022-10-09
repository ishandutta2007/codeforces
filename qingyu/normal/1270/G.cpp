#include <bits/stdc++.h>

const int N = 1e6 + 50;

int n, a[N], head[N], nxt[N], ver[N], fa[N], dep[N], cnt;
bool vis[N];

inline void add(int u, int v)
{
	nxt[++cnt] = head[u];
	ver[cnt] = v;
	head[u] = cnt;
}

inline void report(int x, int y)
{
	std::vector<int> v;
	while (x != y)
	{
		if (dep[x] < dep[y]) std::swap(x, y);
		v.push_back(x);
		x = fa[x];
	}
	v.push_back(x);
	printf("%d\n", v.size());
	for (int x : v) printf("%d ", x);
	printf("\n");
}

bool dfs(int x, int f = 0)
{
	fa[x] = f, dep[x] = dep[f] + 1, vis[x] = true;
	for (int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if (vis[y])
		{
			report(x, y);
			return true;
		}
		else if (dfs(y, x)) return true;;
	}
	return false;
}

template<int T>
struct fast_io
{
	char p[T], q[T], *p1, *p2, *q1, *q2;

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
		if (q1 == q2)
		{
			fwrite(q, 1, T, stdout);
			q1 = q;
		}
		*q1++ = c;
	}

	~fast_io()
	{
		fwrite(q, 1, q1 - q, stdout);
	}
};

fast_io<2000000> io;

inline int64_t read()
{
	int64_t r = 0, neg = 1;
	char ch;
	do
	{
		ch = io.gc();
		if (ch == '-') neg = -1;
	}
	while (ch < 48 || ch > 57);
	do r = r * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return r * neg;
}

inline void putint(int x)
{
	if (x < 0)
	{
		io.pc('-');
		putint(-x);
		return;
	}
	if (x / 10) putint(x / 10);
	io.pc(48 + x % 10);
}

inline void output(int x, char ch = ' ')
{
	putint(x);
	io.pc(ch);
}

int main()
{
	int t = read();
	while (t--)
	{
		n = read();		
		memset(head, 0, n + 1 << 2);
		memset(vis , 0, n + 1 << 2);
		for (int i = 1; i <= n; ++i) a[i] = read(), add(i, i - a[i]);
		dfs(1);
	}
	return 0;
}
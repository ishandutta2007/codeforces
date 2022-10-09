#include <bits/stdc++.h>

const int N = 3005;
const int mod = 1e9 + 7;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }

inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

inline int fastpow(int x, int p)
{
	int r = 1;
	while (p)
	{
		if (p & 1) pud(r, x);
		pud(x, x);
		p >>= 1;
	}
	return r;
}

int n, len, d[N], bel[N], dist[N][N], fact[N], inv[N];
bool circle[N];
std::vector<int> G[N];

inline void find_circle()
{
	for (int x = 1; x <= n; ++x) circle[x] = true;
	std::queue<int> que;
	for (int i = 1; i <= n; ++i) if (d[i] == 1) que.push(i), circle[i] = false;
	while (!que.empty())
	{
		int x = que.front(); que.pop();
		for (int y : G[x])
			if (--d[y] == 1)
			{
				que.emplace(y);
				circle[y] = false;
			}
	}
}

inline void calc(int x, int *d)
{
	d[x] = 0;
	std::queue<int> que; que.push(x);
	while (!que.empty())
	{
		int x = que.front(); que.pop();
		for (int y : G[x])
			if (d[y] > d[x] + 1)
			{
				d[y] = d[x] + 1;
				que.push(y);
			}
	}
}

inline void init()
{
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) fact[i] = mul(i, fact[i - 1]);
	inv[n] = fastpow(fact[n], mod - 2);
	for (int i = n - 1; i >= 0; --i) inv[i] = mul(i + 1, inv[i + 1]);
	for (int i = 1; i <= n; ++i) pud(inv[i], fact[i - 1]);
}

template<int T>
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

inline long long read()
{
	long long r = 0, neg = 1;
	char ch;
	do
	{
		ch = io.gc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do r = r * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return r * neg;
}

inline int read(char *s)
{
	char ch;
	int len = 0;
	do ch = io.gc(); while (!isalpha(ch));
	do *s++ = ch, ch = io.gc(), ++len; while (isalpha(ch));
	*s = 0;
	return len;
}

inline char rc()
{
	char ch;
	do ch = io.gc(); while (ch != '.' && ch != '#');
	return ch;
}

inline void putint(long long x)
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

inline void output(long long x, char ch = ' ')
{
	putint(x);
	io.pc(ch);
}

inline void outputs(const char *s)
{
	while (*s) io.pc(*s++);
	io.pc('\n');
}

void dfs(int x, int col, int f = 0)
{
	bel[x] = col;
	for (int y : G[x])
		if (!circle[y] && y != f)
		{
			dfs(y, col, x);
		}	
}

int main()
{
	n = read();
	for (int i = 1; i <= n; ++i)
	{
		int x = read() + 1, y = read() + 1;
		G[x].push_back(y), G[y].push_back(x);
		++d[x], ++d[y];
	}
	find_circle();
	memset(dist, 0x3f, sizeof dist);
	for (int x = 1; x <= n; ++x) calc(x, dist[x]);
	for (int x = 1; x <= n; ++x) if (circle[x]) dfs(x, x, 0), ++len;
	init();
	double ans = 0;
	for (int x = 1; x <= n; ++x)
		for (int y = 1; y <= n; ++y)
		{
			if (bel[x] == bel[y])
			{
				int d = dist[x][y];
				ans += 1.0 / (d + 1);
				//upd(ans, inv[d + 1]);
			}
			else
			{
				int u = bel[x], v = bel[y];
				int d1 = dist[u][v], d2 = len - dist[u][v];
				ans += 1.0 / (dist[x][y] + 1);
				ans += 1.0 / (dist[x][y] - d1 + d2 + 1);
				ans -= 1.0 / (dist[x][y] + d2);
			}
		}
	printf("%.10f", ans);
	return 0;
}
#include <bits/stdc++.h>

const int N = 2e6 + 50;

int n, m, head[N], nxt[N], ver[N], fa[N], cnt, maxd;
bool vis[N];
std::vector<int> ve[N];

inline void add(int u, int v)
{
	nxt[++cnt] = head[u];
	ver[cnt] = v;
	head[u] = cnt;
}

void dfs(int x, int d = 1, int f = 0)
{
	maxd = std::max(maxd, d); vis[x] = true;
	ve[d].push_back(x);
	fa[x] = f;
	for (int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if (!vis[y])
		{
			dfs(y, d + 1, x);
		}
	}
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

inline int read()
{
	int r = 0, neg = 1;
	char ch;
	do
	{
		ch = io.gc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do r = r * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return r * neg;
}

inline char readchar()
{
	char ch;
	do ch = io.gc(); while (!isalpha(ch));
	return ch;
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
		cnt = 0; 
		memset(head, 0, (n + 1) << 2);
		memset(vis, 0, (n + 1) << 2);
		n = read(), m = read(), maxd = 0;
		for (int i = 1; i <= m; ++i)
		{
			int u = read(), v = read();
			add(u, v), add(v, u);
		}
		dfs(1);
		if (maxd >= (n + 1) / 2)
		{
			assert(!ve[maxd].empty());
			int t = ve[maxd].back();
			printf("PATH\n%d\n", maxd);
			while (t)
			{
				printf("%d\n", t);
				t = fa[t];
			}
		}
		else
		{
			std::vector<std::pair<int, int> > p2;
			for (int i = 1; i <= maxd; ++i)
			{
				for (int s = 0; s + 1 < ve[i].size(); s += 2)
				{
					p2.emplace_back(ve[i][s], ve[i][s + 1]);
				}
			}
			printf("PAIRING\n%d\n", p2.size());
			for (auto [x, y] : p2)
			{
				printf("%d %d\n", x, y);
			}
		}
		for (int i = 1; i <= maxd; ++i) ve[i].clear();
	}
	return 0;
}
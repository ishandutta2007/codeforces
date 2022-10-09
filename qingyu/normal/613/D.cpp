#include <bits/stdc++.h>

const int N = 3e5 + 50;

int n, m, k, tim, head[N], nxt[N], ver[N], dfn[N], ord[N], dep[N], vertices[N], cnt;
int bin[N], btot;
int f[N][20];
bool sp[N], ssp[N];

inline void add(int u, int v)
{
	nxt[++cnt] = head[u];
	ver[cnt] = v;
	head[u] = cnt;
}
inline void addb(int u, int v)
{
	add(u, v), add(v, u);
}
void dfs(int x, int fa = 0)
{
	dfn[x] = ++tim;
	dep[x] = dep[fa] + 1;
	f[x][0] = fa;
	for (int i = 0; f[x][i]; ++i) f[x][i + 1] = f[f[x][i]][i];
	for (int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if (y != fa)
		{
			dfs(y, x);
		}
	}
}
inline int LCA(int x, int y)
{
	if (dep[x] < dep[y]) std::swap(x, y);
	for (int i = 19; i >= 0; --i)
		if (dep[f[x][i]] >= dep[y]) x = f[x][i];
	if (x == y) return x;
	for (int i = 19; i >= 0; --i)
		if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}

inline void build_virtual_tree()
{
	static int stack[N], top;
	if (vertices[1] != 1) stack[top = 1] = bin[btot = 1] = 1;
	for (int i = 1; i <= k; ++i)
	{
		if (!top) stack[++top] = bin[++btot] = vertices[i];
		else
		{
			int g = LCA(stack[top], vertices[i]);
			while (top > 1 && dep[g] < dep[stack[top - 1]])
			{
				addb(stack[top], stack[top - 1]);
				--top;
			}
			if (dep[g] < dep[stack[top]]) addb(g, stack[top--]);
			if (!top || (stack[top] != g)) stack[++top] = g, bin[++btot] = g;
			stack[++top] = bin[++btot] = vertices[i];
		}
	}
	if (top)
	{
		while (--top)
		{
			addb(stack[top], stack[top + 1]);
		}
	}
}

int ans = 0;
bool nos;

void solve(int x, int f = 0)
{
	int total = 0;
	ssp[x] = sp[x];
	for (int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if (y != f)
		{
			solve(y, x);
			if (sp[x])
			{
				if (ssp[y])
				{
					++ans;
				}
			}
			else
			{
				if (ssp[y])
				{
					++total;
					if (total == 1)
					{
						ssp[x] = true;
					}
					else if (total == 2)
					{
						ssp[x] = false;
						++ans;
					}
				}
			}
		}
		if (nos) return;
	}
}

inline int go_greedy()
{
	ans = nos = 0;
	solve(1);
	if (nos) return -1;
	return ans;
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
fast_io<1 << 20> io;
inline int read()
{
	int res = 0;
	char ch;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return res;
}
inline void put(int64_t x)
{
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) put(x / 10);
	io.pc(48 + x % 10);
}
inline void output(int64_t x, char ch = ' ')
{
	put(x);
	io.pc(ch);
}

int main()
{ 
	n = read();
	for (int i = 1; i <= n; ++i) ord[i] = i;
	for (int i = 1; i < n; ++i)
	{
		int x = read(), y = read();
		add(x, y), add(y, x);
	}
	m = read();
	dfs(1);
	auto cmp = [&](const int x, const int y) { return dfn[x] < dfn[y]; };
	std::sort(ord + 1, ord + n + 1, cmp);
	memset(head, 0, sizeof head); cnt = 0;
	for (int i = 1; i <= m; ++i)
	{
		k = read();
		for (int i = 1; i <= k; ++i) vertices[i] = read(), sp[vertices[i]] = true;
		bool nos = false;
		for (int i = 1; i <= k; ++i) 
		{
			if (sp[vertices[i]] && sp[f[vertices[i]][0]])
			{
				nos = true;
				break;
			}
		}
		if (nos) output(-1, '\n');
		else
		{
			std::sort(vertices + 1, vertices + k + 1, cmp);
			build_virtual_tree();
			output(go_greedy(), '\n');
		}
		for (int i = 1; i <= k; ++i) sp[vertices[i]] = false;
		while (btot) 
		{
			head[bin[btot--]] = 0;
		}
		cnt = 0;
	}
	return 0;
}
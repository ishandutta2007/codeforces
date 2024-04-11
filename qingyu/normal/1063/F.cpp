#include<bits/stdc++.h>

const int N = 1e6 + 50;
const int M = 4e6 + 50;

inline int lc(int o) { return o << 1; }
inline int rc(int o) { return o << 1 | 1; }

int n, ans, tot = 1, lst = 1, cnt, p;
int fa[N], len[N], ch[N][26], bel[N], dp[N];
int in[N], out[N], f[N][22], mx[M];
char s[N];
int head[N], nxt[N], ver[N], etot;
inline void add(int u, int v)
{
	nxt[++etot] = head[u];
	ver[etot] = v;
	head[u] = etot;
}

inline void push_up(int o)
{
	mx[o] = std::max(mx[lc(o)], mx[rc(o)]);
}

void modify(int o, int l, int r, int p, int v)
{
	if (l == r)
	{
		mx[o] = v;
	}
	else
	{
		const int mid = l + r >> 1;
		if (p <= mid) modify(lc(o), l, mid, p, v);
		else modify(rc(o), mid + 1, r, p, v);
		push_up(o);
	}
}

int query(int o, int l, int r, int ql, int qr)
{
	if (!ql || !qr) return 0;
	if (ql <= l && qr >= r) return mx[o];
	int v = 0;
	const int mid = l + r >> 1;
	if (ql <= mid) v = std::max(v, query(lc(o), l, mid, ql, qr));
	if (qr > mid) v = std::max(v, query(rc(o), mid + 1, r, ql, qr));
	return v;
}

inline void insert(int c, int id)
{
	int p = lst, np = lst = ++tot;
	len[np] = len[p] + 1, bel[id] = np;
	while (p && !ch[p][c]) ch[p][c] = np, p = fa[p];
	if (!p) fa[np] = 1;
	else
	{
		int q = ch[p][c];
		if (len[q] == len[p] + 1) fa[np] = q;
		else
		{
			int nq = ++tot;
			memcpy(ch[nq], ch[q], sizeof ch[q]);
			len[nq] = len[p] + 1, fa[nq] = fa[q], fa[np] = fa[q] = nq;
			while (ch[p][c] == q) ch[p][c] = nq, p = fa[p];
		}
	}
}

void dfs(int x)
{
	in[x] = ++cnt, f[x][0] = fa[x];
	for (int i = 1; f[x][i - 1]; ++i) f[x][i] = f[f[x][i - 1]][i - 1];
	for (int i = head[x]; i; i = nxt[i]) dfs(ver[i]);
	out[x] = cnt;
}

inline int get(int x, int lenth)
{
	x = bel[x];
	for (int i = 20; i >= 0; --i)
		if (f[x][i] && len[f[x][i]] >= lenth)
			x = f[x][i];
	return x;
}

inline int calc(int x)
{
	return query(1, 1, tot, in[x], out[x]);
}

bool check(int p)
{
	int x = get(p, dp[p] - 1), y = get(p - 1, dp[p] - 1);
	return std::max(calc(x), calc(y)) >= dp[p] - 1;
}

template <int T>
struct fast_io
{
	char p[T], *p1, *p2, q[T], *q1, *q2;
	fast_io()
	{
		p1 = p2 = p, q1 = q, q2 = q + T;
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

fast_io<1000000> io;

inline int read()
{
	int r = 0;
	char ch;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	do r = r * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return r;
}

inline int read(char *s)
{
	char ch; int len = 0;
	do ch = io.gc(); while (!isalpha(ch));
	do *s++ = ch, ch = io.gc(), ++len; while (isalpha(ch));
	return len;
}

void putint(int x)
{
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) putint(x / 10);
	io.pc(48 + x % 10);
}

inline void output(int x, char ch = ' ')
{
	putint(x); io.pc(ch);
}


int main()
{
       	n = read(s + 1);
	std::reverse(s + 1, s + n + 1);
	for (int i = 1; i <= n; ++i) insert(s[i] - 'a', i);
	for (int i = 2; i <= tot; ++i) add(fa[i], i);
	dfs(1);
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + 1;
		while (!check(i))
			--dp[i], ++p, modify(1, 1, tot, in[bel[p]], dp[p]);
		ans = std::max(ans, dp[i]);
	}
	output(ans);
	return 0;
}
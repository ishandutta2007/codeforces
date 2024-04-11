// By Qingyu
#include <bits/stdc++.h>

const int N = 1e5 + 50;
const int M = 1e7 + 50;

int n, head[N], nxt[N << 1], ver[N << 1], _cnt;
int lc[M], rc[M], cnt[M], tot;
long long sum[M], ans[N];

inline void add(int u, int v)
{
	nxt[++_cnt] = head[u];
	ver[_cnt] = v;
	head[u] = _cnt;
}

inline void push_up(int o)
{
	cnt[o] = std::max(cnt[lc[o]], cnt[rc[o]]);
	sum[o] = 0;
	if (cnt[o] == cnt[lc[o]]) sum[o] += sum[lc[o]];
	if (cnt[o] == cnt[rc[o]]) sum[o] += sum[rc[o]];
}

struct Segment
{
	int rt;
	void ins(int &o, int l, int r, int v)
	{
		if (!o) o = ++tot;
		if (l == r) ++cnt[o], sum[o] = l;
		else
		{
			const int mid = l + r >> 1;
			if (v <= mid) ins(lc[o], l, mid, v);
			else ins(rc[o], mid + 1, r, v);
			push_up(o);
		}
	}
	void ins(int v)
	{
		ins(rt, 1, n, v);
	}
} T[N];

void mergeTo(int &src, int tar)
{
	if (!tar) return;
	if (!src)
	{
		src = tar;
		return;
	}
	mergeTo(lc[src], lc[tar]);
	mergeTo(rc[src], rc[tar]);
	if (!lc[src] && !rc[src])
	{
		cnt[src] += cnt[tar];
		sum[src] = std::max(sum[src], sum[tar]);
	}
	else
	{
		push_up(src);
	}
}

void dfs(int x, int fa = -1)
{
	for (int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if (y != fa)
		{
			dfs(y, x);
			mergeTo(T[x].rt, T[y].rt);
		}
	}
	ans[x] = sum[T[x].rt];
}

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0;
	char ch;
	do ch = nc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;
}

int main()
{
	n = read();
	for (int i = 1; i <= n; ++i) T[i].ins(read());
	for (int i = 1; i < n; ++i)
	{
		int u = read(), v = read();
		add(u, v), add(v, u);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i) printf("%lld ", ans[i]);
	return 0;
}
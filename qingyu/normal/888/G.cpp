// By Qingyu
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#include <bits/stdc++.h>

const int N = 2e5 + 50;
const int B = 31;

int n, rt, a[N], f[N], ch[N * B][2], cnt[N * B], id[N * B], min_p[N], min_v[N], tot;
std::vector<int> vec[N];

inline int find(int x)
{
	while (x != f[x])
		x = f[x] = f[f[x]];
	return x;
}

inline void insert(int &o, int v, int id, int d = 30)
{
	if (!o) o = ++tot;
	++cnt[o];
	if (d >= 0) insert(ch[o][v >> d & 1], v, id, d - 1);
	else ::id[o] = id;
}

inline void del(int o, int v, int d = 30)
{
	--cnt[o];
	if (d >= 0) del(ch[o][v >> d & 1], v, d - 1);
}

inline void merge(std::vector<int> &v1, std::vector<int> &v2)
{
	if (!v2.empty())
	{
		if (v1.size() < v2.size()) std::swap(v1, v2);
		v1.insert(v1.end(), v2.begin(), v2.end());
		v2.clear();
	}
}

inline int query(int o, int v, int d = 30)
{
	if (d == -1) return id[o];
	if (cnt[ch[o][v >> d & 1]]) return query(ch[o][v >> d & 1], v, d - 1);
	return query(ch[o][!(v >> d & 1)], v, d - 1);
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
	for (int i = 1; i <= n; ++i) a[i] = read();
	std::sort(a + 1, a + n + 1);
	n = std::unique(a + 1, a + n + 1) - (a + 1);
	int components = n;
	std::iota(f, f + n + 1, 0);
	for (int i = 1; i <= n; ++i) insert(rt, a[i], i), vec[i].emplace_back(i);
	long long ans = 0;
	while (components > 1)
	{
		for (int i = 1; i <= n; ++i)
			if (!vec[i].empty())
			{
				min_v[i] = 2147483647;
				for (int x : vec[i]) del(rt, a[x]);
				for (int x : vec[i])
				{
					int v = query(rt, a[x]);
					if ((a[v] ^ a[x]) < min_v[i])
					{
						min_v[i] = a[v] ^ a[x];
						min_p[i] = v;
					}
				}
				for (int x : vec[i]) insert(rt, a[x], x);
			}
		for (int i = 1; i <= n; ++i)
			if (!vec[i].empty())
			{
				int x = find(i), y = find(min_p[i]), w = min_v[i];
				if (x != y)
				{
					f[x] = y;
					ans += w;
					merge(vec[y], vec[x]);
					--components;
				}
			}
	}
	printf("%lld", ans);
	return 0;
}
#include <bits/stdc++.h>
 
typedef long long ll;
constexpr int N = 1e6 + 50;

int a[N], pos[N], tr[N], n, m;
int max[N], min[N];

constexpr int lowbit(int x) { return x & -x;}
 
inline void add(int p, int v)
{
	for (; p < N; p += lowbit(p)) tr[p] += v;
}

inline int query(int p)
{
	int res = 0; int pp = p;
	for (; p; p -= lowbit(p)) res += tr[p];
	return res;
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
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) min[i] = max[i] = i, pos[i] = n - i + 1, add(i, 1);
	for (int i = 1; i <= m; ++i) min[a[i] = read()] = 1;
	for (int i = 1; i <= m; ++i)
	{
		max[a[i]] = std::max(max[a[i]], n - query(pos[a[i]]) + 1);
		add(pos[a[i]], -1);
		add(pos[a[i]] = i + n, 1);
	}
	for (int i = 1; i <= n; ++i) max[i] = std::max(max[i], n - query(pos[i]) + 1);
	for (int i = 1; i <= n; ++i) printf("%d %d\n", min[i], max[i]);
	return 0;
}
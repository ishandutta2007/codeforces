#include <bits/stdc++.h>
 
const int N = 7e5 + 50;
const int M = 3e7 + 50;
 
int n, m, ans, a[N], b[N], c[N];
int lc[M], rc[M], sum[M], root[N], tot;
 
std::queue<int> pool;
 
inline int newnode()
{
	if (pool.empty()) return ++tot;
	int x = pool.front(); pool.pop();
	return x;
}
 
struct tree
{
	int root;
	int insert(int o, int l, int r, int v, int V)
	{
		if (!o) o = newnode();
		if (l == r) sum[o] += V;
		else
		{
			const int mid = l + r >> 1;
			if (v <= mid) lc[o] = insert(lc[o], l, mid, v, V);
			else rc[o] = insert(rc[o], mid + 1, r, v, V);
			sum[o] += V;
		}
		if (sum[o] == 0 && o > n)
		{
			pool.push(o);
			sum[o] = lc[o] = rc[o] = 0;
			o = 0;
		}
		return o;
	}
	void insert(int v, int V = 1) { insert(root, 1, n, v, V); }
	int query(int o, int l, int r, int vL, int vR)
	{
		if (vL <= l && r <= vR) return sum[o];
		const int mid = l + r >> 1;
		int ans = 0;
		if (vL <= mid) ans += query(lc[o], l, mid, vL, vR);
		if (vR > mid) ans += query(rc[o], mid + 1, r, vL, vR);
		return ans;
	}
	
	int query(int vL, int vR)
	{
		assert(root);
		int ans = query(root, 1, n, vL, vR);
		return ans;
	}
	
	int merge(int x, int y)
	{
		if (!x) x = ++tot;
		sum[x] += sum[y];
		if (lc[y]) lc[x] = merge(lc[x], lc[y]);
		if (rc[y]) rc[x] = merge(rc[x], rc[y]);
		return x;
	}
	
	void merge(int x)
	{
		merge(root, x);
	}
} t[M];
 
inline int lowbit(int x) { return x & -x; }
 
inline void insert(int p, int v)
{
	for (int i = p; i <= n; i += lowbit(i)) t[root[i]].insert(v, +1);
}
inline void erase(int p, int v)
{
	for (int i = p; i <= n; i += lowbit(i)) t[root[i]].insert(v, -1);
}
 
inline int query(int p, int l, int r)
{
	int ans = 0;
	for (int i = p; i; i -= lowbit(i)) 
	{
		ans += t[root[i]].query(l, r);
	}
	return ans;
}
 
inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}
 
inline int read()
{
	int res = 0; char ch; do ch = nc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;
}
 
int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 1; i <= n; ++i) ++tot, t[tot].root = tot, root[i] = tot;
 
	for (int i = 1; i <= n; ++i) b[i] = read();
	
	for (int i = 1; i <= n; ++i) c[a[i]] = i;
	for (int i = 1; i <= n; ++i) b[i] = c[b[i]];
	for (int i = 1; i <= n; ++i) insert(i, b[i]);
	
	for (int i = 1; i <= m; ++i)
	{
		int op = read();
		if (op == 1)
		{
			int l = read(), r = read(), x = read(), y = read();
			int ans = query(y, l, r) - query(x - 1, l, r);
			printf("%d\n", ans);
		}
		else
		{
			int x = read(), y = read();
			if (x == y) continue;
			erase(x, b[x]); erase(y, b[y]);
			insert(x, b[y]); insert(y, b[x]);
			std::swap(b[x], b[y]);
		}
	}
	return 0;
	
}
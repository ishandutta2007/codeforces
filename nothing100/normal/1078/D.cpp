#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

int n;
int a[300001];
pii f[300001][21], c[21][1200001];

pii gt(int l, int r)
{
	return pii(max(1, l), min(3 * n, r));
}

pii upd(pii A, pii B)
{
	return pii(min(A.first, B.first), max(A.second, B.second));
}

void build(int p, int l, int r, int K)
{
	if (l == r)
	{
		c[K][p] = f[l][K];
		return;
	}
	int mid = (l + r) >> 1, ll = p << 1;
	build(ll, l, mid, K);
	build(ll | 1, mid + 1, r, K);
	c[K][p] = upd(c[K][ll], c[K][ll | 1]);
}

pii query(int p, int l, int r, int x, int y, int K)
{
	if (l == x && r == y) return c[K][p];
	int mid = (l + r) >> 1, ll = p << 1;
	if (y <= mid) return query(ll, l, mid, x, y, K);
	else if (x >= mid + 1) return query(ll | 1, mid + 1, r, x, y, K);
	else return upd(query(ll, l, mid, x, mid, K), query(ll | 1, mid + 1, r, mid + 1, y, K));
}

int main()
{
	
//	freopen("D.in", "r", stdin);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) scanf("%d", &a[i]); 
	for (int i = 1; i <= n; ++ i)
		a[i + n] = a[i + 2 * n] = a[i];
	for (int i = 1; i <= 3 * n; ++ i)
	{
		f[i][0] = gt(i - a[i], i + a[i]);
	}
	for (int k = 1; k <= 20; ++ k)
	{
//		printf("OK %d\n", k);
		build(1, 1, 3 * n, k - 1);
		for (int i = 1; i <= 3 * n; ++ i)
		{
//			printf("%d %d\n", f[i][k - 1].first, f[i][k - 1].second);
			f[i][k] = query(1, 1, 3 * n, f[i][k - 1].first, f[i][k - 1].second, k - 1);
//			printf("%d %d\n", f[i][k].first, f[i][k].second);
		}
	}
	build(1, 1, 3 * n, 20);
	
	for (int i = n + 1; i <= 2 * n; ++ i)
	{
		int ans = 0, L, R; L = R = i;
		for (int k = 20; k >= 0; -- k)
		{
			pii tmp = query(1, 1, 3 * n, L, R, k);
			if (tmp.second - tmp.first + 1 < n)
			{
				L = tmp.first; R = tmp.second; 
				ans += 1 << k;
			}
		}
		if (n!=1) printf("%d ", ans + 1);
		else printf("%d ",ans);
	}
	printf("\n");
	return 0;
}
#include <bits/stdc++.h>

const int N = 1e6 + 50;

int n, k, a[N], b[N], t[N];

inline int lowbit(int x)
{
	return x & -x;
}

inline void modify(int p, int v)
{
	for (int i = p; i; i -= lowbit(i))
		t[i] = std::max(t[i], v);
}

inline int query(int p)
{
	int ans = -1;
	for (int i = p; i <= n; i += lowbit(i))
		ans = std::max(ans, t[i]);
	return ans;
}

int main()
{
	int TT;
	scanf("%d", &TT);
	while (TT--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i) t[i] = 0;
		for (int i = 1; i <= n; ++i) scanf("%d", a + i), b[i] = a[i];
		std::sort(b + 1, b + n + 1);
		for (int i = 1; i <= n; ++i) a[i] = std::lower_bound(b + 1, b + n + 1, a[i]) - b;
		int count = 1;
		for (int i = 1; i < n; ++i)
		{
			if (a[i] + 1 != a[i + 1])
			{
				++count;
			}
		}	
		puts(count > k ? "No" : "Yes");
	}
	return 0;
}
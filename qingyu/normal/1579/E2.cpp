#include <bits/stdc++.h>

using namespace std;

int n, a[500005], b[500050];
int t[500005];

inline int lowbit(int x)
{
	return x & -x;	
}

inline void add(int p, int v)
{
	++p;
	for (; p <= n+1; p += lowbit(p)) t[p] += v;
}
inline int qry(int p)
{
	++p;
	int r = 0;
	for (; p; p -= lowbit(p)) r += t[p];
	return r;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; ++i) 
		{
			cin >> a[i];
			b[i] = a[i];
		}
		memset(::t, 0, n + 50 << 2);
		sort(b + 1, b + n + 1);
		int m = unique(b + 1, b + n + 1) - (b + 1);
		for (int i = 1; i <= n; ++i)
			a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
		long long ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			int L = qry(a[i] - 1), R = (i - 1) - qry(a[i]);
			ans += min(L, R);
			add(a[i], 1);
		}	
		printf("%lld\n", ans);
	}

}
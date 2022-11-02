#include <bits/stdc++.h>
using namespace std;

int n, f[101][10001], sum, S, a[101];
int g[101][10001];

map <int, int> mp;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%d", &a[i]);
		sum += a[i];
		if (!mp[a[i]]) ++ S;
		++ mp[a[i]];
	}
	f[0][0] = 1;
	for (auto x : mp)
		for (int l = n; l >= 1; -- l)
			for (int k = min(x.second, l); k >= 1; -- k)
				for (int j = 10000; j >= x.first * k; -- j)
				{
					f[l][j] += f[l - k][j - x.first * k];
				}
	int ans = 0;
	for (auto x : mp)
	{
		for (int i = 1; i <= x.second; ++ i)
			if (f[i][i * x.first] == 1 || f[n - i][sum - i * x.first] == 1)
			{
				ans = max(ans, i);
				if (i == x.second && S == 2) ans = max(ans, n);
			}
	}
	printf("%d\n", ans);
	return 0;
}
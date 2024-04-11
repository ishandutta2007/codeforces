#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 20;

int n, a[N], b[N], c[N], d[N], f[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	int ans = 0;
	for (int w = 19; w >= 0; --w)
	{
		int parity = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (a[i] >> w & 1)
			{
				c[i] = c[i - 1] + 1;
				parity ^= 1;
			}
			else
			{
				c[i] = c[i - 1];
			}
			d[i] ^= parity << w;
		}
		memset(f, -1, sizeof f);
		f[0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (f[d[i]] == -1) f[d[i]] = i;
			else
			{
				int j = f[d[i]];
				if (c[i] - c[j] == i - j) ans = max(ans, i - j);
				else f[d[i]] = i;
			}			
		}
	}
	cout << ans << '\n';
}
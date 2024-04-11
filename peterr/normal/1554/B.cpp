#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		long long ans = 2 - k * (a[1] | a[2]);
		ans = max(ans, (long long) n * (n - 1) - k * (a[n] | a[n - 1]));
		for (int i = max(1, n - 3 * k); i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
					continue;
				ans = max(ans, (long long) i * j - k * (a[i] | a[j]));
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
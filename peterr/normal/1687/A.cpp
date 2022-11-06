#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		long long sum = 0;
		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			sum += a[i];
			if (i >= k)
				sum -= a[i - k];
			ans = max(ans, sum);
		}
		for (int i = 0; i < min(n, k); i++)
		{
			ans += k - i - 1;
		}
		cout << ans << "\n";
	}
	return 0;
}
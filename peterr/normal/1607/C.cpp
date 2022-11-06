#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
long long a[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		long long ans = a[0];
		long long sum = 0;
		for (int i = 0; i < n - 1; i++)
		{
			sum += a[i] - sum;
			ans = max(ans, a[i + 1] - sum);
		}
		cout << ans << "\n";
	}
	return 0;
}
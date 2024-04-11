#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 5000;
int a[MAXN];
int best[MAXN + 1];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n >> x;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			int sum = 0;
			for (int j = 0; j < i; j++)
			{
				sum += a[j];
			}
			best[i] = sum;
			for (int j = i; j < n; j++)
			{
				sum += a[j];
				sum -= a[j - i];
				best[i] = max(best[i], sum);
			}
		}
		for (int i = 0; i <= n; i++)
		{
			int ans = 0;
			for (int j = 1; j <= n; j++)
			{
				ans = max(ans, best[j] + x * min(i, j));
			}
			cout << ans << " \n"[i == n];
		}
	}
	return 0;
}
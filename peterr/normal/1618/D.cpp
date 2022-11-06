#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 100;
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
		sort(a, a + n);
		int ans = 0;
		for (int i = 0; i < n - 2 * k; i++)
		{
			ans += a[i];
		}
		for (int i = 0; i < k; i++)
		{
			if (a[n - i - 1] == a[n - i - k - 1])
				ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
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
		int n, x;
		cin >> n >> x;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		long long ans = 0;
		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += a[i];
			if (sum > x)
				break;
			ans += (x - sum) / (i + 1) + 1;
		}
		cout << ans << "\n";
	}
	return 0;
}
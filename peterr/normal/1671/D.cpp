#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
int a[MAXN];

int check(int z, int n)
{
	int ans = abs(z - a[0]);
	ans = min(ans, abs(z - a[n - 1]));
	for (int i = 0; i < n; i++)
	{
		ans = min(ans, 2 * abs(z - a[i]));
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n >> x;
		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (i)
				ans += abs(a[i] - a[i - 1]);
		}
		int mn = *min_element(a, a + n);
		int mx = *max_element(a, a + n);
		if (1 < mn)
			ans += check(1, n);
		if (x != 1 && x > mx)
			ans += check(x, n);
		cout << ans << "\n";
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int best = 2E9;
	int ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int d = a[i + 1] - a[i];
		if (d < best)
		{
			best = d;
			ans = 1;
		}
		else if (d == best)
			ans++;
	}
	cout << best << " " << ans << "\n";
	return 0;
}
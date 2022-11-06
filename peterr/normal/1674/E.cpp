#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
int a[MAXN];
int b[MAXN];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	int ans = (b[0] + 1) / 2 + (b[1] + 1) / 2;
	for (int i = 0; i < n - 2; i++)
	{
		if (a[i] % 2 == a[i + 2] % 2)
			ans = min(ans, (a[i] + a[i + 2]) / 2);
		else
			ans = min(ans, (a[i] + a[i + 2] + 1) / 2);
	}
	for (int i = 0; i < n - 1; i++)
	{
		int x = a[i];
		int y = a[i + 1];
		if (x < y)
			swap(x, y);
		int amt = min(x - y, (x + 1) / 2);
		x -= 2 * amt;
		y -= amt;
		if (x > 0)
		{
			amt += 2 * ((x + 2) / 3) - 1;
			if (x % 3 == 2 || x % 3 == 0)
				amt++;
		}
		ans = min(ans, amt);
	}
	cout << ans << "\n";
	return 0;
}
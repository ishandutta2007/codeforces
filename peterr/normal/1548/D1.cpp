#include <bits/stdc++.h>
 
using namespace std;

int freq[4];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		x %= 4;
		y %= 4;
		x /= 2;
		y /= 2;
		freq[2 * x + y]++;
	}
	long long ans = (long long) n * (n - 1) * (n - 2) / 6;
	for (int i = 0; i < 4; i++)
	{
		long long cnt = 1;
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
				continue;
			cnt *= freq[j];
		}
		ans -= cnt;
	}
	cout << ans << "\n";
	return 0;
}
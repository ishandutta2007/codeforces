#include <bits/stdc++.h>

using namespace std;

int sign(int pos)
{
	if (pos % 2 != 0)
		return 1;
	return -1;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long x0, n;
		cin >> x0 >> n;
		if (!n)
		{
			cout << x0 << "\n";
			continue;
		}
		x0 += sign(x0);
		long long cycles = (n - 1) / 4;
		x0 += sign(x0 + 1) * cycles * 4;
		for (long long i = cycles * 4 + 2; i <= n; i++)
		{
			x0 += sign(x0) * i;
		}
		cout << x0 << "\n";
	}
	return 0;
}
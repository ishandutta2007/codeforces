#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c, m;
		cin >> a >> b >> c >> m;
		int mx = a - 1 + b - 1 + c - 1;
		if (b > a)
			swap(a, b);
		if (c > a)
			swap(a, c);
		if (c > b)
			swap(b, c);
		int diff = b - c;
		a -= diff;
		b -= diff;
		int x = 0;
		for (int jump = 1E8; jump; jump >>= 1)
		{
			while (x + jump <= a && (x + jump + 1) / 2 <= c)
			{
				if (a - (x + jump) < c - (x + jump) / 2)
					break;
				x += jump;
			}
		}
		a -= x;
		b -= (x + 1) / 2;
		c -= x / 2;
		int mn = 0;
		if (a != b)
			mn = max(0, a - 1);
		if (m >= mn && m <= mx)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}
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
		int a, b, c;
		cin >> a >> b >> c;
		int n = 2 * abs(a - b);
		if (max(max(a, b), c) > n)
			cout << "-1\n";
		else
		{
			int d = c + n / 2;
			if (d > n)
				d -= n;
			cout << d << "\n";
		}
	}
}
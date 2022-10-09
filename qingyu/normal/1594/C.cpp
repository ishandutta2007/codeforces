/*
2021.10.09
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t, n; char c;
	cin >> t;
	string s;
	while (t--)
	{
		cin >> n >> c >> s;
		bool ok = true;
		for (int i = 0; i < n; ++i)
			if (s[i] != c)
			{
				ok = false;
			}
		if (ok)
		{
			cout << 0 << '\n';
			continue;
		}
		for (int i = n / 2 + 1; i <= n; ++i)
		       if (s[i - 1] == c)
		       {
			       ok = true;
			       cout << 1 << '\n' << i << '\n';
			       break;
		       }
		if (!ok)
		{
			cout << 2 << '\n' << n << " " << n - 1 << '\n';
		}
	}
}
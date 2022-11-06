#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int x, y;
		cin >> x >> y;
		if ((x + y) & 1)
			cout << "-1 -1\n";
		else
			cout << x / 2 << " " << (y + 1) / 2 << "\n";
	}
	return 0;
}
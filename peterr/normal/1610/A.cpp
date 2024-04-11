#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		if (n == m && n == 1)
			cout << "0\n";
		else if (min(n, m) == 1)
			cout << "1\n";
		else
			cout << "2\n";
	}
	return 0;
}
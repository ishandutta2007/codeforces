#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		cin >> n;
		if (n % 4 == 0)
		{
			cout << n / 4 << "\n";
		}
		else if (n % 4 == 1)
		{
			if (n >= 9)
			{
				cout << 1 + (n - 9) / 4 << "\n";
			}
			else
				cout << "-1\n";
		}
		else if (n % 4 == 2)
		{
			if (n >= 6)
				cout << 1 + (n - 6 ) / 4 << "\n";
			else
				cout << "-1\n";
		}
		else if (n % 4 == 3)
		{
			if (n >= 15)
				cout << 2 + (n - 15) / 4 << "\n";
			else
				cout << "-1\n";
		}

	}
	return 0;
}
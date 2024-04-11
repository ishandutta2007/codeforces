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
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
				cout << "(";
			for (int j = 0; j < i; j++)
				cout << ")";
			for (int j = 0; j < n - i; j++)
				cout << "(";
			for (int j = 0; j < n - i; j++)
				cout << ")";
			cout << "\n";
		}

	}
	return 0;
}
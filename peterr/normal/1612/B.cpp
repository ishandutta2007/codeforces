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
		int n, a, b;
		cin >> n >> a >> b;
		if (b == n / 2 && a == n / 2 + 1)
		{
			for (int i = n; i >= 1; i--)
				cout << i << " ";
			cout << "\n";
		}
		else if (b <= n / 2 || a > n / 2)
			cout << "-1\n";
		else
		{
			for (int i = b + 1; i <= n; i++)
				cout << i << " ";
			for (int i = a; i <= b; i++)
				cout << i << " ";
			for (int i = 1; i < a; i++)
				cout << i << " ";
			cout << "\n";
		}
	}
	return 0;
}
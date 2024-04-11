#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;
		if ((n & 1) || n == 2)
		{
			cout << "-1\n";
			continue;
		}
		n /= 2;
		cout << (n + 2) / 3 << " " << n / 2 << "\n";
	}
	return 0;
}
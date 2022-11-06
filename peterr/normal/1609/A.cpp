#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int mx = 1;
		long long ans = 0;
		int twos = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			while (!(x & 1))
			{
				x >>= 1;
				twos++;
			}
			mx = max(x, mx);
			ans += x;
		}
		cout << (1LL << twos) * mx + ans - mx << "\n";
	}
	return 0;
}
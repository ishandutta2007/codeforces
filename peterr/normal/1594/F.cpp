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
		long long s, n, k;
		cin >> s >> n >> k;
		if (s == k)
			cout << "YES\n";
		else
		{
			cout << (s >= n + k * (n / k) ? "NO" : "YES") << "\n";
		}
	}
	return 0;
}
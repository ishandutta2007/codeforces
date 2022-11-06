#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	for (int i = 0; i < (1 << n); ++i)
	{
		int sum = 0;
		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j))
			{
				sum += a[j];
			}
			else
				sum -= a[j];
		}
		if (((abs(sum)) % 360) == 0)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}
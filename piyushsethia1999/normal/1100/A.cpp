#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int k; cin >> k;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	int u = -1;
	for (int b = 0; b < n; ++b)
	{
		int an = 0;
		for (int i = 0; i < n; ++i)
		{
			if ((i - b) % k != 0)
			{
				an += a[i];
			}
		}
		u = max(u, abs(an));
	}
	cout << u << "\n";
}
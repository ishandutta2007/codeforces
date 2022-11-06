#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n;
	cin >> n;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	int sum = 0;
	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += a[i];
		m = max(a[i], m);
	}
	cout << max(m, ((2 * sum) / n) + 1);
}
#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	if (a[0] != 0)
	{
		cout << 1;
		exit(0);
	}
	int ma = 1;
	for (int i = 1; i < n; ++i)
	{
		if (a[i] > ma)
		{
			cout << i + 1;
			exit(0);
		}
		else if (ma == a[i])
		{
			ma++;
		}
	}
	cout << -1;
}
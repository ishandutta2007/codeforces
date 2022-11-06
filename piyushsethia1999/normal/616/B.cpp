#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int m; cin >> m;
	std::vector<std::vector<int> > a(n, std::vector<int> (m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
	int M = 0;
	for (int i = 0; i < n; ++i)
	{
		int m1 = a[i][0];
		for (int j = 0; j < m; ++j)
			m1 = min(m1, a[i][j]);
		M = max(m1, M);
	}
	cout << M;
}
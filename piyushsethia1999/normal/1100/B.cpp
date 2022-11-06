#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int m; cin >> m;
	int n; cin >> n;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	std::vector<int> v(m, 0);
	int o = 0;
	std::vector<int> v1(n, 0);
	for (int i = 0; i < n; ++i)
	{
		v[a[i] - 1]++;
		if (v[a[i] - 1] == 1)
		{
			o++;
			if (o == m)
			{
				v1[i] = 1;
				for (int j = 0; j < m; ++j) {
					v[j]--;
					if (v[j] == 0)
						o--;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << v1[i];
	}
}
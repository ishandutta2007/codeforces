#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	vector<int> l(n); for (int o = 0; o < n; o++) { cin >> l[o]; }
	vector<int> r(n); for (int o = 0; o < n; o++) { cin >> r[o]; }
	std::vector<int> in;
	int t = 0;
	int ma = n;
	std::vector<int> res(n, -1);
	while (t != n) {
		in.clear();
		for (int i = 0; i < n; ++i)
			if (l[i] == 0 && r[i] == 0)
				in.pb(i);
		if (in.size() == 0)
		{
			cout << "NO";
			exit(0);
		}
		for (int j : in) {
			res[j] = ma;
			l[j] = -1;
			r[j] = -1;
			t++;
		}
		ma--;
		int la = -1;
		int si = in.size();
		for (int i = 0; i < si; ++i)
		{
			for (int j = la + 1; j < in[i]; ++j)
			{
				r[j] -= (si - i);
			}
			la = in[i];
			if (si != (i + 1))
			{
				for (int j = in[i] + 1; j < in[i + 1]; ++j)
				{
					l[j] -= (i + 1);
				}
			}
		}
		for (int j = in[si - 1] + 1; j < n; ++j)
		{
			l[j] -= (si);
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i)
	{
		cout << res[i] << " ";
	}
}
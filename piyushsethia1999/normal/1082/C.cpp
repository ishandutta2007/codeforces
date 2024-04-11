#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int m; cin >> m;
	std::vector<std::vector<int> > v(m);
	for (int i = 0; i < n; ++i)
	{
		int s; cin >> s; s--;
		int r; cin >> r;
		v[s].pb(r);
	}
	std::vector<std::vector<int> > v1(m);
	int mm = 0;
	std::vector<pair<int, int> > siz(m);
	for (int s = 0; s < m; ++s)
	{
		sort(v[s].rbegin(), v[s].rend());
		v1[s].pb(0);
		for (int i = 0; i < v[s].size(); ++i)
		{
			v1[s].pb(v[s][i] + v1[s][i]);
		}
		mm = max(mm, (int)(v[s].size()));
		siz[s] = {v[s].size(), s};
	}
	sort(siz.begin(), siz.end());
	int mmm = 0;
	int yi = 0;
	for (int o = 0; o < m; ++o)
	{
		for (int i = yi; i < siz[o].first; ++i)
		{
			int y = 0;
			for (int j = o; j < m; j++)
				if (v1[siz[j].second][i + 1] > 0)
					y += v1[siz[j].second][i + 1];
			mmm = max(mmm, y);
		}
		yi = siz[o].first;
	}
	cout << mmm;
}
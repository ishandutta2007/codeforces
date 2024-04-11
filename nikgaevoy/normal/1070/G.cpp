#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void dfs(const vector<vector<int>> &gr, const vector<pair<int, int>> &heroes, vector<int> &used,
         int &ord, int pos, int j)
{
	if (used[j] != -1)
		return;

	used[j] = ord++;

	for (auto it : gr[j])
		if ((heroes[it].first < heroes[j].first && pos > heroes[j].first) ||
		    (heroes[it].first > heroes[j].first && pos < heroes[j].first))
			dfs(gr, heroes, used, ord, pos, it);
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<pair<int, int>> heroes(m);

	for (auto &it : heroes)
	{
		cin >> it.first >> it.second;
		it.first--;
		it.first *= 2;
	}

	vector<int> arr(n);

	for (auto &it : arr)
		cin >> it;

	n *= 2;

	arr.resize(arr.size() * 2);

	for (int i = arr.size() - 1; i >= 0; i--)
		if (i % 2 == 0)
			arr[i] = arr[i / 2];
		else
			arr[i] = 0;

	vector<pair<int, int>> segs(heroes.size());

	for (int i = 0; i < (int) heroes.size(); i++)
	{
		segs[i] = {heroes[i].first, heroes[i].first};

		int h = heroes[i].second;

		while (h >= 0 && segs[i].first >= 0)
		{
			segs[i].first--;
			h += arr[segs[i].first];
		}

		h = heroes[i].second;

		while (h >= 0 && segs[i].second < n)
		{
			segs[i].second++;
			h += arr[segs[i].second];
		}
	}

	for (int pos = 1; pos < n; pos += 2)
	{
		int ord = 0;

		vector<int> used(heroes.size(), -1);

		int lf = pos, rf = pos;

		for (int _ = 0; _ < (int)heroes.size (); _++)
			for (int j = 0; j < (int) heroes.size(); j++)
				if (used[j] == -1)
				{
					if ((heroes[j].first < pos && segs[j].second >= lf) ||
						(heroes[j].first > pos && segs[j].first <= rf))
					{
						used[j] = ord++;
						lf = min (lf, heroes[j].first);
						rf = max (rf, heroes[j].first);
					}
				}

		if (ord == m)
		{
			vector<int> ans(heroes.size());

			for (int i = 0; i < (int) used.size(); i++)
				ans[used[i]] = i;

			if (heroes[ans[0]].first <= pos)
				cout << pos / 2 + 1 << endl;
			else
				cout << (pos + 1) / 2 + 1 << endl;

			for (auto it : ans)
				cout << it + 1 << ' ';
			cout << endl;

			return;
		}
	}

	cout << -1 << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}
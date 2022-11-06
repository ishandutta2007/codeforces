#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5E5;
vector<vector<int>> a;
vector<vector<int>> levels;
vector<vector<int>> prefblue;
vector<vector<int>> prefred;
vector<vector<int>> sufblue;
vector<vector<int>> sufred;
bool isb[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		levels.clear();
		a.clear();
		prefblue.clear();
		prefred.clear();
		sufblue.clear();
		sufred.clear();
		int n, m;
		cin >> n >> m;
		fill(isb, isb + n, false);
		a.resize(n);
		for (int i = 0; i < n; i++)
		{
			a[i].resize(m);
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
			}
		}
		vector<pair<int, int>> vec;
		for (int i = 0; i < n; i++)
			vec.push_back({a[i][0], i});
		sort(vec.begin(), vec.end());
		int ptr = 0;
		while (ptr < (int) vec.size())
		{
			int cur = vec[ptr].first;
			levels.push_back(vector<int>());
			while (ptr < (int) vec.size() && vec[ptr].first == cur)
			{
				levels.back().push_back(vec[ptr].second);
				ptr++;
			}
		}
		levels.pop_back();
		prefblue.resize(levels.size(), vector<int>(m, 0));
		prefred.resize(levels.size(), vector<int>(m, 1E6));
		sufblue.resize(levels.size(), vector<int>(m, 1E6));
		sufred.resize(levels.size(), vector<int>(m, 0));
		for (int i = 0; i < m; i++)
		{
			multiset<int> blue;
			multiset<int> red;
			for (int j = 0; j < n; j++)
				red.insert(a[j][i]);
			for (int j = 0; j < (int) levels.size(); j++)
			{
				for (int r : levels[j])
				{
					red.erase(red.find(a[r][i]));
					blue.insert(a[r][i]);
				}
				if (i)
				{
					prefblue[j][i] = prefblue[j][i - 1];
					prefred[j][i] = prefred[j][i - 1];
				}
				prefblue[j][i] = max(prefblue[j][i], *blue.rbegin());
				prefred[j][i] = min(prefred[j][i], *red.begin());
			}
		}
		for (int i = m - 1; i >= 0; i--)
		{
			multiset<int> blue;
			multiset<int> red;
			for (int j = 0; j < n; j++)
				red.insert(a[j][i]);
			for (int j = 0; j < (int) levels.size(); j++)
			{
				for (int r : levels[j])
				{
					red.erase(red.find(a[r][i]));
					blue.insert(a[r][i]);
				}
				if (i < m - 1)
				{
					sufblue[j][i] = sufblue[j][i + 1];
					sufred[j][i] = sufred[j][i + 1];
				}
				sufblue[j][i] = min(sufblue[j][i], *blue.begin());
				sufred[j][i] = max(sufred[j][i], *red.rbegin());
			}
		}
		for (int i = 0; i < (int) levels.size(); i++)
		{
			for (int r : levels[i])
				isb[r] = true;
			int j = 0;
			while (j < m - 1 && prefblue[i][j] < prefred[i][j])
				j++;
			if (!j)
				continue;
			if (sufblue[i][j] > sufred[i][j])
			{
				cout << "YES\n";
				for (int k = 0; k < n; k++)
					cout << (isb[k] ? 'B' : 'R');
				cout << " " << j << "\n";
				goto exit;
			}
		}
		cout << "NO\n";
		exit:;
	}
	return 0;
}
#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<vector<int>> arr(n, vector<int>(3));

	for (auto &row : arr)
	{
		for (auto &it : row)
			cin >> it;
	}

	vector<bool> used(n);

	int cur = 0;

	auto dist = [](const vector<int> &a, const vector<int> &b) {
		int sum = 0;

		for (int i = 0; i < a.size(); i++)
			sum += abs(a[i] - b[i]);

		return sum;
	};

	vector<map<int, set<int>>> part(3);

	for (int i = 0; i < arr.size(); i++)
		for (int j = 0; j < 3; j++)
			part[j][arr[i][j]].insert(i);

	while (cur < n)
	{
		if (used[cur])
		{
			cur++;

			continue;
		}

		int pt = -1, x = 0;

		for (int j = 0; j < 3; j++)
		{
			auto it = part[j].find(arr[cur][j]);

			if (it->second.size() > 1)
			{
				if (pt == -1 || it->second.size() - 1 < part[pt][x].size())
				{
					pt = j;
					x = it->first;
				}
			}
			else
			{
				auto nxt = it;
				++nxt;

				if (nxt != part[j].end())
				{
					if (pt == -1 || nxt->second.size() < part[pt][x].size())
					{
						pt = j;
						x = nxt->first;
					}
				}

				nxt = it;

				if (nxt != part[j].begin())
				{
					--nxt;

					if (pt == -1 || nxt->second.size() < part[pt][x].size())
					{
						pt = j;
						x = nxt->first;
					}
				}
			}
		}

		int sn = -1;

		for (auto i : part[pt][x])
			if (i != cur && !used[i] && (sn == -1 || dist(arr[cur], arr[i]) < dist(arr[cur], arr[sn])))
				sn = i;

		assert(sn != -1);

		cout << cur + 1 << ' ' << sn + 1 << endl;

		used[cur] = true;
		used[sn] = true;

		for (int j = 0; j < 3; j++)
		{
			part[j][arr[cur][j]].erase(cur);

			if (part[j][arr[cur][j]].empty())
				part[j].erase(arr[cur][j]);
		}

		for (int j = 0; j < 3; j++)
		{
			part[j][arr[sn][j]].erase(sn);

			if (part[j][arr[sn][j]].empty())
				part[j].erase(arr[sn][j]);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}
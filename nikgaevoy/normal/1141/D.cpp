#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	string l, r;

	cin >> l >> r;

	unordered_map<char, vector<int>> shoes;

	for (int i = 0; i < l.size(); i++)
		shoes[l[i]].push_back(i);

	vector<pair<int, int>> ans;

	vector<int> trash;

	for (int i = 0; i < r.size(); i++)
		if (r[i] == '?')
			trash.push_back(i);
		else if (shoes[r[i]].empty())
		{
			if (!shoes['?'].empty())
			{
				ans.emplace_back(shoes['?'].back(), i);
				shoes['?'].pop_back();
			}
		}
		else
		{
			ans.emplace_back(shoes[r[i]].back(), i);
			shoes[r[i]].pop_back();
		}

	for (auto &it : shoes)
		while (!trash.empty() && !it.second.empty())
		{
			ans.emplace_back(it.second.back(), trash.back());
			it.second.pop_back();
			trash.pop_back();
		}

	cout << ans.size() << endl;

	for (auto it : ans)
		cout << it.first + 1 << ' ' << it.second + 1 << endl;
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
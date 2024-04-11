#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<bool> used(n);
	vector<pair<int, int>> edges;
	edges.reserve(n - 1);

	queue<int> ord;
	ord.push(0);

	bool first = true;

	while (!ord.empty())
	{
		auto v = ord.front();
		ord.pop();

		if (!used[v])
		{
			cout << "? " << v + 1 << endl;

			vector<int> ans(n);

			for (auto &it : ans)
				cin >> it;

			if (first)
			{
				first = false;

				int odd = 0;

				for (auto &it : ans)
					if (it % 2 == 1)
						odd++;

				if (2 * odd < ans.size())
				{
					auto nxt = find(ans.begin(), ans.end(), 1) - ans.begin();

					ord.push((int)nxt);

					continue;
				}
			}

			for (int j = 0; j < ans.size(); j++)
			{
				if (ans[j] < 2)
					used[j] = true;
				if (ans[j] == 1)
					edges.emplace_back(v, j);
				if (ans[j] == 2)
					ord.push(j);
			}
		}
	}

	assert(edges.size() == n - 1);

	cout << '!' << endl;

	for (auto it : edges)
		cout << it.first + 1 << ' ' << it.second + 1 << endl;
}


int main()
{
	cout << fixed;

#ifdef LOCAL
	auto st = chrono::steady_clock::now();

	ifstream fin("../input.txt");

	solve();

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}
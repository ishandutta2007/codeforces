#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<int> l(m);

	for (auto &it : l)
		cin >> it;

	vector<int> ans(l.size());
	ans[0] = n - l.front();

	for (int i = 1; i < ans.size(); i++)
	{
		ans[i] = ans[i - 1] + l[i - 1] - 1 - l[i];

		if (ans[i] < 0)
		{
			cout << -1 << endl;

			return;
		}
	}

	int rb = 0, i;

	for (i = ans.size() - 1; ans[i] > rb && i >= 0; i--)
	{
		ans[i] = rb;
		rb = ans[i] + l[i];
	}

	if (i < 0)
	{
		cout << -1 << endl;

		return;
	}

	for (auto it : ans)
		cout << it + 1 << ' ';
	cout << endl;
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

	cout << "clock: " << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}
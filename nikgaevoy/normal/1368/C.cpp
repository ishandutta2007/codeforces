#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	set<pair<int, int>> ans;

	for (int i = 0; i <= 2 * n; i += 2)
	{
		ans.emplace(i, i);
		ans.emplace(i, i + 1);
		ans.emplace(i + 1, i);
		ans.emplace(i, i + 2);
		ans.emplace(i + 2, i);
		ans.emplace(i + 1, i + 2);
		ans.emplace(i + 2, i + 1);
		ans.emplace(i + 2, i + 2);
	}

	cout << ans.size() << '\n';

	for (auto it : ans)
		cout << it.first << ' ' << it.second << '\n';
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
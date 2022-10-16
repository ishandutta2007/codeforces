#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 mt(736);

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<pair<unsigned, unsigned>> arr(n);

	for (auto &it : arr)
		cin >> it.first;

	unsigned all = 0, mask = ~0u;

	for (auto it : arr)
	{
		mask &= ~(all & it.first);
		all |= it.first;
	}

	for (auto &it : arr)
		it.second = it.first & mask;

	sort(arr.begin(), arr.end(), [](const auto &a, const auto &b) {
		return a.second > b.second;
	});

	for (auto it : arr)
		cout << it.first << ' ';
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
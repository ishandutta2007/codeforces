#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	string a, b;

	cin >> n >> a >> b;

	array<int, 27> cnt{};

	for (auto it : a)
		cnt[it - 'a']++;
	for (auto it : b)
		cnt[it - 'a']--;

	if (count(cnt.begin(), cnt.end(), 0) != cnt.size())
	{
		cout << -1 << '\n';

		return;
	}

	int ans = 0;

	while (!b.empty())
	{
		int st = 0;

		for (auto it : a)
			if (st < b.size() && it == b[st])
				st++;

		ans = max(ans, st);

		b = b.substr(1);
	}

	cout << n - ans << '\n';
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
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
#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);

const string cf = "codeforces";


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	ll k;

	cin >> k;

	vector<int> ans(cf.size(), 1);

	auto cnt = [&ans]()
	{
		ll mult = 1;

		for (auto it : ans)
			mult *= it;

		return mult;
	};

	while (cnt() < k)
		for (int i = 0; i < ans.size() && cnt() < k; i++)
			ans[i]++;

	cerr << cnt() << endl;

	for (int i = 0; i < cf.size(); i++)
		cout << string(ans[i], cf[i]);
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

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<ll> arr(n);

	for (auto &it : arr)
		cin >> it;

	map<ll, int> types;

	auto magic = [](ll x) {
		return (x & (x - 1)) ^ x;
	};

	for (auto it : arr)
		types[magic(it)]++;

	ll best = 1;

	for (const auto &it : types)
		if (it.second > types[best])
			best = it.first;

	vector<ll> ans;

	for (auto it : arr)
		if (magic(it) != best)
			ans.push_back(it);

	cout << ans.size() << endl;

	for (auto it : ans)
		cout << it << ' ';
	cout << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4);
	cout << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}
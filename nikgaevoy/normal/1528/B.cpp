#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


constexpr int mod = 998244353;


template<int n>
constexpr array<int, n + 1> get_den()
{
	array<int, n + 1> ans{};

	for (int i = 1; i < ans.size(); i++)
		for (int j = 0; j < ans.size(); j += i)
			ans[j]++;

	return ans;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> ans = {1, 1};
	auto den = get_den<(int) 1e6>();

	ll sum = 2;

	while (n >= ans.size())
	{
		ans.push_back(int(sum % mod));
		ans.back() += den[ans.size() - 1] - 1;
		ans.back() %= mod;
		sum += ans.back();
	}

	cout << ans.back() << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = chrono::steady_clock::now();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}
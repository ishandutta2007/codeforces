#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;
	ll x;

	cin >> n >> k >> x;
	x--;

	string str;

	cin >> str;
	str += 'a';

	vector<pair<int, int>> bnd;

	for (int l = 0, r; l < ssize(str); l = r + 1)
	{
		for (r = l; r < ssize(str) && str[r] != 'a'; r++);

		auto ast = count(str.begin() + l, str.begin() + r, '*');
		auto b = count(str.begin() + l, str.begin() + r, 'b');

		bnd.emplace_back(b, b + ast * k + 1);
	}

	vector<int> ans(bnd.size());

	for (auto it: ranges::iota_view(0, ssize(ans)))
		ans[it] = bnd[it].first;

	function<void(ll, int)> foo = [&](ll sum, int ind)
	{
		if (ind < 0)
			throw runtime_error("bad luck");

		if ((bnd[ind].second - bnd[ind].first) * (__int128) sum <= x)
			foo(sum * (bnd[ind].second - bnd[ind].first), ind - 1);

		while (x >= sum)
		{
			x -= sum;
			ans[ind]++;
		}
	};

	foo(1, ssize(bnd) - 1);

	string val;

	for (auto it: ans)
	{
		val += string(it, 'b');
		val += 'a';
	}

	val.pop_back();

	cout << val << '\n';
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	cin >> t;

	for (weakly_incrementable auto it: ranges::iota_view(0, t))
		solve_test(cin, cout);
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
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


vector<int> foo(int n, int a, int b)
{
	if (abs(a - b) > 1)
		return {};
	if (a < b)
	{
		auto ans = foo(n, b, a);

		for (auto &it: ans)
			it = n + 1 - it;

		return ans;
	}

	vector<int> ans(n);
	ans[0] = n;

	int cur = 1, pos = 1;

	for (int i = 0; i < a; i++, pos += 2, cur++)
	{
		if (pos + 1 >= ssize(ans))
			return {};
		ans[pos] = cur;
		ans[pos + 1] = n - cur;
	}

	if (a > b)
	{
		pos--;

		auto st = ans.begin() + pos;

		ranges::copy(ranges::iota_view(cur) | views::take(distance(st, ans.end())), st);
	}
	else
	{
		if (pos == ans.size())
			return {};

		auto st = ans.begin() + pos;

		ranges::copy(ranges::iota_view(cur) | views::take(distance(st, ans.end())) | views::reverse, st);
	}

	return ans;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, a, b;

	cin >> n >> b >> a;

	auto ans = foo(n, a, b);

	if (!ans.empty())
	{
		ranges::copy(ans, ostream_iterator<decltype(ans)::value_type>(cout, " "));
		cout << endl;
	}
	else
	{
		cout << -1 << endl;
	}
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
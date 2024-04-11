#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	assert(n % 3 == 0);

	auto ask = [&](int a, int b, int c)
	{
		cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;

		int t;

		cin >> t;

		assert(t != -1);

		return t == 1;
	};

	vector<bool> types(n / 3);

	for (auto it: ranges::iota_view(0, ssize(types)))
		types[it] = ask(3 * it, 3 * it + 1, 3 * it + 2);

	auto fi = int(ranges::find(types, false) - types.begin());
	auto ti = int(ranges::find(types, true) - types.begin());

	vector<int> friends, impostors;

	const vector<bool> q = {types[fi],
	                        ask(3 * ti, 3 * fi + 1, 3 * fi + 2),
	                        ask(3 * ti, 3 * ti + 1, 3 * fi + 2),
	                        types[ti]};

	int ind = 0;

	while (q[ind] == q[ind + 1])
		ind++;

	impostors = {3 * fi + ind};
	friends = {3 * ti + ind};

	auto ask_vert = [&](int it)
	{
		(ask(friends.front(), impostors.front(), it) ? friends : impostors).push_back(it);
	};

	for (auto ii: {fi, ti})
		for (auto it: ranges::iota_view(3 * ii) | views::take(3))
			if (it != friends.front() && it != impostors.front())
				ask_vert(it);

	for (auto it: ranges::iota_view(0, ssize(types)))
		if (it != fi && it != ti)
		{
			auto &majority = types[it] ? friends : impostors;
			auto &minority = types[it] ? impostors : friends;

			if (ask(3 * it, 3 * it + 1, minority.front()) == types[it])
			{
				majority.push_back(3 * it);
				majority.push_back(3 * it + 1);

				ask_vert(3 * it + 2);
			}
			else
			{
				majority.push_back(3 * it + 2);

				auto val = ask(friends.front(), impostors.front(), 3 * it);
				(val ? friends : impostors).push_back(3 * it);
				(val ? impostors : friends).push_back(3 * it + 1);
			}
		}

	assert(friends.size() + impostors.size() == n);

	ranges::sort(impostors);

	cout << "! " << impostors.size();

	for (auto it: impostors)
		cout << ' ' << it + 1;
	cout << endl;
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
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = chrono::steady_clock::now();

	solve();

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}
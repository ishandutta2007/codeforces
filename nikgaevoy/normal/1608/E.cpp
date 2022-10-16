#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


constexpr array dx = {0, 0, -1, 1}, dy = {-1, 1, 0, 0};


template<int ind = 0>
bool check(vector<pair<pair<int, int>, int>> arr, int k)
{
	if (ssize(arr) < k)
		return false;

	if constexpr (ind < 2)
	{
		for (int j = 0; j < ssize(dx); j++)
		{
			auto val = [&](const auto &a) -> int
			{
				return a.first.first * dx[j] + a.first.second * dy[j];
			};

			if (j % 2 == 0)
				ranges::sort(arr, [&](const auto &a, const auto &b)
				{
					return val(a) < val(b);
				});
			else
				ranges::reverse(arr);

			auto st = 0;
			auto cnt = k;

			while (st < ssize(arr) && cnt > 0)
			{
				if (arr[st].second == ind)
					cnt--;
				st++;
			}

			assert(st > 0);

			while (st < ssize(arr) && val(arr[st]) == val(arr[st - 1]))
				st++;

			if (cnt == 0)
			{
				decltype(arr) nxt;

				for (auto[p, c]: arr | views::drop(st))
					if (c != ind)
						nxt.emplace_back(p, c);

				if (check<ind + 1>(nxt, k))
					return true;
			}
		}

		return false;
	}
	else
	{
		return true;
	}
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	assert(n % 3 == 0);

	vector<pair<pair<int, int>, int>> arr(n);

	for (auto &[p, c]: arr)
	{
		cin >> p.first >> p.second >> c;

		c--;
	}

	array val{arr, arr, arr};

	for (auto ind: ranges::iota_view(0, ssize(val)))
		for (auto &[_p, c]: val[ind])
			c = (c + ind) % 3;

	int l = 0, r = n / 3 + 1;

	while (l + 1 < r)
	{
		auto t = midpoint(l, r);

		if (ranges::any_of(val, [&](const auto &tmp)
		{
			return check(tmp, t);
		}))
			l = t;
		else
			r = t;
	}

	cout << 3 * l << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

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
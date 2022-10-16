#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


template<class T>
T &remax(T &x, const T &y)
{
	return x = max(x, y);
}


template<int n>
void solve_n(int tn, istream &cin = std::cin, ostream &cout = std::cout)
{
	if (n != tn)
		return solve_n<max(n - 1, 2)>(tn, cin, cout);

	array<string, n> arr;

	for (auto &it: arr)
		cin >> it;

	ranges::sort(arr, [](const auto &a, const auto &b)
	{
		return a.size() < b.size();
	});

	using ind_t = array<unsigned char, n>;

	map<ind_t, pair<int, ind_t>> dp;
	ind_t best{};
	int val = 0;

	dp[best] = {val, best};

	for (const auto &it: dp)
	{
		const auto &row = it.first;

		if (it.second.first > val)
		{
			val = it.second.first;
			best = row;
		}

		auto move_char = [&](char ch) -> ind_t
		{
			ind_t nxt = row;

			for (int j = 0; j < n; j++)
			{
				nxt[j] = arr[j].find(ch, (size_t) nxt[j]);

				if (nxt[j]++ == (decltype(nxt[j])) string::npos)
					return ind_t{};
			}

			return nxt;
		};

		for (auto ch: string_view(arr.front()).substr(row.front()))
		{
			auto nxt = move_char(ch);

			if (nxt > row)
				remax(dp[nxt], {it.second.first + 1, row});
		}
	}

	string ans;

	while (dp.at(best).first > 0)
	{
		ans += arr.front()[best.front() - 1];
		best = dp.at(best).second;
	}

	ranges::reverse(ans);

	assert(ssize(ans) == val);

	cout << ssize(ans) << endl;
	cout << ans << endl;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	solve_n<10>(n, cin, cout);
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (auto it: ranges::iota_view(0, t))
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
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


template<class T, class Comp>
T &remax(T &x, const T &y, Comp cmp = less<T>{})
{
	return x = max(x, y, cmp);
}


template<class T, class Comp>
T &remin(T &x, const T &y, Comp cmp = less<T>{})
{
	return x = min(x, y, cmp);
}


bool foo(span<int> arr)
{
	vector<vector<pair<pair<int, int>, int>>> dp(arr.size() + 1);
	dp.front() = {{{numeric_limits<int>::lowest(), numeric_limits<int>::lowest()}, false}};

	for (auto i: ranges::iota_view(1, ssize(dp)))
	{
		const auto &x = arr[i - 1];
		auto &nxt = dp[i];

		for (auto j: ranges::iota_view(0, ssize(dp[i - 1])))
		{
			const auto &[p, _s]= dp[i - 1][j];

			if (p.first < -x)
				nxt.emplace_back(pair{-x, p.second}, ~j);
			if (p.first < x)
				nxt.emplace_back(pair{x, p.second}, j);
			if (p.second < -x)
				nxt.emplace_back(pair{p.first, -x}, ~j);
			if (p.second < x)
				nxt.emplace_back(pair{p.first, x}, j);
		}

		ranges::sort(nxt);

		for (int j = 0; j < ssize(nxt); j++)
			for (int t = j + 1; t < ssize(nxt); t++)
				while (t < ssize(nxt) && nxt[j].first <= nxt[t].first && nxt[j].second <= nxt[t].second)
				{
					swap(nxt[t], nxt.back());
					nxt.pop_back();
				}
	}

	if (dp.back().empty())
		return false;

	int ind = 0;

	for (auto i: ranges::iota_view(0, ssize(arr)) | views::reverse)
		if ((ind = dp[i + 1][ind].second) < 0)
		{
			arr[i] = -arr[i];
			ind = ~ind;
		}

	return true;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);

	copy_n(istream_iterator<decltype(arr)::value_type>(cin), arr.size(), arr.begin());

	if (foo(arr))
	{
		cout << "YES\n";
		ranges::copy(arr, ostream_iterator<decltype(arr)::value_type>(cout, " "));
		cout << '\n';
	}
	else
		cout << "NO\n";
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
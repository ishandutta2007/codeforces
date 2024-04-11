#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);

template<class T>
constexpr T &remax(T &x, const T &y)
{
	return x = max(x, y);
}


template<class T>
constexpr T &remin(T &x, const T &y)
{
	return x = min(x, y);
}


template<size_t n>
constexpr auto prec()
{
	array<int, n> ans{};

	ranges::fill(ans, numeric_limits<int>::max());

	auto upd = [&](int t, int val)
	{
		if (t < ssize(ans))
			remin(ans[t], val);
	};

	upd(1, 0);

	for (auto i: ranges::iota_view(1, ssize(ans)))
		for (int j = 1; j * j <= i; j++)
		{
			upd(i + j, ans[i] + 1);
			upd(i + i / j, ans[i] + 1);
		}

	return ans;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	static constexpr auto val = prec<(int) 1e3 + 1>();

	int n, k;

	cin >> n >> k;

	vector<int> arr(n), costs(n);

	copy_n(istream_iterator<int>(cin), n, arr.begin());
	copy_n(istream_iterator<int>(cin), n, costs.begin());

	for (auto &it: arr)
		it = val[it];

	if (accumulate(arr.begin(), arr.end(), 0ll) <= k)
	{
		cout << accumulate(costs.begin(), costs.end(), 0ll) << '\n';

		return;
	}

	vector<int> dp(k + 1);

	for (auto i: ranges::iota_view(0, ssize(arr)))
	{
		auto w = arr[i];
		auto c = costs[i];

		for (auto j: ranges::iota_view(0, ssize(dp)) | views::reverse | views::drop(w))
			remax(dp[j + w], dp[j] + c);
	}

	cout << ranges::max(dp) << '\n';
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
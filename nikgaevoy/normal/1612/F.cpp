#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void sim(time_t q, int &ans, int n, int m, const vector<pair<int, int>> &arr, bool st = true, int a = 0, int b = 0, int cur = 0)
{
	if (cur >= ans)
		return;
	if (a == n - 1 && b == m - 1)
	{
		ans = cur;

		return;
	}

	if ((clock() - q) > 0.9 * CLOCKS_PER_SEC)
		return;

	auto get_val = [&]()
	{
		auto val = a + b + 1;

		if (binary_search(arr.begin(), arr.end(), pair{a, b}))
			val++;

		return val;
	};

	auto val = get_val();

	auto move_a = [&]()
	{
		if (a == n - 1)
			return;

		sim(q, ans, n, m, arr, !st, min(n - 1, val), b, cur + 1);
	};

	auto move_b = [&]()
	{
		if (b == m - 1)
			return;

		sim(q, ans, n, m, arr, !st, a, min(m - 1, val), cur + 1);
	};

	if (st)
	{
		move_a();
		move_b();
	}
	else
	{
		move_b();
		move_a();
	}
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m, q;

	cin >> n >> m >> q;

	vector<pair<int, int>> arr(q);

	for (auto &[a, b]: arr)
	{
		cin >> a >> b;

		a--;
		b--;
	}

	auto ans = numeric_limits<int>::max();

	ranges::sort(arr);

	sim(clock(), ans, n, m, arr);
	sim(clock(), ans, n, m, arr, false);

	cout << ans << endl;
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
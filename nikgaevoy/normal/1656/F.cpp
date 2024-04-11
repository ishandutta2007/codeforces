#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using ld = long double;

mt19937 mt(736);


auto func(const vector<int> &arr, const ll t)
{
	auto w = [&](int a, int b)
	{
		return arr[a] * (ll) arr[b] + t * (__int128) (arr[a] + arr[b]);
	};

	auto ans = w(0, ssize(arr) - 1);

	for (auto i: ranges::iota_view(1, ssize(arr) - 1))
		ans += min(w(0, i), w(i, ssize(arr) - 1));

	return ans;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<ll> arr(n);

	for (auto &it: arr)
		cin >> it;

	ranges::sort(arr);

	auto sum = accumulate(arr.begin(), arr.end(), 0ll);

	if (arr.front() * (n - 1ll) + (sum - arr.front()) > 0 ||
	    arr.back() * (n - 1ll) + (sum - arr.back()) < 0)
	{
		cout << "INF\n";

		return;
	}

	ll a = arr.front() * (n - 1ll) + (sum - arr.front());
	ll b = arr.front() * (ll) (sum - arr.front());

	assert(a <= 0);

	if (a == 0)
	{
		cout << b << '\n';

		return;
	}

	for (int j = 1; j + 1 < ssize(arr); j++)
	{
		auto na = a - (arr.front() + arr[j]) + (arr.back() + arr[j]);
		auto nb = b - (arr.front() * (ll) arr[j]) + (arr.back() * (ll) arr[j]);

		if (na >= 0)
		{
			ld x = (b - nb) / ld(na - a);

			assert(round(a * x + b) == round(na * x + nb));

			cout << ll(round(a * x + b)) << '\n';

			return;
		}

		a = na;
		b = nb;
	}

	assert(false);
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	cin >> t;

	for (weakly_incrementable auto it: ranges::iota_view(0, t))
		solve_test(cin, cout);
}


void gen(ostream &cout = std::cout)
{
	cout << 1 << endl;

	const int n = 10;

	cout << n << endl;

	uniform_int_distribution<int> uid(-1e6, 1e6);

	for (auto i: ranges::iota_view(0, n))
		cout << uid(mt) << ' ';
	cout << endl;
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
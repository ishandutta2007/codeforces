#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


constexpr ll sq_naive(ll x)
{
	int ans = 0;

	for (int i = 1; i < x; i++)
		if (i % int(floor(sqrt(i))) == 0)
			ans++;

	return ans;
}

template<int add>
constexpr ll sq_smart(ll x)
{
	ll l = 0, r = sqrt(x) + 10;

	while (l + 1 < r)
	{
		auto t = midpoint(l, r);

		if (t * (t + add) < x)
			l = t;
		else
			r = t;
	}

	return r;
}


ll sq(ll x)
{
	auto q = sq_smart<0>(x) + sq_smart<1>(x) + sq_smart<2>(x);

	return q;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	ll l, r;

	cin >> l >> r;
	r++;

	cout << sq(r) - sq(l) << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	cin >> t;

	for (int i = 0; i < t; i++)
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

#ifdef STRESS
	for (int cnt = 1;; cnt++)
	{
		stringstream ss, in1, out1, in2, out2;

		gen(ss);

		in1 << ss.str();
		in2 << ss.str();

		solve(in1, out1);
		stress(in2, out2);

		if (out1.str() != out2.str())
		{
			cout << "fail: " << cnt << endl;
			cout << ss.str();
			cout << "solve:" << endl;
			cout << out1.str();
			cout << "stress:" << endl;
			cout << out2.str();

			break;
		}
		else if (cnt % 100 == 0)
			cout << "ok: " << cnt << endl;
	}
#endif

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}
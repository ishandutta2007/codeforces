#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


bool foo(int a, int b, bool type, bool who)
{
	static map<tuple<int, int, bool, bool>, bool> dp;

	assert(a >= 0 && b >= 0);

	if (a == 0 && b == 0)
		return type == who;

	if (!dp.count({a, b, type, who}))
	{
		bool ans = false;

		if (a > 0)
			ans |= !foo(a - 1, b, type, !who);
		if (b > 0)
			ans |= !foo(a, b - 1, who == type, !who);

		dp[{a, b, type, who}] = ans;
	}

	return dp[{a, b, type, who}];
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	array<int, 2> cnt{};

	for (int i = 0; i < n; i++)
	{
		int t;

		cin >> t;

		cnt[t % 2 != 0]++;
	}

	cout << (foo(cnt[0], cnt[1], false, false) ? "Alice" : "Bob") << '\n';
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
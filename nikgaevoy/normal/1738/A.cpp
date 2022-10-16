#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


ll foo(array<vector<ll>, 2> pws)
{
	auto q = min(ssize(pws[1]) + 1, ssize(pws[0]));
	auto w = min(ssize(pws[1]), ssize(pws[0]));

	auto ans = 2 * accumulate(pws[0].begin(), pws[0].begin() + q, 0ll) +
	           accumulate(pws[0].begin() + q, pws[0].end(), 0ll) +
	           2 * accumulate(pws[1].begin(), pws[1].begin() + w, 0ll) +
	           accumulate(pws[1].begin() + w, pws[1].end(), 0ll);

	return ans;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<bool> type(n);

	for (int i = 0; i < n; i++)
	{
		int t;

		cin >> t;

		type[i] = (t == 1);
	}

	vector<int> arr(n);

	for (auto &it: arr)
		cin >> it;

	array<vector<ll>, 2> pws{};

	for (int i = 0; i < n; i++)
		pws[type[i]].push_back(arr[i]);

	if (pws[0].size() < pws[1].size())
		pws[0].swap(pws[1]);

	for (auto &row: pws)
		ranges::sort(row, greater<ll>());

	ll ans = 0;

	for (int i = 0; i < ssize(pws); i++)
	{
		auto &row = pws[i];

		if (!row.empty())
		{
			auto add = row.back();
			row.pop_back();

			if (i == 0)
				swap(pws.front(), pws.back());
			ans = max(ans, foo(pws) + add);
			if (i == 0)
				swap(pws.front(), pws.back());

			row.push_back(add);
		}
	}

	cout << ans << endl;
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
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


bool solve(int n, array<pair<int, int>, 3> arr, pair<int, int> target)
{
	pair<int, int> cent = arr.front();

	for (auto it: arr)
	{
		int x = 0, y = 0;

		for (auto q: arr)
		{
			if (it.first == q.first)
				x++;
			if (it.second == q.second)
				y++;
		}

		if (x == 2 && y == 2)
			cent = it;
	}

	auto col = [](pair<int, int> x)
	{
		return (x.first + x.second) % 2;
	};

	if (target.first == cent.first || target.second == cent.second)
		return true;

	if (col(target) == col(cent) && (target.first % 2 != cent.first % 2 || target.second % 2 != cent.second % 2))
		return false;

	if ((cent.first == 0 || cent.first == n - 1) &&
	    (cent.second == 0 || cent.second == n - 1))
		return false;

	return true;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	array<pair<int, int>, 3> arr{};

	for (auto &[x, y]: arr)
	{
		cin >> x >> y;
		x--;
		y--;
	}

	pair<int, int> target;

	cin >> target.first >> target.second;
	target.first--;
	target.second--;

	cout << (solve(n, arr, target) ? "YES\n" : "NO\n");
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
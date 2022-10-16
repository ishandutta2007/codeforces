#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


tuple<int, int, int> slv(const vector<int> &arr)
{
	int best = 0, al = 0, ar = 0;

	for (int l = 0, r; l < ssize(arr); l = r)
		if (arr[l] != 0)
		{
			for (r = l; r < ssize(arr) && arr[r] != 0; r++);

			int q = 0;
			bool neg = false;

			for (int i = l; i < r; i++)
			{
				if (abs(arr[i]) == 2)
					q++;
				if (arr[i] < 0)
					neg = !neg;
			}

			while (neg)
			{
				if (abs(arr[l]) == 2)
					q--;
				if (arr[l] < 0)
					neg = !neg;
				l++;
			}

			if (q > best)
			{
				best = q;
				al = l;
				ar = r;
			}
		}
		else
			r = l + 1;

	return {best, al, ssize(arr) - ar};
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);

	for (auto &it: arr)
		cin >> it;

	auto ansl = slv(arr);

	ranges::reverse(arr);

	auto ansr = slv(arr);

	if (ansr > ansl)
		cout << get<2>(ansr) << ' ' << get<1>(ansr) << '\n';
	else
		cout << get<1>(ansl) << ' ' << get<2>(ansl) << '\n';
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
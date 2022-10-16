#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<int> arr(m);

	for (auto &it: arr)
	{
		cin >> it;
		it--;
	}

	vector<int> cnt(n);

	for (auto it: arr)
		cnt[it]++;

	vector<int> q(m + 1);

	for (auto it: cnt)
		q[it]++;

	int l = 0, r = m;

	while (q[l] == 0)
		l++;
	while (q[r] == 0)
		r--;

	while (l + 2 < r)
	{
		auto sz = min(q[l], q[r]);

		q[l + 2] += sz;
		q[l] -= sz;
		q[r] -= sz;
		q[r - 1] += sz;

		while (q[l] == 0)
			l++;
		while (q[r] == 0)
			r--;
	}

	cout << r << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

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
	auto st = clock();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}
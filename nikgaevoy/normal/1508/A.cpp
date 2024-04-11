#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	array<string, 3> arr;

	for (auto &it : arr)
		cin >> it;

	array<int, 3> pnt{};

	for (int i = 0; i < 3 * n; i++)
	{
		if (auto t = max_element(pnt.begin(), pnt.end()) - pnt.begin(); pnt[t] == 2 * n)
		{
			int sec = !t;

			for (int j = 0; j < pnt.size(); j++)
				if (j != t && pnt[j] > pnt[sec])
					sec = j;

			cout << arr[sec].substr(pnt[sec]);
			i += arr[sec].substr(pnt[sec]).size();
			assert(i <= 3 * n);
			cout << string(3 * n - i, '0');

			break;
		}

		array<char, 3> q{};

		for (int j = 0; j < pnt.size(); j++)
			q[j] = arr[j][pnt[j]];

		sort(q.begin(), q.end());

		char nxt = q[1];

		cout << nxt;

		for (int j = 0; j < pnt.size(); j++)
			if (arr[j][pnt[j]] == nxt)
				pnt[j]++;
	}
	cout << endl;
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
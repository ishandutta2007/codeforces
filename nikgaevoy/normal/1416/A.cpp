#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);

	for (auto &it : arr)
		cin >> it;

	vector<int> last(n + 1, -1), sz(n + 1, 0);

	for (int i = 0; i < arr.size(); i++)
	{
		sz[arr[i]] = max(sz[arr[i]], i - last[arr[i]]);
		last[arr[i]] = i;
	}

	for (int i = 0; i < last.size(); i++)
		sz[i] = max(sz[i], n - last[i]);

	for (auto &it : sz)
		it--;

	vector<int> st(n + 1, numeric_limits<int>::max());

	for (int i = 0; i < sz.size(); i++)
		st[sz[i]] = min(st[sz[i]], i);

	for (int i = 1; i < st.size(); i++)
		st[i] = min(st[i], st[i - 1]);

	st.pop_back();

	for (auto it : st)
		cout << (it == numeric_limits<int>::max() ? -1 : it) << ' ';
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
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


template<class T>
int slv(T ab, T ae, T sb, T se)
{
	int pref = 0, ans = 0;

	while (sb != se)
	{
		int cnt = ae - lower_bound(ab, ae, *sb);

		ans = max(ans, pref + int(lower_bound(sb, se, *sb + cnt) - sb));

		if (binary_search(ab, ae, *sb))
			pref++;

		sb++;
	}

	return ans;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<int> arr(n), spec(m);

	for (auto &it : arr)
		cin >> it;
	for (auto &it : spec)
		cin >> it;

	int ap = lower_bound(arr.begin(), arr.end(), 0) - arr.begin();
	int sp = lower_bound(spec.begin(), spec.end(), 0) - spec.begin();

	for (auto &it : arr)
		it = -abs(it);
	for (auto &it : spec)
		it = -abs(it);

	cout << slv(arr.begin(), arr.begin() + ap, spec.begin(), spec.begin() + sp) +
	        slv(arr.rbegin(), arr.rend() - ap, spec.rbegin(), spec.rend() - sp) << endl;
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
#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> diff (n - 1);

	for (auto &it : diff)
		cin >> it;

	vector<int> ps (diff.size () + 1);

	for (int i = 1; i < ps.size (); i++)
		ps[i] = diff[i - 1] + ps[i - 1];

	int mn = *min_element(ps.begin(), ps.end ());

	for (auto &it : ps)
		it += -mn + 1;

	set<int> tmp (ps.begin(), ps.end ());

	if (*tmp.begin() != 1 || *--tmp.end() != n || tmp.size () != ps.size ())
	{
		cout << -1 << endl;

		return;
	}

	for (auto it : ps)
		cout << it << ' ';
	cout << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}
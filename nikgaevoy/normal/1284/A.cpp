#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<string> s(n), t(m);

	for (auto &it : s)
		cin >> it;
	for (auto &it : t)
		cin >> it;

	int q;

	cin >> q;

	for (int i = 0; i < q; i++)
	{
		int y;

		cin >> y;
		y--;

		cout << s[y % n] << t[y % m] << endl;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}
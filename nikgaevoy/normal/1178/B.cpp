#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	string str;

	cin >> str;

	vector<int> ps(str.size());

	for (int i = 1; i < ps.size(); i++)
		ps[i] = ps[i - 1] + (str.substr(i - 1, 2) == "vv" ? 1 : 0);

	ll ans = 0;

	for (int i = 0; i < str.size(); i++)
		if (str[i] == 'o')
			ans += ps[i] * (ll) (ps.back() - ps[i]);


	cout << ans << endl;
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
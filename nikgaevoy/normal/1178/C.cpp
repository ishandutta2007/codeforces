#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);
const int mod = 998244353;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int w, h;

	cin >> w >> h;

	int ans = 1;

	for (int i = 0; i < w + h; i++)
		ans = (2 * ans) % mod;

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
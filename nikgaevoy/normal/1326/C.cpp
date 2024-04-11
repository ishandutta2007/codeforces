#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);

const int mod = 998244353;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;

	cin >> n >> k;

	vector<int> perm(n);

	for (auto &it : perm)
		cin >> it;

	vector<int> fix;

	ll sum = 0;

	for (int i = 0; i < n; i++)
		if (perm[i] > n - k)
		{
			sum += perm[i];
			fix.push_back(i);
		}

	cout << sum << ' ';

	ll ans = 1;

	for (int i = 1; i < fix.size(); i++)
	{
		ans *= fix[i] - fix[i - 1];
		ans %= mod;
	}

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
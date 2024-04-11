#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;

	cin >> n >> k;

	string ans(n, '1');

	if (k == 1)
	{
		ans.front() = '0';
	}
	else
	{
		int per = (n + 2 - k) / 2;

		for (int i = 0; i < n; i += per)
			ans[i] = '0';
	}

	cout << ans << endl;
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
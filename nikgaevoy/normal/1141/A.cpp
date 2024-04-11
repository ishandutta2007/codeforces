#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	int cnt = 0;

	while (n < m)
	{
		if (((n & (n - 1)) ^ n) != ((m & (m - 1)) ^ m))
			n *= 2;
		else
			n *= 3;

		cnt++;
	}

	cout << (n == m ? cnt : -1) << endl;
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
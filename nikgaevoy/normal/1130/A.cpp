#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	int pos = 0, neg = 0, zer = 0;

	for (int i = 0; i< n; i++)
	{
		int t;

		cin >> t;

		if (t == 0)
			zer++;
		else if (t > 0)
			pos++;
		else
			neg++;
	}

	if (pos >= (n + 1) / 2)
		cout << 1 << endl;
	else if (neg >= (n + 1) / 2)
		cout << -1 << endl;
	else
		cout << 0 << endl;
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
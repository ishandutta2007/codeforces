#include <bits/stdc++.h>


using namespace std;


using ll = long long;
mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<vector<ll>> matr(n, vector<ll>(n));

	for (auto &row : matr)
		for (auto &it : row)
			cin >> it;

	for (int i = 0; i < n; i++)
	{
		int a = !i;

		int b = max(a, i) == 1 ? 2 : 1;

		cout << (ll)sqrt(matr[a][i] * matr[i][b] / matr[a][b]) << ' ';
	}

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

	cout << setprecision(4);
	cout << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}
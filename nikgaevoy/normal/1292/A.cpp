#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, q;

	cin >> n >> q;

	int cnt = 0;

	vector<vector<bool>> arr(n, vector<bool>(2));

	for (int i = 0; i < q; i++)
	{
		int r, c;

		cin >> c >> r;
		r--;
		c--;

		for (int j = r - 1; j <= r + 1; j++)
			if (0 <= j && j < arr.size() && arr[r][c] && arr[j][1 - c])
				cnt--;

		arr[r][c] = !arr[r][c];

		for (int j = r - 1; j <= r + 1; j++)
			if (0 <= j && j < arr.size() && arr[r][c] && arr[j][1 - c])
				cnt++;

		cout << (cnt > 0 ? "No" : "Yes") << endl;
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

	cout << "clock: " << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}
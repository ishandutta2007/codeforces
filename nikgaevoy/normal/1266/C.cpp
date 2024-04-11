#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int r, c;

	cin >> r >> c;

	if (r == 1 && c == 1)
	{
		cout << 0 << endl;

		return;
	}

	vector<int> br(r), bc(c);

	if (c == 1)
	{
		iota(bc.begin(), bc.end(), 1);
		iota(br.begin(), br.end(), 2);
	}
	else
	{
		iota(br.begin(), br.end(), 1);
		iota(bc.begin(), bc.end(), r + 1);
	}

	vector<vector<int>> ans(r, vector<int>(c));

	for (int i = 0; i < ans.size(); i++)
		for (int j = 0; j < ans[i].size(); j++)
			ans[i][j] = br[i] * bc[j];

	for (const auto &row : ans)
	{
		for (auto it : row)
			cout << it << ' ';
		cout << endl;
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
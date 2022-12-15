#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

ll solve(void);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_tests;
	cin >> nb_tests;

	for (int i(0); i < nb_tests; ++i)
		solve();
}

ll solve(void)
{
	int nb_lig, nb_col, prix_1, prix_2;
	cin >> nb_lig >> nb_col >> prix_1 >> prix_2;
	vector<vector<bool>> cases(nb_lig, vector<bool>(nb_col));
	for (int lig(0); lig < nb_lig; ++lig)
		for (int col(0); col < nb_col; ++col)
		{
			char c;
			cin >> c;
			cases[lig][col] = c=='*';
		}
	if (prix_1 * 2 <= prix_2)
	{
		int rep(0);
		for (int lig(0); lig < nb_lig; ++lig)
			for (int col(0); col < nb_col; ++col)
				rep += prix_1 * !cases[lig][col];
		cout << rep << '\n';
		return 0;
	}
	int rep(0);
	for (int lig(0); lig < nb_lig; ++lig)
	{
		int col(0);
		while (col < nb_col)
		{
			if (cases[lig][col])
			{
				++col;
				continue;
			}
			if (col+1 < nb_col and !cases[lig][col+1])
			{
				rep += prix_2;
				++col;
			}
			else
				rep += prix_1;
			++col;
		}
	}
	cout << rep << '\n';

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MAXDIM = 500;
const int MAXDIS = 11;
int dp[MAXDIS][MAXDIM][MAXDIM];

inline void chkmin(int &a, int b)
{
	a = min(a, b);
}

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int nbLig, nbCol, lenNecessaire;
	cin >> nbLig >> nbCol >> lenNecessaire;

	vector<vector<int>> goRight(nbLig, vector<int>(nbCol-1));
	for (auto &arr : goRight)
		for (auto &v : arr)
			cin >> v;
	vector<vector<int>> goDown(nbLig-1, vector<int>(nbCol));
	for (auto &arr : goDown)
		for (auto &v : arr)
			cin >> v;
	
	if (lenNecessaire % 2)
	{
		for (int lig(0); lig < nbLig; ++lig)
		{
			for (int col(0); col < nbCol; ++col)
				cout << -1 << ' ';
			cout << '\n';
		}
		return 0;
	}
	for (int lig(0); lig < nbLig; ++lig)
		for (int col(0); col < nbCol; ++col)
			dp[0][lig][col] = 0;

	lenNecessaire/=2;
	for (int dis(0); dis < lenNecessaire; ++dis)
	{
		for (int lig(0); lig < nbLig; ++lig)
			for (int col(0); col < nbCol; ++col)
			{
				int &x = dp[dis+1][lig][col];
				x = 1e9;
				if (lig)
					chkmin(x, dp[dis][lig-1][col] + goDown[lig-1][col]);
				if (col)
					chkmin(x, dp[dis][lig][col-1] + goRight[lig][col-1]);
				if (lig+1 <nbLig)
					chkmin(x, dp[dis][lig+1][col] + goDown[lig][col]);
				if (col+1 < nbCol)
					chkmin(x, dp[dis][lig][col+1] + goRight[lig][col]);
			}
	}
		for (int lig(0); lig < nbLig; ++lig)
			for (int col(0); col < nbCol; ++col)
				cout << 2*dp[lenNecessaire][lig][col] << " \n"[col==nbCol-1];
}
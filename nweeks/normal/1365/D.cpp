#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())

using ll = long long;

pair<int, int> D[] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

vector<vector<char>> carte;

void dfs(int lig, int col)
{
	if (carte[lig][col] == '#')
		return ;
	carte[lig][col] = '#';
	for (auto [dy, dx] : D)
		if (lig+dy>= 0  and lig + dy < SZ(carte) and col+dx >= 0 and col+dx < SZ(carte[0]))
			dfs(lig+dy, col+dx);
}

bool solve()
{
	int nbLig, nbCol;
	cin >> nbLig >> nbCol;

	carte= vector<vector<char>>(nbLig, vector<char>(nbCol));
	for (auto &v : carte)
		for (auto &c : v)
			cin >> c;

	for (int lig(0); lig < nbLig; ++lig)
		for (int col(0); col < nbCol; ++col)
			if (carte[lig][col] == 'B')
				for (auto [dy, dx] : D)
					if (lig + dy >= 0 and lig + dy < nbLig and col + dx < nbCol and col + dx >= 0)
					{
						if (carte[lig+dy][col+dx] == '.')
							carte[lig+dy][dx+col] = '#';
						else if (carte[lig+dy][col+dx] == 'G')
							return false;
					}
	dfs(nbLig-1, nbCol-1);
	for (int lig(0); lig < nbLig; ++lig)
		for (int col(0); col < nbCol; ++col)
			if (carte[lig][col] == 'G')
				return false;
	return true;
}

int main(void)
{
	int nbTests(1);
	cin >> nbTests;
	for (int i(0); i < nbTests; ++i)
		cout << (solve() ? "Yes" : "No") << '\n';
}
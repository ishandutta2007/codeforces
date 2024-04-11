#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAXGRID = 1001;
const int MAXD = 4;
int DX[] = {-1,1, 0, 0};
int DY[] = {0,0,-1,1};

bool grid[MAXGRID][MAXGRID];
bool visited[MAXGRID][MAXGRID];
int nb_lig, nb_col;
bool blocked[MAXGRID][MAXGRID];
pair<int, int> seg_lig[MAXGRID], seg_col[MAXGRID];

bool is_safe(int lig, int col)
{
	return lig < nb_lig and lig >= 0 and col < nb_col and col >= 0;
}

void dfs(int lig, int col)
{
	if (visited[lig][col]) return;
	visited[lig][col] = true;
	for (int d(0); d < 4; ++d)
	{
		int lig2 = lig+DY[d];
		int col2 = col + DX[d];
		if (is_safe(lig2, col2) and grid[lig2][col2])
			dfs(lig2, col2);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> nb_lig >> nb_col;
	for (int lig(0); lig < nb_lig; ++lig)
		for (int col(0); col < nb_col; ++col)
		{
			char c;
			cin >> c;
			grid[lig][col] = (c=='#');
		}	
	for (int lig(0); lig < nb_lig; ++lig)
	{
		int lft(0);
		while (lft < nb_col and !grid[lig][lft])
			++lft;
		if (lft == nb_col)
		{
			seg_lig[lig] = {-1,-1};
			continue ;
		}
		int rgt(lft);
		while (rgt+1 < nb_col and grid[lig][rgt+1])
			++rgt;
		seg_lig[lig] = make_pair(lft, rgt);
		for (int i(rgt+1); i < nb_col; ++i)
			if (grid[lig][i])
			{
				cout <<-1 << endl;
				return 0;
			}
	}
	int lig_vide(0);
	while (lig_vide < nb_lig and seg_lig[lig_vide].first != -1)
		++lig_vide;
	int col_vide(0);
	while (col_vide < nb_col)
	{
		bool empty(true);
		for (int lig(0); lig < nb_lig; ++lig)
			if (grid[lig][col_vide])
				empty=false;
		if (empty)
			break;
		col_vide++;
	}
	if ((lig_vide!=nb_lig) ^ (col_vide != nb_col))
	{
		bool empty(true);
		for (int lig(0); lig < nb_lig; ++lig)
			for (int col(0); col < nb_col; ++col)
				empty &= !grid[lig][col];
		cout << (empty ? 0 : -1) << endl;
		return 0;
	}
	int nb_necessaire(0);
	for (int lig(0); lig < nb_lig; ++lig)
		for (int col(0); col < nb_col; ++col)
			if (!visited[lig][col] and grid[lig][col])
			{
				++nb_necessaire;
				dfs(lig, col);
			}

	for (int col(0); col < nb_col; ++col)
	{
		int lft(0);
		while (lft < nb_lig and !grid[lft][col])
			++lft;
		while (lft < nb_lig and grid[lft][col])
			++lft;
		while (lft < nb_lig and !grid[lft][col])
			++lft;
		if (lft < nb_lig)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	cout << nb_necessaire<< endl;
}
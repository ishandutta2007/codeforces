#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 500;

int grid[MAXN][MAXN];
int dim;
int restant;

void fill(int iLig, int iCol, int aMettre)
{
	if (iLig == dim or iCol == dim or iCol < 0 or iLig < 0 or iLig < iCol) return;
	if (!restant or grid[iLig][iCol]) return ;
	//cout << aMettre << ' ' << iLig << ' ' << iCol << endl;
	grid[iLig][iCol] = aMettre;
	restant--;
	fill(iLig, iCol+1, aMettre);
	fill(iLig+1, iCol, aMettre);
	fill(iLig, iCol-1, aMettre);
}

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> dim;
	vector<int> perm(dim);
	for (auto &v : perm)
		cin >> v;

	for (int iDiag(dim-1); iDiag >= 0; --iDiag)
	{
		restant = perm[iDiag];
		fill(iDiag, iDiag, perm[iDiag]);
		assert(!restant);
	}
	for (int iLig(0); iLig < dim; ++iLig)
	{
		for (int col(0); col <= iLig; ++col)
			cout << grid[iLig][col] << ' ';
		cout << endl;
	}
}
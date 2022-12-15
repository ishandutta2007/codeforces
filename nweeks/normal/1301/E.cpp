#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAX = 500;
const int MAXP = 10;
int bsq[4][MAX+1][MAX+1];
int ans[MAX][MAX];
int sparse[MAXP][MAX][MAXP][MAX];
map<char, int> col;

int query(int line_lo, int line_up, int col_lo, int col_up)
{
	if (line_lo > line_up or col_lo > col_up) return 0;
	int diff_line = line_up-line_lo;
	int diff_col = col_up - col_lo;
	int ans(0);
	for (int p(0); p < MAXP; ++p)
		if ((1<<p) & diff_line)
		{
			int cc = col_lo;
			for (int q(0); q < MAXP; ++q)
				if ((1<<q) & diff_col)
				{
					ans = max(ans, sparse[p][line_lo][q][cc]);
					cc += (1<<q);
				}
			line_lo += (1<<p);
		}
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	col['R'] = 0;
	col['G'] = 1;
	col['Y'] = 2;
	col['B'] = 3;
	int nb_lig, nb_col, nb_requetes;
	cin >> nb_lig >> nb_col >> nb_requetes;
	for (int i(0); i < nb_lig; ++i)
		for (int j(0); j < nb_col; ++j)
		{
			char c;
			cin >> c;
			bsq[col[c]][i][j]=1;
		}
	for (int c(0); c < 4; ++c)
		for (int line(nb_lig-1); line >= 0; --line)
			for (int col(nb_col-1); col >= 0; --col)
				if (bsq[c][line][col])
					bsq[c][line][col] = min({bsq[c][line+1][col], bsq[c][line][col+1], bsq[c][line+1][col+1]})+1;
	for (int line(0); line < nb_lig; ++line)
		for (int col(0); col < nb_col; ++col)
		{
			int sz = bsq[0][line][col];
			bool can = (line + 2*sz<= nb_lig and col+2*sz<=nb_col and bsq[1][line][col+sz]>=sz
				 and bsq[2][line+sz][col] >= sz and bsq[3][line+sz][col+sz]>=sz);
			if (can and sz)
				ans[line + sz-1][col+sz-1] = max(ans[line+sz-1][col+sz-1], sz);
		}

	for (int line(0); line < nb_lig; ++line)
		for (int col(0); col < nb_col; ++col)
			sparse[0][line][0][col] = ans[line][col];
	for (int p(1); p < MAXP; ++p)
		for (int line(0); line < nb_lig; ++line)
			for (int col(0); col < nb_col; ++col)
			{
				if (col + (1<<(p-1)) < nb_col)
					sparse[0][line][p][col] = max(sparse[0][line][p-1][col], sparse[0][line][p-1][col+(1<<(p-1))]);
				else
					sparse[0][line][p][col] = sparse[0][line][p-1][col];					
			}
	for (int p(1); p < MAXP; ++p)
		for (int line(0); line < nb_lig; ++line)
			for (int q(0); q < MAXP; ++q)
				for (int col(0); col < nb_col; ++col)
				{
					if (line + (1<<(p-1)) < nb_lig)
						sparse[p][line][q][col] = max(sparse[p-1][line][q][col], sparse[p-1][line+(1<<(p-1))][q][col]);
					else
						sparse[p][line][q][col] = sparse[p-1][line][q][col];
				}
	while (nb_requetes--)
	{
		int line_lo, line_up, col_lo, col_up;
		cin >> line_lo >> col_lo >> line_up >> col_up;
		line_lo--, col_lo--;
		int lo(0), up(nb_lig);
		while (lo < up)
		{
			int mid = (lo+up+1)/2;
			if (query(line_lo+mid-1, line_up - mid, col_lo+mid-1,col_up - mid) >= mid)
				lo = mid;
			else
				up = mid-1;
		}
		cout << 4*lo*lo << endl;
	}
}
#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAXD = 4;
int DX[] = {-1, 1, 0, 0};
int DY[] = {0,0,-1, 1};
const int MAXN = 1000;

int nb_lig, nb_col;
int carte[MAXN][MAXN];
ll first_change[MAXN][MAXN];

bool is_safe(int lig, int col)
{
	return lig >= 0 and lig < nb_lig and col >= 0 and col < nb_col;
}

bool check_same(int lig, int col)
{
	for (int d(0); d < 4; ++d)
	{
		int lig2 = lig + DY[d];
		int col2 = col + DX[d];
		if (is_safe(lig2, col2) and carte[lig2][col2] == carte[lig][col])
			return true;
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_requetes;
	cin >> nb_lig >> nb_col >> nb_requetes;
	for (int i(0); i < nb_lig; ++i)
		for (int j(0); j < nb_col; ++j)
		{
			char c;
			cin >> c;
			carte[i][j] = (c == '1') ? 1 : 0;
		}
	queue<tuple<int,int,int> > q;
	for (int lig(0); lig < nb_lig; ++lig)
		for (int col(0); col < nb_col; ++col)
		{
			if (check_same(lig, col))
			{
				q.push({lig, col, 0});
				first_change[lig][col] = 0;
			}
			else
				first_change[lig][col] = 1e18;
		}
	while (SZ(q))
	{
		auto [lig, col, dis] = q.front(); q.pop();
		for (int d(0); d < 4; ++d)
		{
			int lig2 = lig + DY[d];
			int col2 = col + DX[d];
			if (is_safe(lig2, col2) and carte[lig2][col2] != carte[lig][col] and first_change[lig2][col2] == 1e18)
			{
				first_change[lig2][col2] = dis+1;
				q.push({lig2, col2, dis+1});
			}
		}
	}


	while (nb_requetes--)
	{
		ll lig, col, t;
		cin >> lig >> col >> t;
		--lig, --col;

		if (t <= first_change[lig][col])
			cout << carte[lig][col] << '\n';
		else
			cout << ( (t - first_change[lig][col])%2 == 1 ? 1-carte[lig][col] : carte[lig][col]) << '\n';
	}

}
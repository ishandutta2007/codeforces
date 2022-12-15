#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

int DX[4] = {-1, 1, 0, 0};
int DY[4] = {0,0,-1,1};
const int MAXP = 21;
map<char,int> moves;
vector<vector<pair<int, int>>> where[2];;
vector<vector<bool>> black_cells;
vector<vector<bool> > black, exists;
int nb_lig, nb_col;

void solve(void)
{
	cin >> nb_lig >> nb_col;
	black_cells.clear();
	black.clear();
	exists.clear();
	for (int p(0); p < 2; ++p)
	{
		where[p].clear();
		where[p].resize(nb_lig);
		for (int lig(0); lig < nb_lig; ++lig)
			where[p][lig].resize(nb_col);
	}
	black.resize(nb_lig);
	black_cells.resize(nb_lig);
	exists.resize(nb_lig);
	for (int lig(0); lig < nb_lig; ++lig)
	{
		black_cells[lig].resize(nb_col);
		black[lig].resize(nb_col);
		exists[lig].resize(nb_col);
		for (int col(0); col < nb_col; ++col)
		{
			char c;
			cin >> c;
			black_cells[lig][col] = (c=='0');
		}
	}

	for (int lig(0); lig < nb_lig; ++lig)
		for (int col(0); col < nb_col; ++col)
		{
			black[lig][col]=exists[lig][col]=false;
			char c; cin >> c;
			where[0][lig][col] = make_pair(lig+DY[moves[c]], col+DX[moves[c]]);
		}
	for (int p(1); p < MAXP; ++p)
		for (int lig(0); lig < nb_lig; ++lig)
			for (int col(0); col < nb_col; ++col)
				where[p%2][lig][col] = where[1-p%2][ where[1-p%2][lig][col].first ]
												[ where[1-p%2][lig][col].second ];
	for (int lig(0); lig < nb_lig; ++lig)
		for (int col(0); col < nb_col; ++col)
		{
			auto [y,x] = where[(MAXP-1)%2][lig][col];
			if (black_cells[lig][col])
				black[y][x]=true;
			exists[y][x]=true;
		}
	int ans1(0), ans2(0);
	for (int lig(0); lig < nb_lig; ++lig)
		for (int col(0); col < nb_col; ++col)
			ans1+=exists[lig][col], ans2+=black[lig][col];
	cout<<ans1 << ' ' << ans2 << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	moves['L']=0;
	moves['R']=1;
	moves['U']=2;
	moves['D']=3;
	int __t(1);
	cin >> __t;
	while (__t--)
		solve();
}
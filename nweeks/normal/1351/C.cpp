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

int DX[] = {-1, 1, 0, 0};
int DY[] = {0,0,-1, 1};

ll solve(void)
{
	string s;
	cin >> s;
	map<char, int> move;
	move['W'] = 0;
	move['E'] = 1;
	move['N'] = 2;
	move['S'] = 3;
	map<pair<pair<int,int>, pair<int, int>>, bool> seen;
	int x(0), y(0);
	int ans(0);
	for (auto c : s)
	{
		int nxtx(x+DX[move[c]]), nxty(y+DY[move[c]]);
		if (seen[{ {x, y}, {nxtx, nxty} }])
			ans++;
		else
			ans += 5;
		seen[{ {x,y}, {nxtx, nxty} }] = true;
		seen[{ {nxtx, nxty}, {x, y} }] = true;
		x = nxtx, y = nxty;
	}
	cout << ans << '\n';
	return 0;
}
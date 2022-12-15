#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;
const int MAXK = 1e4+1;

bool ret[MAX][MAX][MAXK];

bool rec(int k, int n, int m)
{
	if (k < 0) return false;
	if (n <= 0 or m <= 0)
		return false;
	if (n == 1 and m == 1)
		return !k;
	if (ret[k][n][m]!=-1)
		return ret[k][n][m];
	return ret[k][m][m] = (rec(k-n, n, m-1) or rec(k-m, n-1, m));
}

bool solve()
{
	int n, m, k;
	cin >> n >>m >> k;
	//return rec(k, n, m);
	return ret[n][m][k];
}

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ret[1][1][0] = true;

	for (int n(1); n < MAX; ++n)
		for (int m(1); m < MAX; ++m)
			for (int k(0); k < MAXK; ++k)
			{
				if (k >= n)
					ret[n][m][k] |= ret[n][m-1][k-n];
				if (k >= m)
					ret[n][m][k] |= ret[n-1][m][k-m];
			}


	//rec(MAXK-1, MAX-1, MAX-1);
			
	int tc;
	cin >> tc;
	while (tc--)
		cout << (solve() ? "YES" : "NO") << endl;
}
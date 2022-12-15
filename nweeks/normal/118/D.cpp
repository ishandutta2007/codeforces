#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e8;

int ways[101][101][11][11];

int n1, n2, k1, k2;

int comp(int left1, int left2, int consec1, int consec2)
{
	if (left1 < 0 or left2 < 0 or consec1 > k1 or consec2 > k2) return 0;
	if (left1 == 0 and left2 == 0)
		return 1;
	if (ways[left1][left2][consec1][consec2] != -1)
		return ways[left1][left2][consec1][consec2];
	return ways[left1][left2][consec1][consec2] = (comp(left1-1, left2, consec1+1, 0) + comp(left1, left2-1, 0, consec2+1))%MOD;
}

int main(void)
{
	cin >> n1 >> n2 >> k1 >> k2;
	for (int i(0); i < 101;++i)
		for (int j(0); j < 101; ++j)
			for (int k(0); k <= 10; ++k)
				for (int l(0); l <= 10; ++l)
					ways[i][j][k][l] = -1;
	cout << comp(n1, n2, 0, 0) << endl;
}
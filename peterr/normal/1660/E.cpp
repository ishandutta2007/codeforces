#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2000;
string board[MAXN];
int val[MAXN][MAXN];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int ans = n;
		for (int i = 0; i < n; i++)
		{
			cin >> board[i];
			for (char ch : board[i])
			{
				ans += (ch == '1');
			}
			fill(val[i], val[i] + n, 0);
		}
		int mx = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int r = (i + j) % n;
				int c = j;
				val[i][0] += (board[r][c] == '1');
			}
			for (int j = 0; j < n; j++)
			{
				if (i == 0)
					continue;
				int r = j % n;
				int c = (i + j) % n;
				val[0][i] += (board[r][c] == '1');
			}
			mx = max(mx, val[0][i]);
			mx = max(mx, val[i][0]);
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				val[i][j] = val[i - 1][j - 1] - (board[i - 1][j - 1] == '1') + (board[(i + n - 1) % n][(j + n - 1) % n] == '1');
			}
		}
		cout << ans - 2 * mx << "\n";
	}
	return 0;
}
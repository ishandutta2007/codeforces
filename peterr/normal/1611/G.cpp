#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E6;
string board[MAXN];

int solve(int n, int m, int offset)
{
	int ans = 0;
	multiset<int> ms;
	for (int i = offset; i >= -(m - 1); i -= 2)
	{
		int row = min(i + m - 1, n - 1);
		int col = row - i;
		while (row >= 0 && col >= 0)
		{
			if (board[row][col] == '1')
			{
				//cout << "at " << row << " " << col << endl;
				ans++;
				auto it = ms.lower_bound(row + col);
				if (it != ms.end())
				{
					//cout << "erasing" << endl;
					ms.erase(it);
					ans--;
				}
				ms.insert(row + col);
			}
			row--;
			col--;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> board[i];
		}
		int ans = solve(n, m, n - 1);
		ans += solve(n, m, n - 2);
		cout << ans << "\n";
	}
	return 0;
}
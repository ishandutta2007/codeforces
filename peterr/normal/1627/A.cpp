#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 50;
string board[MAXN];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, r, c;
		cin >> n >> m >> r >> c;
		r--;
		c--;
		bool black = false;
		for (int i = 0; i < n; i++)
		{
			cin >> board[i];
			for (char ch : board[i])
				if (ch == 'B')
					black = true;
		}
		if (board[r][c] == 'B')
			cout << "0\n";
		else if (!black)
			cout << "-1\n";
		else
		{
			bool found = false;
			for (int i = 0; i < n; i++)
			{
				if (board[i][c] == 'B')
					found = true;
			}
			for (int i = 0; i < m; i++)
			{
				if (board[r][i] == 'B')
					found = true;
			}
			if (found)
				cout << "1\n";
			else
				cout << "2\n";
		}
	}
	return 0;
}
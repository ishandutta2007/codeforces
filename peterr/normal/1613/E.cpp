#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E6;
string board[MAXN];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

void solve(int r, int c, int n, int m)
{
	//cout << "solve " << r << " " << c << "\n";
	for (int i = 0; i < 4; i++)
	{
		int newr = r + dr[i];
		int newc = c + dc[i];
		if (newr < 0 || newr >= n || newc < 0 || newc >= m)
			continue;
		if (board[newr][newc] == '+' || board[newr][newc] == 'L' || board[newr][newc] == '#')
			continue;
		//cout << "considering " << newr << " " << newc << "\n";
		int bad = 0;
		for (int j = 0; j < 4; j++)
		{
			int newr2 = newr + dr[j];
			int newc2 = newc + dc[j];
			if (newr2 < 0 || newr2 >= n || newc2 < 0 || newc2 >= m)
				continue;
			//cout << board[newr2][newc2] << "\n";
			if (board[newr2][newc2] == '.')
				bad++;
		}
		if (bad <= 1)
		{
			//cout << "accepted\n";
			board[newr][newc] = '+';
			solve(newr, newc, n, m);
		}
	}
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
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == 'L')
					solve(i, j, n, m);
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << board[i] << "\n";
		}
	}
	return 0;
}
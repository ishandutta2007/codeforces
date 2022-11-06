#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;
string board[MAXN];
pair<int, int> nxt[MAXN][MAXN];
pair<int, int> lift[MAXN][MAXN];
bool isCycle[MAXN][MAXN];
int moves[MAXN][MAXN];
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

int encode(char ch)
{
	if (ch == 'L')
		return 0;
	if (ch == 'U')
		return 1;
	if (ch == 'R')
		return 2;
	return 3;
}

int solve(int r, int c)
{
	if (r == -1)
		return 0;
	if (!moves[r][c])
		moves[r][c] = 1 + solve(nxt[r][c].first, nxt[r][c].second);
	return moves[r][c];
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
			fill(moves[i], moves[i] + m, 0);
			fill(isCycle[i], isCycle[i] + m, 0);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int key = encode(board[i][j]);
				int newr = i + dr[key];
				int newc = j + dc[key];
				if (newr < 0 || newr >= n || newc < 0 || newc >= m)
				{
					nxt[i][j] = {-1, -1};
				}
				else
				{
					nxt[i][j] = {newr, newc};
				}
				lift[i][j] = nxt[i][j];
			}
		}
		for (int i = 0; i < 30; i++)
		{
			for (int r = 0; r < n; r++)
			{
				for (int c = 0; c < m; c++)
				{
					if (lift[r][c].first == -1)
						continue;
					pair<int, int> pr = lift[r][c];
					lift[r][c] = lift[pr.first][pr.second];
				}
			}
		}
		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < m; c++)
			{
				pair<int, int> pr = lift[r][c];
				if (pr.first == -1)
					continue;
				isCycle[pr.first][pr.second] = true;
			}
		}

		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < m; c++)
			{
				if (!isCycle[r][c] || moves[r][c])
					continue;
				vector<pair<int, int>> vec;
				vec.push_back({r, c});
				while (1)
				{
					//cout << "loop" << endl;
					pair<int, int> pr = vec.back();
					//cout << pr.first << " " << pr.second << endl;
					pair<int, int> nxtpr = nxt[pr.first][pr.second];
					if (nxtpr == vec[0])
						break;
					vec.push_back(nxtpr);
				}
				for (pair<int, int> pr : vec)
					moves[pr.first][pr.second] = (int) vec.size();
			}
		}
		int ans = 0;
		int rr = 0;
		int cc = 0;
		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < m; c++)
			{
				solve(r, c);
				if (moves[r][c] > ans)
				{
					ans = moves[r][c];
					rr = r + 1;
					cc = c + 1;
				}
			}
		}
		cout << rr << " " << cc << " " << ans << "\n";
	}
	return 0;
}
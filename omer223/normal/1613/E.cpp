#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const long long infty = 1e18 + 15;
const int dxs[] = { 0, 0, 1, -1 };
const int dys[] = { 1, -1, 0, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		long long n, m;
		cin >> n >> m;
		bool** board = new bool*[n];
		pii lab;
		for (int i = 0; i < n; i++)
		{
			board[i] = new bool[m];
			for (int j = 0; j < m; j++)
			{
				board[i][j] = false;
				char c;
				cin >> c;
				if (c == '#') board[i][j] = true;
				if (c == 'L') lab = { i, j };
			}
		}
		int** unblocked = new int*[n];
		for (int i = 0; i < n; i++)
		{
			unblocked[i] = new int[m];
			for (int j = 0; j < m; j++)
			{
				unblocked[i][j] = 0;
				for (int d = 0; d < 4; d++)
				{
					int dx = dxs[d];
					int dy = dys[d];
					int nx = i + dx;
					int ny = j + dy;
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && !board[nx][ny])
					{
						unblocked[i][j]++;
					}
				}
			}
		}
		int li = lab.first;
		int lj = lab.second;
		bool** ans = new bool*[n];
		for (int i = 0; i < n; i++)
		{
			ans[i] = new bool[m];
			for (int j = 0; j < m; j++) ans[i][j] = false;
		}
		queue<pii> q;
		q.push(lab);
		ans[li][lj] = true;
		while (!q.empty())
		{
			pii curr = q.front();
			q.pop();
			int ux = curr.first;
			int uy = curr.second;			
			for (int d = 0; d < 4; d++)
			{
				int dx = dxs[d];
				int dy = dys[d];
				int nx = ux + dx;
				int ny = uy + dy;
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && !board[nx][ny] && !ans[nx][ny])
				{
					unblocked[nx][ny]--;
					if (unblocked[nx][ny] <= 1)
					{
						q.push({ nx, ny });
						ans[nx][ny] = true;
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (lab == pii(i, j)) cout << "L";
				else if (ans[i][j]) cout << "+";
				else if (!board[i][j]) cout << ".";
				else cout << "#";
			}
			cout << '\n';
		}
	}
	cin >> t;
}
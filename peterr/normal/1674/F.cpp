#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 1000;
string board[MAXN];
int n, m, q;

pair<int, int> decode(int x)
{
	return {x % n, x / n};
}

int encode(pair<int, int> pr)
{
	return pr.second * n + pr.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> q;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
		for (char ch : board[i])
			cnt += ch == '*';
	}
	int good = 0;
	for (int i = 0; i < cnt; i++)
	{
		pair<int, int> pr = decode(i);
		if (board[pr.first][pr.second] == '*')
			good++;
	}
	while (q--)
	{
		int r, c;
		cin >> r >> c;
		r--;
		c--;
		if (board[r][c] == '*')
		{
			if (encode({r, c}) < cnt)
				good--;
			board[r][c] = '.';
			cnt--;
			pair<int, int> pr = decode(cnt);
			if (board[pr.first][pr.second] == '*')
				good--;
		}
		else
		{
			pair<int, int> pr = decode(cnt);
			if (board[pr.first][pr.second] == '*')
				good++;
			board[r][c] = '*';
			cnt++;
			if (encode({r, c}) < cnt)
				good++;
		}
		cout << cnt - good << "\n";
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

pair<int, int> a[200][200];
int ans[200][200];

int main()
{
	#ifdef ONPC
		freopen("a.in", "r", stdin);
	#endif
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = {i, j};
		}
	}
	for (int i = 0; i < q; i++)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int x;
			cin >> x;
			x--;
			auto p = a[x][0];
			for (int j = 0; j < m - 1; j++)
			{
				a[x][j] = a[x][j + 1];
			}
			a[x][m - 1] = p;
		}
		if (t == 2)
		{
			int x;
			cin >> x;
			x--;
			auto p = a[0][x];
			for (int j = 0; j < n - 1; j++)
			{
				a[j][x] = a[j + 1][x];
			}
			a[n - 1][x] = p;
		}
		if (t == 3)
		{
			int x, y, z;
			cin >> x >> y >> z;
			x--, y--;
			ans[a[x][y].first][a[x][y].second] = z;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
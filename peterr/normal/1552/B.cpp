#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5E4;
int a[MAXN + 1][5];

bool better(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		cnt += a[x][i] < a[y][i];
	}
	return cnt >= 3;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cin >> a[i][j];
			}
		}
		int cur = 1;
		for (int j = 2; j <= n; j++)
		{
			if (better(j, cur))
				cur = j;
		}
		bool good = true;
		for (int i = 1; i <= n; i++)
		{
			if (i == cur)
				continue;
			if (better(i, cur))
				good = false;
		}
		//cout << "cur was " << cur << endl;
		if (!good)
			cur = -1;
		cout << cur << "\n";
	}
	return 0;
}
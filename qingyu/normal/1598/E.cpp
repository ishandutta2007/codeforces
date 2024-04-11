//2021.10.12
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int N = 1e3 + 50;

int n, m, q;
int f[N][N], a[N][N];
long long ans;

ll contrib(int i, int j)
{
	if (a[i][j]) return 0;
	if (i <= 0 || j <= 0 || i > n || j > m) return 0;
	int ans = 0, A = min(f[i][j], f[i][j + 1]), B = min(f[i][j], f[i][j + 1] + 1);	
	int C = min(f[i][j], f[i + 1][j]), D = min(f[i][j], f[i + 1][j] + 1);
	ans += min(f[i][j], f[i][j + 1]);
	ans += min(f[i][j], f[i][j + 1] + 1);
	ans += min(f[i][j], f[i + 1][j]);
	ans += min(f[i][j], f[i + 1][j] + 1);
	--ans;
	return ans;
}

long long takeout(int _x, int _y)
{
	int w = 0;
	while (_x > 0 && _y > 0)
	{
		w += contrib(_x, _y);
		w += contrib(_x - 1, _y);
		w += contrib(_x, _y - 1);
		--_x, --_y;
	}
	return w;
}

void update(int x, int y)
{
	int sx = x, sy = y;
	while (x < n && y < m) ++x, ++y;
	int step = 1;
	int _x = x, _y = y, xx = x, yy = y;
	ans -= takeout(x, y);	
	a[sx][sy] = !a[sx][sy];
	while (x > 0 && y > 0)
	{
		if (a[x][y])
		{
			step = 0;	
		}
		else
		{
		}
		f[x][y] = step;
		++step, --x, --y;
	}
	_x = xx, _y = yy;
	ans += takeout(xx, yy);

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			f[i][j] = min(n - i + 1, m - j + 1);
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			ans += contrib(i, j);	
		}
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		update(x, y);
		cout << ans << endl;
	}
}
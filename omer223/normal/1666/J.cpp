#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MXN = 205;
const long long inf = 1e18;

long long c[MXN][MXN];
long long dp[MXN][MXN];
long long argdp[MXN][MXN];
long long pref[MXN][MXN];
int p[MXN];

void prep(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			pref[i][j] = c[i][j];
			if (i > 0) pref[i][j] += pref[i - 1][j];
			if (j > 0) pref[i][j] += pref[i][j - 1];
			if (i > 0 && j > 0) pref[i][j] -= pref[i - 1][j - 1];
		}
	}
}

long long query(int x1, int y1, int x2, int y2)
{
	if (x1 > x2 || y1 > y2) return 0;
	long long ans = pref[x2][y2];
	if (x1 > 0) ans -= pref[x1 - 1][y2];
	if (y1 > 0) ans -= pref[x2][y1 - 1];
	if (x1 > 0 && y1 > 0) ans += pref[x1 - 1][y1 - 1];
	return ans;
}

void getp(int l, int r, int prevp)
{
	if (l > r) return;
	int k = argdp[l][r];
	p[k] = prevp;
	getp(l, k - 1, k);
	getp(k + 1, r, k);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> c[i][j];
		}
	}
	prep(n);
	for (int d = 0; d <= n; d++)
	{
		for (int i = 0; i < n; i++)
		{
			int j = i + d;
			if (j >= n) continue;
			dp[i][j] = inf;
			for (int k = i; k <= j; k++)
			{
				long long v = 0;
				if (i <= k - 1)
				{
					v += dp[i][k - 1];
				}
				if (k + 1 <= j)
				{
					v += dp[k + 1][j];
				}
				v += query(0, k + 1, n - 1, j) - query(k + 1, k + 1, j, j);
				v += query(0, i, n - 1, k - 1) - query(i, i, k - 1, k - 1);
				if (v < dp[i][j])
				{
					dp[i][j] = v;
					argdp[i][j] = k;
				}
			}
		}
	}
	getp(0, n - 1, -1);
	for (int i = 0; i < n; i++)
	{
		cout << p[i] + 1 << " ";
	}
	cout << "\n";
	//cout << "---------------\n" << dp[0][n - 1] << "\n-------------------\n";
	cin >> n;
}
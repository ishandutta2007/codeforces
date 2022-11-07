#include <bits/stdc++.h>

using namespace std;

const int INF = 1E9;
const int MAXN = 1E5;
int a[2][MAXN];
int suf[MAXN];
int pref[MAXN];

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
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
			}
		}
		pref[0] = a[1][0];
		for (int i = 1; i < n; i++)
		{
			pref[i] = pref[i - 1] + a[1][i];
		}
		suf[n - 1] = a[0][n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			suf[i] = suf[i + 1] + a[0][i];
		}
		int ans = INF;
		for (int i = 0; i < n; i++)
		{
			int x = i - 1 >= 0 ? pref[i - 1] : 0;
			int y = i + 1 < n ? suf[i + 1] : 0;
			ans = min(ans, max(x, y));
		}
		cout << ans << "\n";
	}
}
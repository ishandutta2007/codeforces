#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int pref[6][MAXN + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	string s;
	cin >> n >> m >> s;
	s = "#" + s;
	for (int i = 1; i <= n; i++)
	{
		int key = s[i] - 'a';
		for (int j = 0; j < 6; j++)
		{
			if (j < 3)
				pref[j][i] = pref[j][i - 1] + (key != (i + j) % 3);
			else
				pref[j][i] = pref[j][i - 1] + (key != (((-i + j) % 3) + 3) % 3);
		}
	}
	while (m--)
	{
		int l, r;
		cin >> l >> r;
		int ans = MAXN;
		for (int i = 0; i < 6; i++)
		{
			ans = min(ans, pref[i][r] - pref[i][l - 1]);
		}
		cout << ans << "\n";
	}
	return 0;
}
//2021.10.12
#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 50;
int a[N][5], b[5];

inline void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < 5; ++i) b[i] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 5; ++j)
		{
			cin >> a[i][j];
			b[j] &= a[i][j];
		}
	for (int x = 0; x < 5; ++x)
		for (int y = x + 1; y < 5; ++y)
		{
			bool ok = true;
			int f1 = 0, f2 = 0, f3 = 0;
			for (int i = 1; i <= n; ++i)
			{
				if (!a[i][x] && !a[i][y])
				{
					ok = false;
					break;
				}
				else if (a[i][x] && a[i][y])
				{
					++f3;
				}
				else if (a[i][x]) ++f1;
				else if (a[i][y]) ++f2;
			}
			if (!ok)
			{
				continue;
			}
			if (f1 + f3 >= (n / 2) && f2 + f3 >= (n / 2))
			{
				puts("YES");
				return;
			}
		}
	puts("NO");

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}
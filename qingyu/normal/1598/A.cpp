//2021.10.12
#include <bits/stdc++.h>

using namespace std;

inline void solve()
{
	int n;
	string a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i)
		if (a[i] == '1' && b[i] == '1')
		{
			puts("NO");
			return;
		}
	puts("YES");
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
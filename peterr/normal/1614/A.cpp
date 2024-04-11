#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int a[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, l, r, k;
		cin >> n >> l >> r >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > k || a[i] > r || a[i] < l)
				continue;
			k -= a[i];
			ans++;
		}
		cout << ans << "\n";
	}
}
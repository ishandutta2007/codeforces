#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN];

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
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		long long ans = 0;
		for (int i = 0; i < n - 1; i++)
		{
			ans = max(ans, (long long) a[i] * a[i + 1]);
		}
		cout << ans << "\n";
	}
	return 0;
}
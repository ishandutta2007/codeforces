#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
int a[MAXN];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int mx = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			mx = max(mx, a[i]);
		}
		int ans = 0;
		int cur = -1;
		for (int i = n - 1; i >= 0; i--)
		{
			if (a[i] == mx)
				break;
			if (a[i] > cur)
				ans++;
			cur = max(cur, a[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}
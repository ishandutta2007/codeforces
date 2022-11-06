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
		sort(a, a + n);
		int ptr = 0;
		int best = 0;
		while (ptr < n)
		{
			int cnt = 0;
			int cur = a[ptr];
			while (ptr < n && a[ptr] == cur)
			{
				cnt++;
				ptr++;
			}
			best = max(best, cnt);
		}
		int ans = n - best;
		while (best < n)
		{
			best *= 2;
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
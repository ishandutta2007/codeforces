#include <bits/stdc++.h>

using namespace std;

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
		string a, b;
		cin >> a >> b;
		int ans = 0;
		vector<bool> used(n);
		for (int i = 0; i < n; i++)
		{
			ans += 2 * (a[i] != b[i]);
			if (a[i] == '0' && b[i] == '0')
			{
				ans++;
				if (i && a[i - 1] == '1' && b[i - 1] == '1' && !used[i - 1])
				{
					used[i - 1] = true;
					ans++;
				}
				else if (i + 1 < n && a[i + 1] == '1' && b[i + 1] == '1' && !used[i + 1])
				{
					used[i + 1] = true;
					ans++;
				}
			}
			
		}
		cout << ans << "\n";
	}
	return 0;
}
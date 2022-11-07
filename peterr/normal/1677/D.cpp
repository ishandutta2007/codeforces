#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 1E6;
const int MOD = 998244353;
int a[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		bool valid = true;
		for (int i = 0; i < k; i++)
		{
			if (a[n - i - 1] > 0)
				valid = false;
		}
		if (!valid)
		{
			cout << "0\n";
			continue;
		}	
		int ans = 1;
		for (int i = 0; i < k; i++)
		{
			ans = (int) ((long long) ans * (i + 1) % MOD);
		}
		for (int i = 0; i < n - k; i++)
		{
			if (a[i] > 0)
				continue;
			if (a[i] == 0)
				ans = (int) ((long long) ans * (k + 1) % MOD);
			if (a[i] == -1)
				ans = (int) ((long long) ans * (k + i + 1) % MOD);
			//cout << "iter " << i << " " << ans << endl;
		}
		cout << ans << "\n";
	}
	return 0;
}
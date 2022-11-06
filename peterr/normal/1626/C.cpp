#include <bits/stdc++.h>
 
using namespace std;

const long long INF = 1E18;
const int MAXN = 100;
int k[MAXN + 1];
int h[MAXN + 1];
long long dp[MAXN + 1];

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
		for (int i = 1; i <= n; i++)
		{
			cin >> k[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> h[i];
		}
		for (int i = 1; i <= n; i++)
		{
			int amt = h[i];
			int j = i - 1;
			while (j >= 1)
			{
				if (k[i] - k[j] >= amt)
					break;
				amt = max(amt, h[j] + (k[i] - k[j]));
				j--;
			}
			dp[i] = (long long) amt * (amt + 1) / 2 + dp[j];
		}	
		cout << dp[n] << "\n";
	}
	return 0;
}
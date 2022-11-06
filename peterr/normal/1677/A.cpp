#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 5000;
int a[MAXN];
int suf[MAXN][MAXN + 1];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			suf[i][n] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 1; j >= i; j--)
			{
				suf[i][j] = suf[i][j + 1] + (a[j] < a[i]);
				//cout << "suf " << i << " " << j << " " << suf[i][j] << endl;
			}
		}
		long long ans = 0;
		for (int j = 0; j < n; j++)
		{
			long long sum = 0;
			for (int i = j - 1; i >= 0; i--)
			{
				if (a[j] > a[i])
					ans += sum;
				//cout << i << " " << j << " adding " << sum << endl;
				sum += suf[i][j + 1];
				//cout << "\tnew sum " << sum << endl;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
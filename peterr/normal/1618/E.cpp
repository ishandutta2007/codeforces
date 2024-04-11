#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 4E4;
int b[MAXN];
int ans[MAXN];

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
		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
			sum += b[i];
		}
		long long cnt = (long long) n * (n + 1) / 2;
		if (sum % cnt)
		{
			cout << "NO\n";
			continue;
		}
		sum /= (long long) n * (n + 1) / 2;
		for (int i = 0; i < n; i++)
		{
			int j = i - 1;
			if (j == -1)
				j = n - 1;
			ans[i] = b[i] - b[j] - sum;
			if (ans[i] >= 0 || -ans[i] % n)
			{
				cout << "NO\n";
				goto exit;
			}
			ans[i] = -ans[i] / n;
		}
		cout << "YES\n";
		for (int i = 0; i < n; i++)
		{
			cout << ans[i] << " \n"[i == n - 1];
		}
		exit:;
	}
	return 0;
}
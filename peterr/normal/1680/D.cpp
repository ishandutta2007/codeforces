#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3000;
int a[MAXN];

long long solve(int n, int k, int totalZeros, long long target)
{
	long long ans = 0;
	for (int i = 0; i <= n; i++)
	{
		long long pref = 0;
		int zeros = 0;
		for (int j = 0; j < i; j++)
		{
			zeros += a[j] == 0;
			pref += a[j];
		}
		//cout << "pref " << i << " " << pref << " " << zeros << endl;
		long long suf = 0;
		for (int j = 0; j + i <= n; j++)
		{
			if (j)
			{
				zeros += a[n - j] == 0;
				suf += a[n - j];
			}
			long long mid = (long long) (totalZeros - zeros) * k;
			long long ends = min((long long) zeros * k, mid - target);
			//cout << "suf " << j << " " << suf << " " << zeros << " " << mid << " " << ends << endl;
			//cout << "ans " << -pref - suf + ends + 1 << endl;
			ans = max(ans, -pref - suf + ends + 1);
		}
	}
	//cout << "returning " << ans << endl;
	return ans;
}

int main()
{
	int n, k;
	cin >> n >> k;
	long long sum = 0;
	int zeros = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		zeros += a[i] == 0;
		sum += a[i];
	}
	if (abs(sum) > (long long) zeros * k)
	{
		cout << "-1\n";
		return 0;
	}
	long long ans = solve(n, k, zeros, -sum);
	for (int i = 0; i < n; i++)
		a[i] = -a[i];
	ans = max(ans, solve(n, k, zeros, sum));
	cout << ans << "\n";
	return 0;
}
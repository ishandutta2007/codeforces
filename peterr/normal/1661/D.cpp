#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 3E5;
long long a[MAXN];
long long freq[MAXN];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	long long ans = 0;
	long long sum = 0;
	long long extra = 0;
	long long window = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		//cout << "iter " << i << endl;
		if (i >= k - 1)
		{
			long long ops = max(0LL, (a[i] - sum + k - 1) / k);
			ans += ops;
			freq[i - k + 1] = ops;
			//cout << "ops " << ops << endl;
		}
		else
		{
			extra = max(extra, (a[i] - sum + i) / (i + 1));
			//cout << "extra " << extra << endl;
		}
		
		sum -= window;
		window -= freq[i];
		if (i - k + 1 >= 0)
		{
			window += freq[i - k + 1];
			sum += (k - 1) * freq[i - k + 1];
		}
		//cout << "sum " << sum << endl;
		//cout << "window " << window << endl;
	}
	ans += extra;
	cout << ans << "\n";
	return 0;
}
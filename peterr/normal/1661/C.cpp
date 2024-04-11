#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 3E5;
int a[MAXN];

long long solve(int n, int target)
{
	long long lo = 0;
	long long hi = 1E18;
	while (lo < hi)
	{
		long long mid = (lo + hi) / 2;
		long long ones = (mid + 1) / 2;
		long long twos = mid / 2;
		bool valid = true;
		for (int i = 0; i < n; i++)
		{
			long long amt = min(twos, (target - a[i]) / 2LL);
			twos -= amt;
			long long left = target - (a[i] + 2 * amt);
			if (left > ones)
				valid = false;
			ones -= left;
		}
		if (valid)
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}

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
		long long ans = 1E18;
		for (int i = 0; i <= 10; i++)
		{
			ans = min(ans, solve(n, *max_element(a, a + n) + i));
		}
		cout << ans << "\n";
	}
	return 0;
}
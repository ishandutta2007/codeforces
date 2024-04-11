#include <bits/stdc++.h>

using namespace std;

const long long INF = 2E9;
long long ten[10];
long long eleven[10];

long long solve(long long n, long long k)
{
	set<long long> nums;
	long long nn = n;
	while (nn)
	{
		long long dig = nn % 10;
		nums.insert(dig);
		nn /= 10;
	}
	if ((long long) nums.size() <= k)
		return n;
	string s = to_string(n);
	long long ans = INF;
	nums.clear();
	long long cur = 0;
	for (long long i = 0; i < (long long) s.length(); i++)
	{
		long long digits = (long long) s.length() - i;
		long long dig = s[i] - '0';
		auto top = nums.upper_bound(dig);
		if (top != nums.end())
		{
			long long below = *nums.begin();
			ans = min(ans, cur + ten[digits - 1] * *top + (digits - 2 >= 0 ? eleven[digits - 2] * below : 0));
			if ((long long) nums.size() < k)
				ans = min(ans, cur + ten[digits - 1] * *top);
		}
		if ((long long) nums.size() < k && dig < 9)
		{
			long long below = 0;
			if ((long long) nums.size() == k - 1)
			{
				if (nums.size())
					below = min(*nums.begin(), dig + 1);
				else
					below = dig + 1;
			}
			ans = min(ans, cur + ten[digits - 1] * (dig + 1) + (digits - 2 >= 0 ? eleven[digits - 2] * below : 0));
		}
		nums.insert(dig);
		if ((long long) nums.size() > k)
			break;
		cur += dig * ten[digits - 1];
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ten[0] = eleven[0] = 1;
	for (long long i = 1; i < 10; i++)
	{
		ten[i] = 10 * ten[i - 1];
		eleven[i] = 10 * eleven[i - 1] + 1;
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		cout << solve(n, k) << "\n";
	}
	return 0;
}
#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
int a[MAXN];
vector<int> freq;

int solve(int x, int y, int n)
{
	int ptr = 0;
	int sum1 = 0;
	while (ptr < (int) freq.size() && freq[ptr] + sum1 <= x)
	{
		sum1 += freq[ptr];
		ptr++;
	}
	if (x != 1 && sum1 <= x / 2)
		return 1E9;
	int sum2 = 0;
	int ptr2 = (int) freq.size() - 1;
	while (ptr2 >= ptr && freq[ptr2] + sum2 <= y)
	{
		sum2 += freq[ptr2];
		ptr2--;
	}
	if (y != 1 && sum2 <= y / 2)
		return 1E9;
	int rem = n - sum1 - sum2;
	int twopow = 1;
	while (twopow < rem)
		twopow += twopow;
	return x - sum1 + y - sum2 + twopow - rem;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		freq.clear();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		int ptr = 0;
		while (ptr < n)
		{
			int cur = a[ptr];
			freq.push_back(0);
			while (ptr < n && a[ptr] == cur)
			{
				freq.back()++;
				ptr++;
			}
		}
		int ans = 1E9;
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				ans = min(ans, solve(1 << i, 1 << j, n));
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
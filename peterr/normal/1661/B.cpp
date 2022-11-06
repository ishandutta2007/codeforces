#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 32768;
int a[MAXN];

int solve(int x)
{
	if (!x)
		return 0;
	int ans = 15;
	for (int i = 1; i <= 15; i++)
	{
		int temp = 0;
		if (x & ((1 << i) - 1))
		{
			int mask = x & ((1 << i) - 1);
			temp += (1 << i) - mask;
		}
		temp += 15 - i;
		ans = min(ans, temp);
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << solve(a[i]) << " \n"[i == n - 1];
	}
	return 0;
}
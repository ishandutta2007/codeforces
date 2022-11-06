#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int a[MAXN];

bool check(int n, long long x, long long h)
{
	for (int i = 0; i < n; i++)
	{
		h -= x;
		if (i)
			h += max(0LL, a[i - 1] + x - a[i]);
		if (h <= 0)
			return true;
	}
	return false;
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
		long long h;
		cin >> n >> h;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		long long lo = 1;
		long long hi = h;
		while (lo < hi)
		{
			long long mid = (lo + hi) / 2;
			if (check(n, mid, h))
				hi = mid;
			else
				lo = mid + 1;
		}
		cout << lo << "\n";
	}
	return 0;
}
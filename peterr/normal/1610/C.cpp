#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];
int b[MAXN];

bool check(int n, int k)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (cnt > a[i])
			continue;
		if (cnt + 1 + b[i] < k)
			continue;
		cnt++;
	}
	return cnt >= k;
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
			cin >> b[i] >> a[i];
		}
		int lo = 0;
		int hi = n;
		while (lo < hi)
		{
			int mid = (lo + hi + 1) / 2;
			if (check(n, mid))
				lo = mid;
			else
				hi = mid - 1;
		}
		cout << lo << "\n";
	}
	return 0;
}
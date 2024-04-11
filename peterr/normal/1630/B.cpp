#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
int a[MAXN];
int freq[MAXN + 1];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		fill(freq + 1, freq + n + 1, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			freq[a[i]]++;
		}
		int num = 0;
		while (num - (n - num) < k)
			num++;
		int right = 0;
		int cnt = 0;
		int x = -1;
		int y = n + 1;
		for (int i = 1; i <= n; i++)
		{
			while (right < n && cnt < num)
			{
				right++;
				cnt += freq[right];
			}
			if (cnt >= num)
			{
				if (right - i < y - x)
				{
					x = i;
					y = right;
				}
			}
			cnt -= freq[i];
		}
		vector<pair<int, int>> ans;
		cnt = 0;
		int begin = 1;
		for (int i = 0; i < n; i++)
		{
			if (a[i] >= x && a[i] <= y)
			{
				cnt++;
			}
			else
				cnt--;
			if (cnt > 0)
			{
				ans.push_back({begin, i + 1});
				begin = i + 2;
				cnt = 0;
			}
		}
		if (begin <= n)
			ans.push_back({begin, n});
		cout << x << " " << y << "\n";
		for (int i = 0; i < k; i++)
		{
			if (i < k - 1)
				cout << ans[i].first << " " << ans[i].second << "\n";
			else
				cout << ans[i].first << " " << n << "\n";
		}
	}
	return 0;
}
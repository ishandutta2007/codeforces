#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
int a[MAXN];
long long cost[MAXN + 1];
int freq[MAXN + 1];

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
		fill(freq, freq + n + 1, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			freq[a[i]]++;
		}
		sort(a, a + n);
		int ptr = 0;
		vector<int> extras;
		fill(cost + 1, cost + n + 1, -1);
		for (int i = 1; i <= n; i++)
		{
			int cnt = 0;
			while (ptr < n && a[ptr] == i - 1)
			{
				cnt++;
				ptr++;
			}
			if (cnt)
			{
				cost[i] = cost[i - 1];
				for (int j = 0; j < cnt - 1; j++)
					extras.push_back(i - 1);
			}
			else
			{
				if (extras.size())
				{
					cost[i] = cost[i - 1] + (i - extras.back() - 1);
					extras.pop_back();
				}
				else
					break;
			}
		}
		for (int i = 0; i <= n; i++)
		{
			long long res = cost[i] == -1 ? -1 : cost[i] + freq[i];
			cout << res << " \n"[i == n];
		}
	}
	return 0;
}
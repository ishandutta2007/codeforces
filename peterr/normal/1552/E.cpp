#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int freq[MAXN * MAXN];
int lastOcc[MAXN];
int a[MAXN * MAXN];
pair<int, int> ans[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	fill(lastOcc, lastOcc + n, -1);
	for (int i = 0; i < n * k; i++)
	{
		cin >> a[i];
		a[i]--;
	}
	int mx = (n + k - 2) / (k - 1);
	for (int i = 0; i < n * k; i++)
	{
		int x = a[i];
		if (lastOcc[x] == -1 || ans[x].second)
		{
			lastOcc[x] = i;
			continue;
		}
		bool good = true;
		for (int j = lastOcc[x]; j <= i; j++)
		{
			if (freq[j] == mx)
			{
				good = false;
				break;
			}
		}
		if (good)
		{
			ans[x] = {lastOcc[x] + 1, i + 1};
			for (int j = lastOcc[x]; j <= i; j++)
				freq[j]++;
		}
		lastOcc[x] = i;
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
	return 0;
}
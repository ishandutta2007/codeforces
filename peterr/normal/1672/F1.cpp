#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
int a[MAXN];
vector<int> adjList[MAXN + 1];
pair<int, int> freq[MAXN + 1];

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
		for (int i = 1; i <= n; i++)
		{
			adjList[i].clear();
			freq[i] = {0, i};
		}
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			freq[a[i]].first++;
		}
		sort(freq + 1, freq + n + 1);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; i < n && j < freq[i].first; j++)
			{
				adjList[freq[i].second].push_back(freq[i + 1].second);
			}
			for (int j = 0; j < freq[i].first - freq[i - 1].first; j++)
			{
				adjList[freq[n].second].push_back(freq[i].second);
			}
		}
		for (int i = 0; i < n; i++)
		{
			int x = a[i];
			cout << adjList[x].back() << " \n"[i == n - 1];
			adjList[x].pop_back();
		}
	}
	return 0;
}
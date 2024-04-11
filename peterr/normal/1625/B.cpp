#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 150000;
vector<int> where[MAXN + 1];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= MAXN; i++)
			where[i].clear();
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			where[x].push_back(i);
		}
		int ans = -1;
		for (int i = 1; i <= MAXN; i++)
		{
			for (int j = 0; j < (int) where[i].size() - 1; j++)
			{
				ans = max(ans, 1 + where[i][j] + (n - where[i][j + 1] - 1));
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
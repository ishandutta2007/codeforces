#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
bool visited[2 * MAXN + 1];
pair<int, int> a[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		fill(visited + 1, visited + 2 * n + 1, false);
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			a[i] = {x, y};
			visited[x] = visited[y] = true;
		}
		vector<int> vec;
		for (int i = 1; i <= 2 * n; i++)
		{
			if (!visited[i])
				vec.push_back(i);
		}
		for (int i = 0; i < (int) vec.size() / 2; i++)
		{
			a[k + i] = {vec[i], vec[i + (int) vec.size() / 2]};
			//cout << "made " << vec[i] << " " << vec[i + (int) vec.size() / 2] << endl;
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				int x1 = a[i].first;
				int y1 = a[i].second;
				int x2 = a[j].first;
				int y2 = a[j].second;
				if (x1 > y1)
					swap(x1, y1);
				if (x2 > y2)
					swap(x2, y2);
				if (x1 > x2)
				{
					swap(x1, x2);
					swap(y1, y2);
				}
				int cnt = 0;
				cnt += x2 > x1 && x2 < y1;
				cnt += y2 > x1 && y2 < y1;
				ans += (cnt == 1);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
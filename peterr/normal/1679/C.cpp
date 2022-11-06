#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int rowcnt[MAXN + 1];
int colcnt[MAXN + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	set<int> rows;
	set<int> cols;
	for (int i = 1; i <= n; i++)
	{
		rows.insert(i);
		cols.insert(i);
	}
	while (q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int x, y;
			cin >> x >> y;
			rowcnt[x]++;
			colcnt[y]++;
			rows.erase(x);
			cols.erase(y);
		}
		else if (t == 2)
		{
			int x, y;
			cin >> x >> y;
			rowcnt[x]--;
			colcnt[y]--;
			if (!rowcnt[x])
				rows.insert(x);
			if (!colcnt[y])
				cols.insert(y);
		}
		else
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			bool ans = false;
			auto it = rows.lower_bound(x1);
			if (it == rows.end() || *it > x2)
				ans = true;
			it = cols.lower_bound(y1);
			if (it == cols.end() || *it > y2)
				ans = true;
			cout << (ans ? "Yes" : "No") << "\n";
		}
	}
	return 0;
}
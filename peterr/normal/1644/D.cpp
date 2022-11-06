#include <bits/stdc++.h>
 
using namespace std;

const int MOD = 998244353;
const int MAXN = 2E5;
int last_row[MAXN + 1];
int last_col[MAXN + 1];
bool row_visited[MAXN + 1];
bool col_visited[MAXN + 1];
pair<int, int> a[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fill(last_row + 1, last_row + MAXN + 1, -1);
	fill(last_col + 1, last_col + MAXN + 1, -1);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k, q;
		cin >> n >> m >> k >> q;
		for (int i = 0; i < q; i++)
		{
			int x, y;
			cin >> x >> y;
			a[i] = {x, y};
			last_row[x] = last_col[y] = i;
		}
		int last_all = -1;
		int row_cnt = 0;
		int col_cnt = 0;
		for (int i = q - 1; i >= 0; i--)
		{
			int r = a[i].first;
			int c = a[i].second;
			if (!row_visited[r])
				row_cnt++;
			if (!col_visited[c])
				col_cnt++;
			row_visited[r] = col_visited[c] = true;
			if (row_cnt == n || col_cnt == m)
			{
				last_all = i;
				break;
			}
		}
		int cnt = 0;
		for (int i = 0; i < q; i++)
		{
			int r = a[i].first;
			int c = a[i].second;
			if (last_row[r] > i && last_col[c] > i)
				continue;
			else if (last_all > i)
				continue;
			cnt++;
			//cout << "iter " << i << endl;
			//cout << "cnt " << cnt << endl;
		}
		int ans = 1;
		for (int i = 0; i < cnt; i++)
		{
			ans = (int) ((long long) ans * k % MOD);
		}
		cout << ans << "\n";
		for (int i = 0; i < q; i++)
		{
			row_visited[a[i].first] = false;
			col_visited[a[i].second] = false;
			last_row[a[i].first] = -1;
			last_col[a[i].second] = -1;
		}
	}
	return 0;
}
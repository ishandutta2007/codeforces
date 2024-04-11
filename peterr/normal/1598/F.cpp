#include <bits/stdc++.h>

using namespace std;

const int INF = 1E9;
const int MAXN = 20;
unordered_map<int, vector<int>> a[MAXN];
pair<int, int> val[MAXN];
int dp1[1 << MAXN];
int dp2[1 << MAXN];
int pre[1 << MAXN];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int bal = 0;
		for (int j = 0; j < (int) s.length(); j++)
		{
			if (s[j] == '(')
				bal++;
			else
				bal--;
			a[i][bal].push_back(j);
			val[i].second = min(val[i].second, bal);
		}
		val[i].first = bal;
	}
	for (int mask = 1; mask < (1 << n); mask++)
	{
		int j = __builtin_ctz(mask & -mask);
		int sub = mask ^ (1 << j);
		pre[mask] = pre[sub] + val[j].first;
		//cout << "pre " << bitset<8>(mask).to_string() << " " << pre[mask] << endl;
	}
	for (int mask = 1; mask < (1 << n); mask++)
	{
		dp1[mask] = dp2[mask] = -INF;
		for (int i = 0; i < n; i++)
		{
			if (!(mask & (1 << i)))
				continue;
			int sub = mask ^ (1 << i);
			if (dp1[sub] != -INF && pre[sub] + val[i].second >= 0)
				dp1[mask] = max(dp1[mask], dp1[sub] + (int) a[i][-pre[sub]].size());
			if (dp1[sub] != -INF && pre[sub] + val[i].second < 0)
			{
				int cutoff_val = -pre[sub] - 1;
				int ind = a[i][cutoff_val][0];
				//auto it = lower_bound(a[i][-pre[sub]].begin(), a[i][-pre[sub]].end(), ind);
				//int num = distance(a[i][-pre[sub]].begin(), it);
				vector<int>& vec = a[i][-pre[sub]];
				int lo = -1;
				int hi = (int) vec.size() - 1;
				while (lo < hi)
				{
					int mid = (lo + hi + 1) / 2;
					if (vec[mid] >= ind)
						hi = mid - 1;
					else
						lo = mid;
				}
				int num = lo + 1;
				dp2[mask] = max(dp2[mask], dp1[sub] + num);
			}
		}
		//cout << "dp " << bitset<4>(mask).to_string() << " " << dp1[mask] << " " << dp2[mask] << endl;
	}
	int ans = 0;
	for (int i = 1; i < (1 << n); i++)
	{
		ans = max(ans, dp1[i]);
		ans = max(ans, dp2[i]);
	}
	cout << ans << "\n";
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
long long a[MAXN + 1];
long long b[MAXN + 1];
pair<int, int> seg[MAXN];
int cnt[MAXN];
map<int, vector<int>> mp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		mp.clear();
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> b[i];
			a[i] -= b[i];
		}
		for (int i = 1; i <= n; i++)
		{
			if (a[i])
				mp[i] = vector<int>();
		}
		for (int i = 1; i <= n; i++)
			a[i] += a[i - 1];
		vector<int> vec;
		for (int i = 0; i < m; i++)
		{
			int l, r;
			cin >> l >> r;
			seg[i] = {l, r};
			cnt[i] = 0;
			if (a[r])
				mp[r].push_back(i);
			else
				cnt[i]++;
			if (a[l - 1])
				mp[l - 1].push_back(i);
			else
				cnt[i]++;
			if (cnt[i] == 2)
				vec.push_back(i);
		}
		while (vec.size())
		{
			int ind = vec.back();
			vec.pop_back();
			while (1)
			{
				auto it = mp.lower_bound(seg[ind].first);
				if (it == mp.end() || it->first > seg[ind].second)
					break;
				for (int x : it->second)
				{
					cnt[x]++;
					if (cnt[x] == 2)
						vec.push_back(x);
				}
				mp.erase(it);
			}
		}
		cout << (mp.size() ? "NO" : "YES") << "\n";
	}
	return 0;
}
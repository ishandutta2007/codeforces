#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];
int b[MAXN];
int m[MAXN];
int ans[MAXN];

int solve(vector<int> ind)
{
	vector<tuple<int, int, int>> events;
	for (int i : ind)
	{
		int lo = max(0, a[i] - m[i]);
		int hi = a[i] - max(0, m[i] - b[i]);
		events.push_back({hi, lo, i});
	}
	sort(events.begin(), events.end());
	int cnt = 0;
	int last_time = -1;
	for (tuple<int, int, int> tup : events)
	{
		if (get<1>(tup) > last_time)
		{
			cnt++;
			last_time = get<0>(tup);
		} 
		ans[get<2>(tup)] = last_time;
	}
	return cnt;
}

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
		map<int, vector<int>> mp;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i] >> b[i] >> m[i];
			mp[a[i] + b[i] - m[i]].push_back(i);
		}
		int cnt = 0;
		for (auto it : mp)
		{
			cnt += solve(it.second);
		}
		cout << cnt << "\n";
		for (int i = 0; i < n; i++)
		{
			int eat = a[i] - ans[i];
			cout << eat << " " << m[i] - eat << "\n";
		}
	}
	return 0;
}
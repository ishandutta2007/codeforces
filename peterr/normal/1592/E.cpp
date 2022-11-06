#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E6;
int a[MAXN + 1];
unordered_map<int, vector<int>> mp[2];

int solve(int n)
{
	mp[0].clear();
	mp[1].clear();
	mp[0][0].push_back(0);
	int ans = 0;
	int cur = 0;
	int ptr = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!(a[i] & 1))
			ptr = i;
		cur = cur ^ a[i];
		vector<int>& vec = mp[i & 1][cur];
		auto it = ptr == i ? vec.end() : lower_bound(vec.begin(), vec.end(), ptr);
		if (it != vec.end())
		{
			ans = max(ans, i - *it);
		}
		vec.push_back(i);
		//mp[i & 1][cur].push_back(i);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < 21; i++)
	{
		ans = max(ans, solve(n));
		for (int j = 1; j <= n; j++)
			a[j] >>= 1;
	}
	cout << ans << "\n";
	return 0;
}
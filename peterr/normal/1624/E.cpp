#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 1E3;
string a[MAXN];
tuple<int, int, int> dp[MAXN + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		string s;
		cin >> s;
		map<string, tuple<int, int, int>> mp;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < (int) a[i].length() - 1; j++)
			{
				mp[a[i].substr(j, 2)] = {j + 1, j + 2, i + 1};
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < (int) a[i].length() - 2; j++)
			{
				mp[a[i].substr(j, 3)] = {j + 1, j + 3, i + 1};
			}
		}
		dp[1] = {-1, -1, -1};
		for (int i = 2; i <= m; i++)
		{
			dp[i] = {-1, -1, -1};
			string two = s.substr(i - 2, 2);
			if (mp.count(two) && get<0>(dp[i - 2]) != -1)
			{
				dp[i] = mp[two];
			}
			if (i >= 3)
			{
				string three = s.substr(i - 3, 3);
				if (mp.count(three) && get<0>(dp[i - 3]) != -1)
				{
					dp[i] = mp[three];
				}
			}
		}
		if (get<0>(dp[m]) == -1)
			cout << "-1\n";
		else
		{
			vector<tuple<int, int, int>> vec;
			int ptr = m;
			while (ptr)
			{
				vec.push_back(dp[ptr]);
				if (get<1>(dp[ptr]) - get<0>(dp[ptr]) == 1)
					ptr -= 2;
				else
					ptr -= 3;
			}
			cout << vec.size() << "\n";
			for (int i = (int) vec.size() - 1; i >= 0; i--)
			{
				cout << get<0>(vec[i]) << " " << get<1>(vec[i]) << " " << get<2>(vec[i]) << "\n";
			}
		}
	}
	return 0;
}
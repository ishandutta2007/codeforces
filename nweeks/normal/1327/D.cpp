#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

ll solve(void)
{
	int n;
	cin >> n;
	vector<int> p(n), c(n);
	for (auto &v : p)
	{
		cin >> v;
		v--;
	}
	for (int i(0); i < n; ++i)
		cin >> c[i];

	vector<bool> visited(n, false);

	vector<vector<int>> cycles;

	for (int i(0); i < n; ++i)
	{
		if (visited[i]) continue;

		vector<int> v;
		v.push_back(i);
		int j  = p[i];
		visited[i] = true;
		while (i != j)
		{
			v.push_back(j);
			visited[j] = true;
			j = p[j];
		}
		cycles.push_back(v);
	}
	int ans(n);

	for (int i(0); i < SZ(cycles); ++i)
	{
		for (int d(1); d*d  <= SZ(cycles[i]); ++d)
		{
			if (SZ(cycles[i])%d) continue;
			for (int j(0); j < SZ(cycles[i]); ++j)
				visited[j]=false;
			
			for (int s(0); s < SZ(cycles[i]); ++s)
			{
				if (visited[s]) continue;
				int j = (s+d)%SZ(cycles[i]);
				visited[s] = true;
				bool found(true);
				while (j != s)
				{
					visited[j] = true;
					if (c[cycles[i][s]] != c[cycles[i][j]]) found = false;
					j = (j + d)%SZ(cycles[i]);
				}
				if (found)
				{
					ans = min(ans, d);
					break;
				}
			}

			int dd = SZ(cycles[i])/d;
			for (int j(0); j < SZ(cycles[i]); ++j)
				visited[j]=false;
			
			for (int s(0); s < SZ(cycles[i]); ++s)
			{
				if (visited[s]) continue;
				int j = (s+dd)%SZ(cycles[i]);
				visited[s] = true;
				bool found(true);
				while (j != s)
				{
					visited[j] = true;
					if (c[cycles[i][s]] != c[cycles[i][j]]) found = false;
					j = (j+dd)%SZ(cycles[i]);
				}
				if (found)
				{
					ans = min(ans, dd);
					break;
				}
			}
		}

	}	
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		cout << solve() << '\n';
}
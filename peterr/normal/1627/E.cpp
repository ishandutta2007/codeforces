#include <bits/stdc++.h>
 
using namespace std;

struct Ladder
{
	int a, b, c, d, h;
};

const long long INF = 1E18;
const int MAXN = 1E5;
int x[MAXN + 1];
Ladder ladders[MAXN];
vector<int> floors[MAXN + 1];
long long dp[MAXN][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++)
		{
			floors[i].clear();
		}
		for (int i = 0; i < k; i++)
		{
			dp[i][0] = dp[i][1] = INF;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i];
		}
		for (int i = 0; i < k; i++)
		{
			int a, b, c, d, h;
			cin >> a >> b >> c >> d >> h;
			ladders[i] = {a, b, c, d, h};
			floors[a].push_back(i);
			floors[c].push_back(i);
		}
		for (int ind : floors[n])
		{
			if (ladders[ind].c == n)
			{
				dp[ind][1] = (long long) (m - ladders[ind].d) * x[n];
			}
		}
		for (int i = n; i >= 1; i--)
		{
			vector<pair<long long, int>> after;
			vector<pair<int, int>> before;
			for (int ind : floors[i])
			{
				if (ladders[ind].a == i && dp[ind][1] != INF)
				{
					dp[ind][0] = dp[ind][1] - ladders[ind].h;
					after.push_back({dp[ind][0] + (long long) (ladders[ind].b - 1) * x[i], ind});
					before.push_back({ladders[ind].b, ind});
				}
			}
			sort(after.begin(), after.end());
			sort(before.begin(), before.end());
			vector<pair<int, int>> exits;
			for (int ind : floors[i])
			{
				if (ladders[ind].c == i)
					exits.push_back({ladders[ind].d, ind});
			}
			sort(exits.begin(), exits.end());
			int afterPtr = 0;
			int beforePtr = 0;
			int beforeInd = -1;
			for (pair<int, int> pr : exits)
			{
				int col = pr.first;
				int ind = pr.second;
				while (afterPtr < (int) after.size() && ladders[after[afterPtr].second].b < col)
					afterPtr++;
				long long best = INF;
				if (afterPtr < (int) after.size())
					best = min(best, dp[after[afterPtr].second][0] + (long long) (ladders[after[afterPtr].second].b - col) * x[i]);
				while (beforePtr < (int) before.size() && before[beforePtr].first < col)
				{
					if (beforeInd == -1)
						beforeInd = before[beforePtr].second;
					else if (dp[before[beforePtr].second][0] + (long long) (col - ladders[before[beforePtr].second].b) * x[i] < dp[beforeInd][0] + (long long) (col - ladders[beforeInd].b) * x[i])
					{
						beforeInd = before[beforePtr].second;
					}
					beforePtr++;
				}
				if (beforeInd != -1)
					best = min(best, dp[beforeInd][0] + (long long) (col - ladders[beforeInd].b) * x[i]);
				dp[ind][1] = min(dp[ind][1], best);
			}
		}
		long long ans = INF;
		for (int ind : floors[1])
		{
			if (ladders[ind].a == 1 && dp[ind][0] != INF)
			{
				ans = min(ans, dp[ind][0] + (long long) (ladders[ind].b - 1) * x[1]);
			}
		}
		if (ans == INF)
			cout << "NO ESCAPE\n";
		else
			cout << ans << "\n";
	}
	return 0;
}
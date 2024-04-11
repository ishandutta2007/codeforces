#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10;
const int MAXM = 1E5 + 5;
vector<int> a[MAXN];

struct Build
{
	int choice[MAXN];
	
	Build()
	{
		fill(choice, choice + MAXN, 0);
	}
	
	bool operator<(Build const& other) const
	{
		for (int i = 0; i < MAXN; i++)
		{
			if (choice[i] < other.choice[i])
				return true;
			else if (choice[i] > other.choice[i])
				return false;
		}
		return false;
	}
};

int curChoice[MAXN];
priority_queue<pair<int, Build>, vector<pair<int, Build>>, greater<pair<int, Build>>> pq;
vector<pair<int, Build>> op;
set<Build> banned;

int getVal(Build const& b, int n)
{
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += a[i][b.choice[i]];
	return ans;
}

Build solve(int n)
{
	set<Build> visited;
	Build b;
	for (int i = 0; i < n; i++)
	{
		b.choice[i] = 0;
	}
	priority_queue<pair<int, Build>> pq;
	visited.insert(b);
	pq.push({getVal(b, n), b});
	while (pq.size())
	{
		Build curBuild = pq.top().second;
		pq.pop();
		if (!banned.count(curBuild))
			return curBuild;
		Build newBuild;
		copy(curBuild.choice, curBuild.choice + n, newBuild.choice);
		for (int i = 0; i < n; i++)
		{
			if (newBuild.choice[i] + 1 < (int) a[i].size())
			{
				newBuild.choice[i]++;
				if (visited.count(newBuild))
				{
					newBuild.choice[i]--;
					continue;
				}
				visited.insert(newBuild);
				pq.push({getVal(newBuild, n), newBuild});
				newBuild.choice[i]--;
			}
		}
	}
	return b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		for (int j = 0; j < x; j++)
		{
			int y;
			cin >> y;
			a[i].push_back(y);
		}
		reverse(a[i].begin(), a[i].end());
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		Build b;
		for (int j = 0; j < n; j++)
		{
			cin >> b.choice[j];
			b.choice[j] = (int) a[j].size() - b.choice[j];
		}
		//cout << "banned\n";
		//for (int j = 0; j < n; j++)
			//cout << b.choice[j] << " \n"[j == n - 1];
		banned.insert(b);
	}
	Build ans = solve(n);
	for (int i = 0; i < n; i++)
	{
		cout << (int) a[i].size() - ans.choice[i] << " \n"[i == n - 1];
	}
	
	//cout << ans << "\n";
	return 0;
}
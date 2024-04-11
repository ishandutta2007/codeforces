#include <bits/stdc++.h>
using namespace std;

struct Arc
{
	int type, v;
};

const int MAX = (1<<22)+1;

int n, M;

int numbers[MAX];
//vector<Arc> G[2][MAX];
bool	visited[2][MAX];
bool	present[MAX];

void DFS(int u, int type)
{
	stack<Arc> S;
	S.push({type, u});

	while (!S.empty())
	{
		auto cur = S.top(); S.pop();
		if (cur.type == 0)
		{
			if (!visited[1][cur.v])
			{
				S.push({1, cur.v});
				visited[1][cur.v] = true;
			}
		}
		else
		{
			for (int k(0); k < n; ++k)
				if (!(cur.v&(1<<k)) and !visited[1][cur.v|(1<<k)])
				{
					visited[1][cur.v|(1<<k)] = true;
					S.push({1, cur.v|(1<<k)});
				}
			if (present[(1<<n) - 1 - cur.v] and !visited[0][(1<<n) - 1 - cur.v])
			{
				visited[0][(1<<n)-1-cur.v] = true;
				S.push({0, (1<<n) - 1 - cur.v});
			}
		}
	}
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> M;

	for (int i(0); i < M; ++i)
	{
		cin >> numbers[i];
		present[numbers[i]] = true;
	}

	int ans(0);	
	for (int i(0); i < M; ++i)
		if (!visited[0][numbers[i]])
		{
			ans++;
			DFS(numbers[i], 0);
		}
	cout << ans << endl;
}
#include <bits/stdc++.h>

const int	MAX = 2e5;

struct Situation
{
	int	longueur, u;
};

std::vector<int>	G[MAX];

bool	visited[MAX][2];
bool	visiting[MAX];
int		parent[MAX][2];

bool	DFS(int u)
{
	if (visiting[u]) return false;
	visiting[u] = true;
	for (auto v : G[u])
		if (!DFS(v))
			return false;
	visiting[u] = false;
	return true;
}


int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	N, M;
	std::cin >> N >> M;

	for (int i(0); i < N; ++i)
	{
		int	m;
		std::cin >> m;
		while (m--)
		{
			int	v;
			std::cin >> v;
			--v;
			G[i].push_back(v);
		}
	}

	int		start;
	std::cin >> start;
	--start;

	std::queue<Situation>	Q;

	Q.push({0,start});
	visited[start][0] = true;
	while (!Q.empty())
	{
		Situation	cur = Q.front(); Q.pop();

		if (G[cur.u].size() == 0)
		{
			if (cur.longueur % 2 == 0)
				continue ;
			std::cout << "Win" << std::endl;

			std::vector<int>	answer;
			int	index(cur.longueur);
			for (int i(cur.u); index % 2 == 1 or i != start; --index)
			{
				answer.push_back(i+1);
				i = parent[i][(index)%2];
			}
			answer.push_back(start+1);
			for (int i(answer.size()-1); i >= 0; --i)
				std::cout << answer[i] << " ";
			std::cout << std::endl;
			while (!Q.empty()) Q.pop();
			return 0;
		}

		for (auto v : G[cur.u])
		{
			if (visited[v][(cur.longueur+1)%2])
				continue ;
			Q.push({cur.longueur+1, v});
			visited[v][(cur.longueur+1) % 2] = true;
			parent[v][(cur.longueur+1)%2] = cur.u;
		}
	}
	if (!DFS(start))
		std::cout << "Draw" << std::endl;
	else
		std::cout << "Lose" << std::endl;
}
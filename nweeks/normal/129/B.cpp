#include <bits/stdc++.h>

const int	MAX = 100;
const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

std::list<int>	G[MAX];
std::vector<bool>	visited(MAX);
int					N, M;
std::stack<int>	S;

void	DFS(int	i)
{
	visited[i] = true;
	if (G[i].size() == 0)
		return ;
	if (G[i].size() == 1)
		S.push(i);
	for (auto val : G[i])
		if (!visited[val])
			DFS(val);
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> N >> M;

	while (M--)
	{
		int		a,b;
		std::cin >> a >> b;
		--a,--b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int		cnt(-1);

	do
	{
		++cnt;
		while (!S.empty())
		{
			int		to_remove = S.top();
			int		other = G[to_remove].front();
			G[other].remove(to_remove);
			G[to_remove].remove(other);
			S.pop();
		}
		for (int i(0); i < N; ++i)
			visited[i] = false;	
		for (int i(0); i < N; ++i)
			if (!visited[i])
				DFS(i);
	} while (!S.empty());
	std::cout << cnt << std::endl;
}
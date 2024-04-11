#include <bits/stdc++.h>

const int	MAX = 7000;

int			dp[2][MAX];
bool		visited[2][MAX] = {};
int			in_deg_count[2][MAX] = {};
std::vector<int>	set[2];
int		N;

void	init(void)
{
	for (int i(0); i < MAX; ++i)
		dp[0][i] = dp[1][i] = -1;
	dp[0][0] = dp[1][0] = 0;
}

void	read_input(void)
{
	std::cin >> N;

	for (int i(0); i < 2; ++i)
	{
		int	size; std::cin >> size;
		set[i].resize(size);
		for (auto &v : set[i])
			std::cin >> v;
	}
}

int	main(void)
{
	std::ios_base::sync_with_stdio(false);
	
	init();
	read_input();
	
	std::queue<std::pair<int,int> > Q;

	Q.push({0,0});
	Q.push({1,0});
	visited[1][0] = visited[0][0] = true;

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();

		// Si on est sur une case dfaite, alors toutes les cases accessibles sont gagnables pour 
		// L'adversaire

		if (dp[cur.first][cur.second] == 0)
			for (auto v : set[!cur.first])
				dp[!cur.first][(cur.second-v+N)%N] = 1;
		else
		{
			int	cnt(0);
			for (auto v : set[!cur.first])
			{
				in_deg_count[!cur.first][(cur.second-v+N)%N]++;
				if (in_deg_count[!cur.first][(cur.second-v+N)%N] == set[!cur.first].size())
					dp[!cur.first][(cur.second-v+N)%N] = 0;
			}
		}
		
		for (auto v : set[!cur.first])
			if (dp[!cur.first][(cur.second-v+N)%N] != -1 and !visited[!cur.first][(cur.second-v+N)%N])
			{
				Q.push({!cur.first, (cur.second-v+N)%N});
				visited[!cur.first][(cur.second-v+N)%N]=true;
			}
	}

	for (int i(0); i < 2; ++i)
	{
		for (int j(1); j < N; ++j)
		{
			if (dp[i][j] == 0)
				std::cout << "Lose ";
			else if (dp[i][j] == 1)
				std::cout << "Win ";
			else
				std::cout << "Loop ";
		}
		std::cout << std::endl;
	}


}
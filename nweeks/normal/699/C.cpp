#include <bits/stdc++.h>

const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

const int	MAX = 100;
int			nothing=0;
int			gym=1;
int			contest=2;
int			event[MAX];
int	N;
int			dp[3][MAX];

int		MIN(int a,int b, int c) 
{
	return std::min(a, std::min(b, c));
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> N;
	for (int i(0); i < N; ++i)
		std::cin >> event[i];

	dp[nothing][0] = 1;
	if (event[0] == 0)
		dp[gym][0] = dp[contest][0] = 1e9;
	else if (event[0] == 1)
		dp[gym][0] = 1e9, dp[contest][0] = 0;
	else if (event[0] == 2)
		dp[contest][0] = 1e9, dp[gym][0] = 0;
	else
		dp[contest][0] = 0, dp[gym][0] = 0;

	for (int i(1); i < N; ++i)
	{
		if (event[i] == 0)
		{
			dp[0][i] = 1 + std::min(dp[0][i-1],std::min(dp[1][i-1],dp[2][i-1]));
			dp[1][i] = dp[2][i] = 1e9;
		}
		if (event[i] == 1)
		{
			dp[contest][i] = std::min(dp[gym][i-1], dp[nothing][i-1]);
			dp[nothing][i] = 1 + MIN(dp[0][i-1], dp[1][i-1], dp[2][i-1]);
			dp[gym][i] = 1e9;
		}
		if (event[i] == 2)
		{
			dp[gym][i] = std::min(dp[contest][i-1], dp[nothing][i-1]);
			dp[nothing][i] = 1 + MIN(dp[0][i-1], dp[1][i-1],dp[2][i-1]);
			dp[contest][i] = 1e9;
		}
		if (event[i] == 3)
		{
			dp[gym][i] = std::min(dp[contest][i-1], dp[nothing][i-1]);
			dp[contest][i] = std::min(dp[gym][i-1], dp[nothing][i-1]);
			dp[nothing][i] = 1 + MIN(dp[0][i-1], dp[1][i-1],dp[2][i-1]);
		}
	}
	std::cout << MIN(dp[0][N-1],dp[1][N-1], dp[2][N-1])<<std::endl;
}
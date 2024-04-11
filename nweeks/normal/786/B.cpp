#include <bits/stdc++.h>

struct Arrete
{
	int	v;
	long long c;
};

struct Situation
{
	int	u;
	long long	dis;

	bool operator<(Situation other) const
	{
		return dis > other.dis;
	}
};

const int	MAXN = 1e5;
const int	MAXH = std::ceil(log2(MAXN)) + 2;
const int	MAXE = (1<<MAXH);
const int	LEAF_START = (1<< (MAXH-1));

bool		visited[MAXE];
long long	distance[MAXE];
std::vector<Arrete>	G[MAXE];

int	nb_noeuds, nb_segments, terre;

void	process_type_one(void)
{
	int	u, v, c;
	std::cin >> u >> v >> c;
	--u, --v;

	G[u + LEAF_START].push_back({v + 3 * (LEAF_START / 2), c});
}

void	process_type_two(void)
{
	int		u, l, r, c;
	std::cin >> u >> l >> r >> c;
	--u;

	l = l + (1 << (MAXH - 1)) + (1 << (MAXH - 2)) - 1;
	r = r + (1 << (MAXH - 1)) + (1 << (MAXH - 2));

	while (l < r)
	{
		if (l % 2 == 1)
			G[u + LEAF_START].push_back({l++, c});
		if (r % 2 == 1)
			G[u + LEAF_START].push_back({--r, c});
		l /= 2;
		r /= 2;
	}
}

void	process_type_three(void)
{
	int		u, l, r, c;
	std::cin >> u >> l >> r >> c;
	--u;

	l += LEAF_START - 1;
	r += LEAF_START;

	while (l < r)
	{
		if (l % 2 == 1)
			G[l++].push_back({u+LEAF_START, c});
		if (r % 2 == 1)
			G[--r].push_back({u+LEAF_START, c});
		r /= 2;
		l /= 2; 
	}
}

void	read_input(void)
{
	for (int i(0); i < MAXE; ++i)
		distance[i] = 1e18;
	for (int i(0); i < LEAF_START / 2; ++i)
		G[i + 3 * LEAF_START / 2].push_back({i + LEAF_START, 0});
	std::cin >> nb_noeuds >> nb_segments >> terre;

	while (nb_segments--)
	{
		int	type; std::cin >> type;
		if (type == 1)
			process_type_one();
		else if (type == 2)
			process_type_two();
		else
			process_type_three();
	}
}

void	ajoute_up(int noeud)
{
	if (noeud >= MAXE)
		return ;
	if (noeud > 3)
		G[noeud].push_back({noeud / 2, 0});
	ajoute_up(noeud * 2);
	ajoute_up(noeud * 2 + 1);
}

void	ajoute_down(int noeud)
{
	if (noeud >= MAXE)
		return ;
	if (noeud > 3)
		G[noeud / 2].push_back({noeud, 0});
	ajoute_down(2 * noeud);
	ajoute_down(2 * noeud + 1);
}

void	run_disjktra(void)
{
	std::priority_queue<Situation>	Q;

	Q.push({terre - 1 + LEAF_START, 0});
	distance[terre - 1 + LEAF_START] = 0;
	visited[terre - 1 + LEAF_START] = true;

	while (!Q.empty())
	{
		auto cur = Q.top(); Q.pop();

		for (auto v : G[cur.u])
		{
			if (distance[v.v] > cur.dis + v.c)
			{
				visited[v.v] = true;
				distance[v.v] = cur.dis + v.c;
				Q.push({v.v, cur.dis + v.c});
			}
		}
	}
}

void	output(void)
{
	for (int i(0); i < nb_noeuds; ++i)
	{
		if (!visited[i + LEAF_START])
			std::cout << -1 << " ";
		else
			std::cout << distance[i + LEAF_START] << " ";
	}
	std::cout << std::endl;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	
	read_input();
	ajoute_down(3);
	ajoute_up(2);

	run_disjktra();
	output();
}
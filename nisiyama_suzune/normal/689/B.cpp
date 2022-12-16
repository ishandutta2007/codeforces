#include <cstdio>
#include <assert.h>
#include <vector>
#include <queue>
#include <iostream>

#define NODESIZE 250000
#define INF 1E9

struct Path
{
	int dest;
	int cost;
};

struct Node
{
	int vertex;
	int cost;
};

bool operator < (const Node &a, const Node &b)
{
	return (a.cost > b.cost);
}

std::vector <Path> edge[NODESIZE];
std::priority_queue <Node> searchQueue;
int vertexCost[NODESIZE];

void init ()
{
	for (int i = 0; i < NODESIZE; i ++)
	{
		edge[i].clear ();
		vertexCost[i] = INF;
	}
}

void addEdge (int from, int dest, int cost)
{
	assert (from >= 0 && dest >= 0);
	edge[from].push_back ((Path) {dest, cost});
}

int Dijkstra (int beginNode)
{
	assert (beginNode >= 0);
	searchQueue.push ((Node){beginNode, 0});
	while (!searchQueue.empty ())
	{
		int q = searchQueue.top ().vertex, qc = searchQueue.top ().cost;
		searchQueue.pop ();
		if (vertexCost[q] < INF)
			continue;
		vertexCost[q] = qc;
		for (int i = 0; i < edge[q].size (); i++)
		{
			int p = edge[q][i].dest, c = edge[q][i].cost;
			if (vertexCost[p] == INF)
				searchQueue.push ((Node){p, qc + c});
		}
	}
	return 0;
}

int N;

int main ()
{
	std::cin >> N;
	init ();
	addEdge (1, 2, 1);
	addEdge (2, 1, 1);
	addEdge (N, N - 1, 1);
	addEdge (N - 1, N, 1);
	for (int i = 2; i <= N - 1; i++)
	{
		addEdge (i - 1, i, 1);
		addEdge (i, i - 1, 1);
		addEdge (i, i + 1, 1);
		addEdge (i + 1, i, 1);
	}
	for (int i = 1; i <= N; i++)
	{
		int a;
		std::cin >> a;
		addEdge (i, a, 1);
	}
	Dijkstra (1);
	std::cout << vertexCost[1];
	for (int i = 2; i <= N; i++)
		std::cout << " " << vertexCost[i];
	std::cout << std::endl;
	return 0;
}
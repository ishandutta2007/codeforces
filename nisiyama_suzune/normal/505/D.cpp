#include <cstdio>
#include <vector>

using namespace std;

int Mark[110000] = {0};
int IsVisited[110000] = {0};
bool HasCircle[110000] = {false};
int N, M;

vector <int> UndirectedGraph[110000], DirectedGraph[110000];

void MarkGraph (int x, int mark)
{
	Mark[x] = mark;
	for (int i = 0; i < UndirectedGraph[x].size (); i++)
		if (Mark[UndirectedGraph[x][i]] == 0) MarkGraph (UndirectedGraph[x][i], mark);
	return;
}

bool Search (int x)
{
	IsVisited[x] = -1;
//	printf ("Now at %d", x);
	for (int i = 0; i < DirectedGraph[x].size (); i++)
	{
		if (IsVisited[DirectedGraph[x][i]] == -1)
		{
//			printf ("Succeeded %d", x);
			IsVisited[x] = 1;
			return true;
		}
		if (IsVisited[DirectedGraph[x][i]] == 1) continue;
		if (Search (DirectedGraph[x][i]))
		{
//			printf ("Succeeded %d", x);
			IsVisited[x] = 1;
			return true;
		}
	}
//	printf ("Now end at %d", x);
	IsVisited[x] = 1;
	return false;
}

int main ()
{
	scanf ("%d%d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf ("%d%d", &a, &b);
		UndirectedGraph[a].push_back (b);
		UndirectedGraph[b].push_back (a);
		DirectedGraph[a].push_back (b);
	}
	int Ans = N;
	for (int i = 1; i <= N; i++)
	{
//		HasCircle[i] = true;
		if (Mark[i] != 0) continue;
		MarkGraph (i, i);
	}
	for (int i = 1; i <= N; i++)
	{
		if (HasCircle[Mark[i]]) continue;
		if (IsVisited[i] == 0) HasCircle[Mark[i]] = Search (i);
	}
	for (int i = 1; i <= N; i++)
		if (Mark[i] == i && !HasCircle[i]) Ans--;
	printf ("%d\n", Ans);
	return 0;
}
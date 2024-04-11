#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long ll;

int dist[505][505], alive[505], answer[505];
vector <int> g[505];

int main()
{
 	//freopen("input.txt", "r", stdin);
 	//freopen("output.txt", "w", stdout);
 	ios_base::sync_with_stdio(0); cin.tie(0);
 	int n, m;
 	cin >> n >> m;
 	for (int i = 1; i <= m; i++)
 	{
 	 	int k;
 	 	cin >> k;
 	 	vector <int> path(k);
 	 	for (int j = 0; j < k; j++) cin >> path[j];
 	 	for (int j = 1; j < k; j++) g[path[j - 1]].pb(path[j]), g[path[j]].pb(path[j - 1]);
 	}

 	for (int start = 1; start <= n; start++)
 	{
 	 	queue <int> qu;
 	 	for (int i = 1; i <= n; i++) dist[start][i] = n;
 	 	dist[start][start] = 0;
 	 	qu.push(start);
 	 	while (!qu.empty())
 	 	{
 	 	 	int v = qu.front();
 	 	 	qu.pop();
 	 	 	for (int u : g[v])
 	 	 		if (dist[start][u] > dist[start][v] + 1)
 	 	 		{
 	 	 		 	dist[start][u] = dist[start][v] + 1;
 	 	 		 	qu.push(u);
 	 	 		}
 	 	}
 	}

 	for (int rep = 1; rep <= n; rep++)
 	{
 	 	for (int i = 1; i <= n; i++) alive[i] = 0;
		vector <int> vertex;
		for (int i = 1; i <= n; i++) vertex.pb(i);

		int sch = 0;
 	 	while (true)
 	 	{
 	 		for (int v : vertex) answer[v] = 0;
 	 		for (int v : vertex)
 	 			for (int u : g[v])
 	 			{
 	 			 	if (alive[u] != sch) continue;
 	 			 	int kol = 0;
 	 			 	for (int w : vertex)
 	 			 		if (dist[v][w] == dist[u][w] + 1) kol++;
 	 			 	answer[v] = max(answer[v], kol); 
 	 		 	}
 	 		int mn = vertex[0];
 	 		for (int v : vertex)
 	 			if (answer[v] < answer[mn]) mn = v;

 	 		cout << mn << endl;
 	 		string S;
 	 		cin >> S;
 	 		if (S == "FOUND") break;
 	 		
 	 		int nx;
 	 		cin >> nx;
 	 		vector <int> cop;
 	 		for (int w : vertex)
 	 			if (dist[mn][w] == dist[nx][w] + 1) alive[w]++, cop.pb(w);

 	 		vertex = cop;
 	 		sch++;
 	 	}
 	}
 	return 0;
}
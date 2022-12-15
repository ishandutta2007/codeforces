#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;

using ll = long long;

template<typename... Args>
void read(Args&... args)
{
	((cin >> args), ...);
}

template<typename... Args>
void write(Args... args)
{
	((cout << args << " "), ...);
}

template<typename... Args>
void writeln(Args... args)
{
	((cout << args << " "), ...); cout << '\n';
}

struct Edge
{
	ll to, f, c;
};

struct Graph
{
	vector<Edge> edges;
	vector<vector<int>> G;
	int s, t;
	Graph(int n, int s, int t) : edges(), G(n), s(s), t(t) {}

	void addEdge(int a, int b, ll c1, ll c2=0) // If not directed, take c2=c1
	{
		G[a].push_back(SZ(edges));
		edges.push_back(Edge{b, 0, c1});
		G[b].push_back(SZ(edges));
		edges.push_back(Edge{a, 0, c2});
	}
};

struct Dinic : public Graph
{
	vector<int> dis, ptr;
	Dinic(int n, int s, int t) : Graph(n, s, t) {}

	ll dfs(ll v, ll maxF)
	{
		if (!maxF or v == t) return maxF;
		for (; ptr[v] < SZ(G[v]); ++ptr[v])
		{
			int k = G[v][ptr[v]];
			Edge &ed = edges[k];
			if (ed.c > ed.f and dis[ed.to] == dis[v] + 1)
				if (ll df = dfs(ed.to, min(maxF, ed.c-ed.f)))
				{
					ed.f += df;
					edges[k^1].f -= df;
					return df;
				}
		}
		return 0;
	}

	ll flow(void)
	{
		int N = SZ(G);
		ll f(0);
		while (1)
		{
			dis.assign(N, -1);
			queue<int> q; q.push(s); dis[s] = 0;
			while (!q.empty())
			{
				int u = q.front(); q.pop();
				if (u == t) break;
				for (auto k : G[u])
				{
					Edge ed = edges[k];
					if (ed.c > ed.f and dis[ed.to] == -1)
					{
						dis[ed.to] = dis[u] + 1;
						q.push(ed.to);
					}
				}
			}
			if (dis[t] == -1) break;
			ptr.assign(N, 0);
			while (ll df = dfs(s, (1LL<<62))) f += df;
		}
		return f;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int nbSommets;
	cin >> nbSommets;
	vector<int> arr(nbSommets);
	for (auto &v : arr) read(v);
	vector<ll> cost(nbSommets);
	for (auto &v : cost) read(v);
	Dinic dic(nbSommets+2, nbSommets, nbSommets+1);
	
	for (int i(0); i < nbSommets; ++i)
	{
		if (cost[i] > 0)
			dic.addEdge(nbSommets, i, cost[i]);
		else
			dic.addEdge(i, nbSommets+1, -cost[i]);
	}
	for (int i(0); i < nbSommets; ++i)
	{
		vector<bool> seen(101, false);
		for (int j(i-1); j >= 0; --j)
		{
			if (arr[i] % arr[j]) continue;
			if (seen[arr[j]]) continue;
			seen[arr[j]] = true;
			dic.addEdge(i, j, (ll)1e18);
		}
	}
	ll ret(0);
	for (auto v : cost) ret += max(0LL, v);
	ret -= dic.flow();
	writeln(ret);
}
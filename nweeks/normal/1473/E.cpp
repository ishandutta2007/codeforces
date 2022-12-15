#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;
typedef long long ll; 

int nbSommets, nbAretes;
struct Edge
{
	int v, w;
};

const int MAXN =2e5;

ll dis[4][MAXN];
bool seen[4][MAXN];
vector<Edge> G[MAXN];

struct Situation
{
	int state, u;
	ll d;

	bool operator<(Situation other) const
	{
		if (d == other.d)
			return make_pair(state, u) < make_pair(other.state, other.u);
		return d > other.d;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	for (int i(0); i < 4; ++i)
		for (int j(0); j < MAXN; ++j)
			dis[i][j] = 1e18;
	cin >> nbSommets >> nbAretes;
	for (int i(0); i < nbAretes; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}

	dis[0][0] = 0;
	priority_queue<Situation> pq;
	pq.push({0, 0, 0});
	while (!pq.empty())
	{
		auto [state, u, d] = pq.top(); pq.pop();
		if (seen[state][u]) continue;
		seen[state][u] = true;

		for (auto [v, w] : G[u])
		{
			if (!(state & 1) and d + 2 * w < dis[state | 1][v])
			{
				dis[state | 1][v] = d + 2 * w;
				pq.push({state | 1, v, d + 2 * w});
			}
			if (!(state & 2) and d < dis[state | 2][v])
			{
				dis[state | 2][v] = d;
				pq.push({state | 2, v, d});
			}
			if (!state and d + w < dis[3][v])
			{
				dis[3][v] = d + w;
				pq.push({3, v, d + w});
			}
			if (d + w < dis[state][v])
			{
				dis[state][v] = d + w;
				pq.push({state, v, d + w});
			}
		}
	}
	for (int i(1); i < nbSommets; ++i)
		cout << dis[3][i] << ' ';
	cout << endl;
}
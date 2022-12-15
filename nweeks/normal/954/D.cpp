#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3;
vector<int> G[MAXN];
int disfroms[MAXN], disfromt[MAXN];
bool visited[MAXN];

int N, M, s, t;

void read_input(void)
{
	cin >> N >> M >> s >> t;
	--s, --t;

	for (int i(0); i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		G[u-1].push_back(v-1);
		G[v-1].push_back(u-1);
	}
}

void calc_disfroms(void)
{
	for (int i(0); i < N; ++i)
		visited[i] = false;
	queue<int> Q;
	Q.push(s);
	visited[s] = true;
	disfroms[s] = 0;
	while (!Q.empty())
	{
		int cur = Q.front(); Q.pop();

		for (auto v : G[cur])
			if (!visited[v])
			{
				visited[v] = true;
				disfroms[v] = disfroms[cur] + 1;
				Q.push(v);
			}
	}
}

void calc_dis_fromt(void)
{
	for (int i(0); i < N; ++i)
		visited[i] = false;
	queue<int > Q;
	Q.push(t);
	visited[t] = true;
	disfromt[t] = 0;
	while (!Q.empty())
	{
		int cur = Q.front(); Q.pop();

		for (auto v : G[cur])
			if (!visited[v])
			{
				visited[v] = true;
				disfromt[v] = disfromt[cur] + 1;
				Q.push(v);
			}
	}
}

int		comp(int cur)
{
	for (int i(0); i < N; ++i)
		visited[i] = false;
	int dis[MAXN] = {};
	queue<int> Q;
	Q.push(cur);
	dis[cur] = 0;
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();

		for (auto v :G[u])
			if (!visited[v])
			{
				visited[v] = true;
				dis[v] = dis[u] + 1;
				Q.push(v);
			}
	}

	int ret(0);

	for (int i(cur + 1); i < N; ++i)
	{
		if (dis[i] <= 1) continue;
		if (disfroms[t] <= disfroms[cur] + 1 + disfromt[i] and disfroms[t] <= disfroms[i] + 1 + disfromt[cur])
			++ret;
	}

	return ret;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
	
	read_input();
	calc_disfroms();
	calc_dis_fromt();

	int ans(0);
	for (int i(0); i < N; ++i)
		ans += comp(i);
	cout << ans << endl;
}
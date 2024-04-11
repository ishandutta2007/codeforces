#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;

using ll = long long;

template<typename... Args>
void read(Args&... args)
{
	((cin >> args), ...);
}
template<typename T>
void read(vector<T> &vec)
{
	for (auto &v : vec) read(v);
}

void write() {}
template<typename H, typename... T>
void write(const H &h, const T&... t)
{
	cout << h;
	if (sizeof...(t)) {cout << ' '; write(t...);}
}

template<typename T>
void write(const vector<T> &vec)
{
	if (SZ(vec) == 0) return;
	write(vec[0]);
	for (int i(1); i < SZ(vec); ++i)
	{cout << ' '; write(vec[i]);}
}

template<typename... Args>
void writeln(Args... args)
{
	write(args...); cout << '\n';
}

struct Situation
{
	int u;
	ll disFrom, dis;

	bool operator<(Situation other) const
	{
		if (dis == other.dis)
			return make_pair(u, disFrom) < make_pair(other.u, other.disFrom);
		return dis > other.dis;
	}
};

const int MAXN =1e5;
bool seen[51][MAXN];
ll dis[51][MAXN];
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nbSommets, nbAretes;
	read(nbSommets, nbAretes);
	priority_queue<Situation> q;
	vector<vector<pair<int, int>>> g(nbSommets);
	for (int i(0); i <= 50; ++i)
		for (int u(0); u < nbSommets; ++u)
			dis[i][u] = 1e18;
	while (nbAretes--)
	{
		int u, v, w;
		read(u, v, w);
		--u, --v;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	q.push({0, 0, 0});
	dis[0][0] = 0;
	while (SZ(q))
	{
		auto [u, disFrom, d] = q.top(); q.pop();
		if (seen[disFrom][u]) continue;
		seen[disFrom][u] = true;
		for (auto [v, w] : g[u])
		{
			ll nxtDisFrom = disFrom ? 0 : w;
			ll nxtDis = d + 2 * disFrom * w + w * w;
			if (dis[nxtDisFrom][v] > nxtDis)
			{
				dis[nxtDisFrom][v] = nxtDis;
				q.push({v, nxtDisFrom, nxtDis});
			}
		}
	}
	for (int i(0); i <= 50; ++i)
		for (int u(0); u < nbSommets; ++u)
			if (dis[i][u] == 1e18)
				dis[i][u] = -1;
	for (int u(0); u < nbSommets; ++u)
		write(dis[0][u], "");
	writeln();
}
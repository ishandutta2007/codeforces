#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAXN = 2e5;

vector<int> G[MAXN];
ll cost[MAXN];
int have[MAXN], want[MAXN];
int cnt;
ll ans;

pair<int, int> dfs(int u, int p, ll curBestCost)
{
	int nb[2] = {0, 0};
	if (have[u] != want[u])
		nb[want[u]]++;

	for (auto v : G[u])
		if (v != p)
		{
			auto pp = dfs(v, u, min(curBestCost, cost[u]));
			nb[0] += pp.first;
			nb[1] += pp.second;
		}
	if (curBestCost >= cost[u])
	{
		int take = min(nb[0], nb[1]);
		ans += 2 * take * cost[u];
		nb[0] -= take, nb[1] -= take;
	}
	return {nb[0], nb[1]};
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nbSommets;
	cin >> nbSommets;
	for (int i(0); i < nbSommets; ++i)
		cin >> cost[i] >> have[i] >> want[i];
	for (int i(1); i < nbSommets; ++i)
	{
		int _u, _v;
		cin >> _u >> _v;
		--_u, --_v;
		G[_u].push_back(_v);
		G[_v].push_back(_u);
	}
	if (dfs(0, 0, 1e18) != make_pair(0, 0))
		cout << -1 << '\n';
	else
		cout << ans << endl;
}
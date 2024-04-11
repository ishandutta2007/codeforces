#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAXN = 2e5;
int nb_sommets;
vector<int> G[MAXN];
int deg[MAXN];
bool erased[MAXN];

vector<int> get_furthest(int u)
{
	vector<int> dis(nb_sommets, nb_sommets);
	dis[u] = 0;
	queue<int> q;
	q.push(u);
	while (SZ(q))
	{
		int v = q.front(); q.pop();
		for (auto w : G[v])
			if (dis[w] == nb_sommets)
			{
				dis[w] = dis[v] + 1;
				q.push(w);
			}
	}
	return dis;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> nb_sommets;
	for (int i(1); i < nb_sommets; ++i)
		{
			int _u, _v;
			cin >> _u >> _v;
			--_u, --_v;
			G[_u].push_back(_v);
			G[_v].push_back(_u);
			++deg[_u];
			++deg[_v];
		}
	auto disu = get_furthest(0);
	int u=0;
	for (int i(0); i < nb_sommets; ++i)
		if (disu[i] > disu[u])
			u = i;
	disu = get_furthest(u);
	int v(0);
	for (int i(0); i < nb_sommets; ++i)
		if (disu[i] > disu[v])
			v = i;
	auto disv = get_furthest(v);

	ll ans(0);
	vector<tuple<int,int,int> > sol;
	queue<int> to_rem;
	for (int i(0); i < nb_sommets; ++i)
		if (deg[i] == 1 and i != u and i != v)
			to_rem.push(i);
	while (SZ(to_rem))
	{
		int cur = to_rem.front(); to_rem.pop();
		if (disu[cur] > disv[cur])
		{
			sol.emplace_back(cur+1, u+1, cur+1);
			ans += disu[cur];
		}
		else
		{
			sol.emplace_back(cur+1, v+1 , cur+1);
			ans += disv[cur];
		}
		erased[cur] = true;
		for (auto w : G[cur])
			if (!erased[w] and --deg[w] == 1)
			{
				assert(w != u and w != v);
				to_rem.push(w);
			}
	}

	while (u != v)
	{
		for (auto w : G[u])
			if (!erased[w])
			{
				ans += disv[u];
				sol.emplace_back(u+1, v+1, u+1);
				erased[u] = true;
				u = w;
				break;
			}
	}
	cout << ans << endl;
	for (auto [u, v, w] : sol)
		cout << u << ' ' << v << ' ' << w << '\n';
}
#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAXN = 2e5;

vector<int> G[MAXN];
int nb_sommets, nb_aretes;


vector<int> bfs(int source)
{
	int _nb_sommets = nb_sommets;
	vector<int> dis(nb_sommets, -1);

	dis[source] = 0;
	queue<int> Q;
	Q.push(source);
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();

		for (auto v : G[u])
			if (dis[v] == -1)
			{
				dis[v] = dis[u] + 1;
				Q.push(v);
			}
	}

	return dis;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> nb_sommets >> nb_aretes;
	for (int i(0); i < nb_aretes; ++i)
	{
		int _u, _v;
		cin >> _u >> _v;
		--_u, --_v;
		G[_v].push_back(_u);
	}

	int len;
	cin >> len;
	vector<int> path(len);
	for (auto &v : path)
	{
		cin >> v;
		--v;
	}
	vector<int> dis = bfs(path.back());
	

	vector<int> nb_bon(nb_sommets);
	for (int i = 0; i < nb_sommets; ++i)
		for (auto v : G[i])
			if (dis[v] == dis[i] + 1)
				nb_bon[v]++;
	
	int mini(0), maxi(0);
	for (int i(0); i < len-1; ++i)
	{
		if (dis[path[i+1]] + 1 != dis[path[i]])
			++mini, ++maxi;
		else if (nb_bon[path[i]] > 1)
			++maxi;
	}
	cout << mini << ' ' << maxi << endl;
}
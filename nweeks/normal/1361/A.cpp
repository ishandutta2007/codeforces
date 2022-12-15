#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAXN = 5e5;

vector<int> G[MAXN];
set<int> picked[MAXN];
int want[MAXN];
int nbSommets, nbAretes;
vector<int> order;

bool comp(int u, int v)
{
	if (want[u] == want[v])
		return u < v;
	return want[u] < want[v];
}

bool check(void)
{
	for (int i(0); i < nbSommets; ++i)
	{
		int cur(0);
		int u = order[i];
		auto it = picked[u].begin();
		while (it != picked[u].end() and *it == cur+1)
			++it, ++cur;
		if (cur+1 != want[u])
			return false;
		for (auto v : G[u])
			picked[v].insert(cur+1);
	}
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> nbSommets >> nbAretes;

	for (int i(0); i < nbAretes; ++i)
	{
		int _u, _v;
		cin >> _u >> _v;
		--_u, --_v;
		G[_u].push_back(_v);
		G[_v].push_back(_u);
	}
	for (int i(0); i < nbSommets; ++i)
	{
		cin >> want[i];
		order.push_back(i);
	}
	sort(order.begin(), order.end(), comp);
	if (!check())
		cout << -1 << endl;
	else
	{
		for (auto v : order)
			cout << v+1 << ' ';
		cout << endl;
	}

}
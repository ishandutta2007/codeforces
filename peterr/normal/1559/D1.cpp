#include <bits/stdc++.h>
 
using namespace std;
 
struct dsu
{
	dsu(int n)
	{
		comps = n;
		par = vector<int>(n + 1);
		roots = set<int>();
		sz = vector<int>(n + 1);
		who = vector<vector<int>>(n + 1);
		for (int i = 1; i <= n; i++)
		{
			roots.insert(i);
			par[i] = i;
			sz[i] = 1;
			who[i] = {i};
		}
	}
	
	int getRoot(int x)
	{
		if (par[x] != x)
			par[x] = getRoot(par[x]);
		return par[x];
	}
	
	bool mge(int x, int y)
	{
		x = getRoot(x);
		y = getRoot(y);
		if (x == y)
			return false;
		if (sz[x] >= sz[y])
			swap(x, y);
		par[x] = y;
		sz[y] += sz[x];
		comps--;
		for (int z : who[x])
			who[y].push_back(z);
		roots.erase(x);
		return true;
	}
 
	set<int> roots;
	vector<int> par;
	vector<int> sz;
	vector<vector<int>> who;
	int comps;
};
 
const int MAXN = 1E5;
bool active[MAXN + 1];
int rep[MAXN + 1];
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	dsu dsu1(n);
	dsu dsu2(n);
	for (int i = 0; i < m1; i++)
	{
		int u, v;
		cin >> u >> v;
		dsu1.mge(u, v);
	}
	for (int i = 0; i < m2; i++)
	{
		int u, v;
		cin >> u >> v;
		dsu2.mge(u, v);
	}
	if (dsu1.comps > dsu2.comps)
		swap(dsu1, dsu2);
	for (int x : dsu1.who[dsu1.getRoot(1)])
	{
		active[dsu2.getRoot(x)] = true;
	}
	vector<pair<int, int>> ans;
	for (int i = 1; i <= n; i++)
	{
		if (dsu2.getRoot(i) != i || active[i])
			continue;
		ans.push_back({1, i});
		for (int x : dsu1.who[dsu1.getRoot(i)])
		{
			active[dsu2.getRoot(x)] = true;
		}
		dsu1.mge(1, i);
		dsu2.mge(1, i);
	}
	//cout << "First pass added " << ans.size() << endl;
	for (int x : dsu1.who[dsu1.getRoot(1)])
	{
		rep[dsu2.getRoot(x)] = x;
		//cout << "rep " << x << " = " << dsu2.getRoot(x) << endl;
	}
	for (int i = 1; i <= n; i++)
	{
		if (dsu1.getRoot(i) == dsu1.getRoot(1) || dsu1.getRoot(i) != i)
			continue;
		//cout << "iter " << i << endl;
		int r = *dsu2.roots.begin();
		//cout << "root of is " << dsu2.getRoot(i) << endl;
		//cout << "r = " << r << endl;
		if (r == dsu2.getRoot(i))
			r = *(++dsu2.roots.begin());
		//cout << "r = " << r << endl;
		int other = rep[r];
		ans.push_back({i, other});
		for (int x : dsu1.who[dsu1.getRoot(i)])
		{
			active[dsu2.getRoot(x)] = true;
		}
		dsu1.mge(i, other);
		dsu2.mge(i, other);
	}
	cout << ans.size() << "\n";
	for (pair<int, int> pr : ans)
		cout << pr.first << " " << pr.second << "\n";
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 50;

int n, gmax;
vector<int> G[N], euler;

int query(vector<int> vec)
{
	cout << "? " << vec.size();
	for (int x : vec) cout << " " << x;
	cout << '\n';
	cout.flush();
	int x;
	cin >> x;
	return x;
}

int query(int l, int r)
{
	vector<int> v;
	for (int i = l; i <= r; ++i)
	{
		v.push_back(euler[i]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	return query(v);
}

void report(int a, int b)
{
	cout << "! " << a << " " << b << '\n';
	cout.flush();
	exit(0);
}

void dfs(int x, int fa = 0)
{
	euler.push_back(x);
	for (int y : G[x])
		if (y != fa)
		{
			dfs(y, x);
			euler.push_back(x);
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v), G[v].push_back(u);
	}
	dfs(1);
	gmax = query(0, euler.size() - 1);
	int l = 0, r = euler.size() - 1;
	while (r - l > 1)
	{
		const int mid = l + r >> 1;
		if (query(l, mid) == gmax)
		{
			r = mid;
		}
		else
		{
			l = mid;
		}
	}
	report(euler[l], euler[r]);
}
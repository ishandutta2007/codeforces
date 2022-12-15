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

const int MAXN = 2e5;

vector<vector<pair<int, int>>> g;
int nbSommets;
ll fibo[50];
vector<int> sz, par;
vector<bool> killed;
int potential;

void dfs(int u, int p)
{
	sz[u] = 1;
	par[u] = p;
	for (auto [v, id] : g[u])
		if (!killed[id] and v != p)
		{
			dfs(v,u);
			sz[u] += sz[v];	
		}
}

bool solve(int u, int k)
{
	if (k <= 1)
		return true;
	dfs(u, -1);
	queue<int> q;
	q.push(u);
	while (SZ(q))
	{
		int u = q.front(); q.pop();
		for (auto [v, id] : g[u])
			if (!killed[id] and v != par[u])
			{
				if (sz[v] == fibo[k-1] or sz[v] == fibo[k-2])
				{
					killed[id] = true;
					while (SZ(q)) q.pop();
					if (sz[v] == fibo[k-1])
						return solve(v, k-1) and solve(u, k-2);
					if (sz[v] == fibo[k-2])
						return solve(v, k-2) and solve(u, k-1);
				}
				q.push(v);
			}
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	fibo[0] = fibo[1] = 1;
	for (int i(2); fibo[i-1] < MAXN; ++i)
		fibo[i] = fibo[i-1] + fibo[i-2];

	read(nbSommets);
	g.resize(nbSommets);
	for (int i(0); i < nbSommets-1; ++i)
	{
		int u, v;
		read(u, v);
		--u, --v;
		g[u].emplace_back(v, i);
		g[v].emplace_back(u, i);
	}
	int k(1);
	while (fibo[k] < nbSommets)
		++k;
	if (fibo[k] != nbSommets)
	{
		writeln("no");
		return 0;
	}
	sz.resize(nbSommets);
	killed.resize(nbSommets);
	par.resize(nbSommets);
	writeln(solve(0, k) ? "yes":"no");
}
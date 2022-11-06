#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

std::vector<std::vector<int> > adj;
int n;

void dfs(std::vector<int>& inc, std::vector<int>& exc, int u, int p)
{
	exc[u] = 0;
	inc[u] = 0;
	int maxl = 0, maxl1 = 0;
	for (int v : adj[u])
	{
		if (v != p)
		{
			dfs(inc, exc, v, u);
			if(maxl < inc[v])
			{
				maxl1 = maxl;
				maxl = inc[v];
			} 
			else if(maxl1 < inc[v])
			{
				maxl1 = inc[v];
			}
			inc[u] = max(inc[v], inc[u]);
			exc[u] = max(exc[u], exc[v]);
		}
	}
	inc[u]++;
	exc[u] = max(exc[u], maxl + maxl1 + 1);
}

int diam(int root, int parent)
{
	std::vector<int> inc(n, 0);
	std::vector<int> exc(n, 0);
	dfs(inc, exc, root, parent);
	return max(inc[root], exc[root]);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); 
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	cin >> n;
	adj.resize(n);
	int u, v;
	for (int i = 0; i < n-1; ++i)
	{
		cin >> u >> v; u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int profit = 0;
	for (int u = 0; u < n; ++u)
	{
		for(int v : adj[u])
		{
			print(u, v);
			if(u < v)
			{
				int l1 = diam(u, v); l1--;
				int l2 = diam(v, u); l2--;
				print(l1, l2);
				profit = max(profit, l1*l2);
			}
		}
	}
	cout << profit;
}
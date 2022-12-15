#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

const int MAXN = 1e5;

vector<int> G[MAXN];
int proc[MAXN];
int in_deg[MAXN];

vector<int> need_dfs;
vector<int> in_coproc;
	queue<int> Q;

void run_dfs(int u)
{
	in_coproc.push_back(u);
	for (auto v : G[u])
		if (proc[v])
		{
			in_deg[v]--;
			if (!in_deg[v])
				run_dfs(v);
		}
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	for (int i(0); i < n; ++i)
		cin >> proc[i];
	for (int i(0); i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		G[v].push_back(u);
		in_deg[u]++;
	}


	for (int i(0); i < n; ++i)
		if (in_deg[i]==0)
		{
			if (proc[i])
				need_dfs.push_back(i);
			else
				Q.push(i);
		}
	int calls(0);
	while (!Q.empty() or SZ(need_dfs)>0 or !in_coproc.empty())
	{
		if (!Q.empty())
		{
			int u = Q.front(); Q.pop();
			for (auto v : G[u])
			{
				in_deg[v]--;
				if (in_deg[v]==0)
				{
					if (proc[v])
						need_dfs.push_back(v);
					else
						Q.push(v);
				}
			}
		}
		else if (SZ(in_coproc) > 0)
		{
			++calls;
			for (auto u : in_coproc)
				for (auto v : G[u])
					if (proc[v]==0)
					{
						in_deg[v]--;
						if (in_deg[v]==0)
							Q.push(v);
					}
			in_coproc.clear();
		}
		else
		{
			for (auto u : need_dfs)
				run_dfs(u);
			need_dfs.clear();
		}
	}
	cout << calls << endl;
}
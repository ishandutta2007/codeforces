#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

const int MAXN = 1e3;

vector<int> G[MAXN];

int ask(int u, int v)
{
	cout << "? " << u + 1 << ' ' << v + 1 << endl;
	cout.flush();
	int lca;
	cin >> lca;
	if (lca == -1)
	{
		assert(1 == 0);
	}
	return lca-1;
}

int main(void)
{
	
	int n; cin >> n;


	for (int i(1); i < n; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	vector<bool> in_graph(n, true);

	while (1)
	{
		vector<int> leaves;
		for (int i(0); i< n; ++i)
			if (in_graph[i])
			{
				int d(0);
				for (auto v : G[i])
					if (in_graph[v])
						d++;
				if (d<=1)
					leaves.push_back(i);
			}
		if (SZ(leaves) == 1)
		{
			cout << "! " << 1+leaves[0] << endl;
			cout.flush();
			return 0;
		}

		int u = leaves[0], v = leaves[1];
		int lca = ask(u,v);
		if (lca == u or lca == v)
		{
			cout << "! " << lca + 1 << endl;
			return 0;
		}
		in_graph[u] = in_graph[v] = false;
	}
}
#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

const int MAXN = 3e5;
const ll MOD = 998244353;

vector<int> G[MAXN];
bool visited[MAXN];

ll ways[MAXN][3];

void solve(int u, int p)
{
	assert(visited[u] == false);
	visited[u] = true;
	ways[u][0] = ways[u][1] = ways[u][2] = 1;
	for (auto v : G[u])
		if (v != p)
		{
			solve(v, u);
			ways[u][0] *= 2 * (ways[v][0] + ways[v][1]) - ways[v][2];
			ways[u][1] *= 2*ways[v][0] + ways[v][1] - ways[v][2];
			ways[u][2] *= ways[v][0] + ways[v][1] - ways[v][2];
			for (int k(0); k < 3; ++k)
				ways[u][k] %= MOD;
		}
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	for (int i(1); i < n; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	solve(0,0);

	cout << (ways[0][0] + ways[0][1] - ways[0][2]-1+2*MOD)%MOD << endl;
}
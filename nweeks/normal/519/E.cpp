#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
const int MAXK = 19;

vector<int> G[MAXN];
int parent[MAXK][MAXN];
int subtree_size[MAXN];
int depth[MAXN];
int N;

void buildtree(int u, int p, int d)
{
	parent[0][u] = p;
	depth[u] = d;
	subtree_size[u] = 1;
	for (auto v : G[u])
		if (v != p)
		{
			buildtree(v, u, d+1);
			subtree_size[u] += subtree_size[v];
		}
}

inline void walk_up(int &p, int dis)
{
	for (int k(0); k < MAXK; ++k)
		if (dis & (1<<k))
			p = parent[k][p];
}

inline int lca_querry(int p, int q)
{
	if (depth[p] < depth[q]) swap(p,q);
	walk_up(p, depth[p] - depth[q]);
	if (p == q) return p;
	for (int k(MAXK-1); k >= 0; --k)
		if (depth[p] - (1<<k) >= 0 and parent[k][p] != parent[k][q])
		{
			p = parent[k][p];
			q = parent[k][q];
		}
	return parent[0][p];
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	for (int i(1); i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		G[u-1].push_back(v-1);
		G[v-1].push_back(u-1);
	}

	buildtree(0,0,0);
	for (int k(1); (1<<k) <= N; ++k)
		for (int i(0); i < N; ++i)
			if (depth[i] - (1<<k) >= 0)
				parent[k][i] = parent[k-1][parent[k-1][i]];

	int Q; cin >> Q;
	while (Q--)
	{
		int A, B;
		cin >> A >> B;
		A--, B--;
		if (A == B)
		{
			cout << N << '\n';
			continue;
		}
		if (depth[A] < depth[B]) swap(A, B);
		int lca = lca_querry(A, B);
		int distance = depth[A] + depth[B] - 2 * depth[lca];
		if (distance % 2 == 1)
		{
			cout << 0 << '\n';
			continue ;
		}
		int middle = A;
		walk_up(middle, distance/2 - 1);
		int prev1 = middle;
		int prev2 = B;
		walk_up(prev2, depth[B] - depth[lca] - 1);
		middle = parent[0][middle];

		int ans(subtree_size[middle]);
		if (middle == lca)
			ans += N - ans;
		ans -= subtree_size[prev1];
		if (parent[0][prev2] == middle)
			ans -= subtree_size[prev2];

		/*int ans(1);
		for (auto v : G[middle])
			if (!(middle != lca and v == parent[0][middle]) and v != prev1 and v != prev2)
			{
				if (v == parent[0][middle])
					ans += subtree_size[0] - subtree_size[middle];
				else
					ans += subtree_size[v];
			}*/
		cout << ans << '\n';
	}
	fflush(stdout);
}
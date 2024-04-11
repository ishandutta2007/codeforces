#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
const int MAXK = 20;
const int MAXA = 10;

vector<int> G[MAXN];
int par[MAXK][MAXN];
int depth[MAXN];
int people[MAXN][10];
int met[MAXK][MAXN][10];
int cpy[10];
int ans[10];

int N, M, Q;
inline void update(int (&to_update)[10], int (&ids)[10], int a)
{
	fill(cpy, cpy+MAXA, 1e9);

	int p1(0), p2(0);
	for (int i(0); i < a; ++i)
	{
		if (to_update[p1] == ids[p2])
		{
			cpy[i] = to_update[p1++];
			++p2;	
		}
		else if (to_update[p1] < ids[p2])
			cpy[i] = to_update[p1++];
		else
			cpy[i] = ids[p2++];
	}
	for (int i(0); i < MAXA; ++i)
		to_update[i] = cpy[i];
}

void read_input(void)
{
	for (int i(0); i < MAXK; ++i)
		for (int j(0); j < MAXN; ++j)
			for (int k(0); k < MAXA; ++k)
				people[j][k] = met[i][j][k] = 1e9;

	cin >> N >> M >> Q;

	for (int i(1); i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int a[10];
	fill(a, a + 10, (int)1e9);
	for (int i(1); i <= M; ++i)
	{
		a[0] = i;
		int node; cin >> node;
		update(people[node-1], a, MAXA);
	}
}

void build_graph(int u, int p, int d)
{
	depth[u] = d;
	for (auto v : G[u])
		if (v != p)
		{
			par[0][v] = u;
			update(met[0][v], people[u], MAXA);
			build_graph(v, u, d + 1);
		}
}

void build_sparse(void)
{
	for (int k(1); k < MAXK; ++k)
		for (int i(0); i < MAXN; ++i)
			if (depth[i] >= (1<<k))
			{
				par[k][i] = par[k-1][par[k-1][i]];
				update(met[k][i], met[k-1][i], MAXA);
				update(met[k][i], met[k-1][par[k-1][i]], MAXA);
			}
}

void get(int u, int v, int a)
{
	fill(ans, ans + 10, 1e9);
	update(ans, people[u], a);
	update(ans, people[v], a);

	if (depth[u] < depth[v])
		swap(u, v);
	int walk = depth[u] - depth[v];
	for (int k(0); k < MAXK; ++k)
		if (walk&(1<<k))
		{
			update(ans, met[k][u], a);
			u = par[k][u];
		}
	if (u == v)
		return ;
	for (int k(MAXK-1); k >= 0; --k)
		if ((1<<k) <= depth[u] and par[k][u] != par[k][v])
		{
			update(ans, met[k][u], a);
			update(ans, met[k][v], a);
			u = par[k][u];
			v = par[k][v];
		}
	update(ans, met[0][u], a);
	update(ans, met[0][v], a);
	return ;
}

void solve(void)
{
	int u, v, a;
	cin >> u >> v >> a;
	u--, v--;
	get(u, v, a);
	int cnt(0);
	for (int i(0); i < a; ++i)
		cnt += ans[i] != 1e9;
	cnt = min(a, cnt);
	cout << cnt << ' ';
	for (int i(0); i < cnt; ++i)
		cout << ans[i] << ' ';
	cout << '\n';
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	read_input();
	build_graph(0,0, 0);
	build_sparse();
	for (int i(0); i < Q; ++i)
		solve();
}
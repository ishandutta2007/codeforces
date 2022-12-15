#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

const int MAXN = 4e5;
const int MAXP = 21;

int id[MAXN];
vector<int> G[MAXN];
int par[MAXP][MAXN];
int reach[MAXN];
int depth[MAXN];
int dis[MAXN];

vector<int> special;

int n, r, k;
int N;

int find(int i)
{
	if (id[i] < 0)
		return i;
	return id[i] = find(id[i]);
}

void merge(int a, int b)
{
	//cout << "HEY"<<endl;
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (-id[a] < -id[b]) swap(a,b);
	id[a]+=id[b];
	id[b]=a;
}

void bfs1(void)
{
	queue<int> Q;
	for (int i(0); i < N; ++i)
		dis[i] = 1e9;
	for (auto u : special)
	{
		dis[u] = 0;
		reach[u] = u;
		Q.push(u);
	}
	while (!Q.empty())
	{
		int u= Q.front(); Q.pop();
		//cout << u + 1 << ' ' << dis[u] << endl;
		if (dis[u] >= k) continue;

		for (auto v : G[u])
		{
			if (dis[u]+1 < dis[v])
			{
				Q.push(v);
				dis[v] = dis[u]+1;
				reach[v] = reach[u];
			}
			if (dis[u] + dis[v] + 1 <= 2*k)
				merge(reach[u], reach[v]);
		}
	}
}

void dfs(int u, int p, int d)
{
	par[0][u] = p;
	depth[u] = d;
	for (auto v : G[u])
		if (v != p)
			dfs(v,u,d+1);
}

void precomp(void)
{
	for (int p(1); p < MAXP; ++p)
		for (int i(0); i < N; ++i)
			par[p][i] = par[p-1][ par[p-1][i] ];
}

int go_up(int u, int d)
{
	for (int p(0); p < MAXP; ++p)
		if ((1<<p) & d)
			u = par[p][u];
	return u;
}

int lca(int u, int v)
{
	if (depth[u] < depth[v])
		swap(u,v);
	int diff = depth[u] - depth[v];
	u = go_up(u, diff);

	if (u == v)
		return u;
	for (int p(MAXP-1); p >= 0; --p)
		if (par[p][u] != par[p][v])
		{
			u = par[p][u];
			v = par[p][v];
		}
	u = par[0][u];
	return u;
}

int calc_dis(int u, int v)
{
	int p = lca(u,v);
	return depth[u] + depth[v] - 2 * depth[p];
}

pair<int, int> move_k(int u, int v)
{
	int p = lca(u,v);

	int diff_u = depth[u] - depth[p];
	int diff_v = depth[v] - depth[p];
	int needed = k;
	int uu, vv;
	if (diff_u < needed)
		uu = go_up(v, diff_v - (needed - diff_u));
	else
		uu = go_up(u, needed);
	if (diff_v < needed)
		vv = go_up(u, diff_u - (needed - diff_v));
	else
		vv = go_up(v, needed);
	return make_pair(uu,vv);
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k >> r;
	N = n;
	for (int i(1); i < n; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u,--v;
		G[u].push_back(N);
		G[N].push_back(u);
		G[v].push_back(N);
		G[N].push_back(v);
		++N;
	}
	for (int i(0); i < N; ++i)
		reach[i]=-1, id[i] = -1;
	special.resize(r);
	for (auto &v : special) 
	{
		cin >> v; 
		v--;
	}

	bfs1();
	for (int i(0); i < N; ++i)
		if (reach[i] != -1)
			reach[i] = find(reach[i]);
	/*for (int i(0); i < N; ++i)
		cout << reach[i] << ' ';
	cout << endl;*/
	dfs(0,0,0);
	precomp();
	
	int q;
	cin >> q;
	while (q--)
	{
		int u, v;
		cin >> u >> v;
		//cout << "PROCESSING QUERY : " << u << ' ' << v << endl;
		--u, --v;
		int dis_uv = calc_dis(u,v);
		//cout << "DISTANCE : " << dis_uv << endl;
		if (dis_uv <= 2*k)
			cout << "YES" << '\n';
		else
		{
			auto p = move_k(u,v);
			//cout << p.first << ' ' << p.second << endl;
			if (reach[p.first] == reach[p.second] and reach[p.first] != -1)
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}
}
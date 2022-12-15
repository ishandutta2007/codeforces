#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

const int MAXN = 1e5;
const int MAXP = 21;

int par[MAXP][MAXN];
int depth[MAXN];

vector<int> G[MAXN];
bool visited[MAXN];

int n;

void dfs(int u, int p, int d)
{
	par[0][u] = p;
	depth[u] = d;
	for (auto v : G[u])
		if (v != p)
			dfs(v,u,d+1);
}

void calc_par(void)
{
	for (int p(1); p < MAXP; ++p)
		for (int i(0); i < n; ++i)
			par[p][i] = par[p-1][ par[p-1][i] ];
}

int calc_dis(int u, int v)
{
	int dis(0);

	if (depth[v] > depth[u])
		swap(u,v);
	int uu(u), vv(v);
	int diff = depth[u] - depth[v];
	dis+=diff;
	for (int p(MAXP-1); p >= 0; --p)
		if ((1<<p) & diff)
			u = par[p][u];
	
	for (int p(MAXP-1); p >= 0; --p)
	{
		if ((1<<p) <= min(depth[u], depth[v]) and par[p][u] != par[p][v])
		{
			dis += (1<<(p+1));
			u = par[p][u];
			v = par[p][v];
		}
	}
	if (u != v)
	{
		dis+=2;
		u = par[0][u], v = par[0][v];
	}

	assert(dis == (depth[uu] - depth[u] + depth[vv] - depth[u]));

	return dis;
}


bool can(int dis, int k)
{
	return dis <= k and (k-dis)%2==0;
}

void process_query(void)
{
	int x, y, u, v, k;
	cin >> x >> y >> u >> v >> k;
	
	--x, --y, --u, --v;
	
	int dis_uy = calc_dis(u,y);
	int dis_ux = calc_dis(u,x);
	int dis_uv = calc_dis(u,v);
	int dis_vx = calc_dis(v,x);
	int dis_vy = calc_dis(v,y);

	int dis1 = dis_uv;
	int dis2 = 1 + dis_ux + dis_vy;
	int dis3 = 1 + dis_uy + dis_vx;
	if ( can(dis1,k) or can(dis2,k) or can(dis3,k))
		cout<<"YES\n";
	else
		cout<<"NO\n";
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i(0); i < n-1; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u,--v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs(0,0,0);
	calc_par();
	int q;
	cin >> q;
	while (q--)
		process_query();
}
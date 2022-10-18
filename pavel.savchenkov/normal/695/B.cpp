#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define sz(c) ((int) (c).size())
#define mp(x, y) make_pair(x, y)
#define prev prev___________________
#define hash hash___________________
#define pb push_back

#define FILE_NAME ""

struct edge
{
	int to;
	int cost;
	int id;
};

typedef vector<vector<edge>> g_type;

void dfs (int x, const g_type &g, vector<char> &used, vi &par)
{
	used[x] = 1;
	for (const auto &e : g[x])
	if (!used[e.to])
	{
		par[e.to] = e.id;
		dfs(e.to, g, used, par);
	}
}

void dfs_calc (int x, const g_type &g, vector<char> &used, vi &par,
				vi &h, vi &jump)
{
	used[x] = 1;
	jump[x] = h[x];
	for (const auto &e : g[x])
	if (!used[e.to])
	{
		par[e.to] = e.id;
		h[e.to] = h[x] + 1;
		dfs_calc(e.to, g, used, par, h, jump);
		jump[x] = min(jump[e.to], jump[x]);
	}

	for (const auto &e : g[x])
	if (e.id != par[x])
		jump[x] = min(jump[x], h[e.to]);
}

const int inf = (int)2e9 + 10;

void solve (int n)
{
	int m; cin >> m;
	int s, t;
	cin >> s >> t;
	--s, --t;

	g_type g(n);
	vi u(m), w(m), v(m);

	for (int i = 0; i < m; i++)
	{
		cin >> u[i] >> v[i] >> w[i];
		--u[i], --v[i];
		g[u[i]].pb(edge{v[i], w[i], i});
		g[v[i]].pb(edge{u[i], w[i], i});
	}

	vector<char> used(n);
	vi par_edge(n, -1);
	dfs(s, g, used, par_edge);
	if (!used[t])
	{
		cout << 0 << endl;
		cout << 0 << endl;
		return;
	}

	int ans = inf;
	vi res;

	auto try_del = [&] (int cure) -> void
	{
		assert(0 <= cure && cure < m);
		int cnt = 0;

		for (int i = 0; i < n; i++)
		for (int j = 0; j < sz(g[i]); j++)
		if (g[i][j].id == cure)
		{
			 cnt++;
			 g[i].erase(g[i].begin() + j);
		}

		assert(cnt == 2);
    int cur_cost = w[cure];
    used.assign(n, 0);
    vi npar_edge(n, -1);
    dfs(s, g, used, npar_edge);
    if (!used[t])
    {
    	vi curt = {cure};
    	if (cur_cost < ans)
    	{
    		ans = cur_cost;
    		res = curt;
    	}
    	g[u[cure]].pb(edge{v[cure], w[cure], cure});
		g[v[cure]].pb(edge{u[cure], w[cure], cure});

    	return;
    }

    used.assign(n, 0);
    vi h(n), jump(n, inf);
    npar_edge.assign(n, -1);
    dfs_calc(s, g, used, npar_edge, h, jump);

    for (int x = t; x != s; )
    {
    	assert(npar_edge[x] != -1);

		  if (jump[x] == h[x])
		  {
		  	vi curt = {cure, npar_edge[x]};
		  	cur_cost = w[cure] + w[npar_edge[x]];
		  	if (cur_cost < ans)
		  	{
		  		ans = cur_cost;
		  		res = curt;
		  	}
		  }

		  int ut = u[npar_edge[x]], vt = v[npar_edge[x]];
	  	if (ut != x)
		  	swap(ut, vt);
		  assert(ut == x && vt != x);
		  x = vt;
    }

		g[u[cure]].pb(edge{v[cure], w[cure], cure});
		g[v[cure]].pb(edge{u[cure], w[cure], cure});
	};

 // cerr << "t = " << t << endl;
 // cerr << "s = " << s << endl;
	for (int x = t; x != s; )
	{
		//cerr << x << " ";

		assert(par_edge[x] != -1);
		int cure = par_edge[x];

		try_del(cure);

		int ut = u[par_edge[x]], vt = v[par_edge[x]];
		if (ut != x)
			swap(ut, vt);
		assert(ut == x && vt != x);
		x = vt;
	}
//	cerr << endl;

  if (ans == inf)
  	cout << -1 << endl;
  else
  {
    cout << ans << endl;
  	cout << sz(res) << endl;
  	for (int id : res)
  		cout << id + 1 << ' ';
  	cout << endl;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen(FILE_NAME ".in", "r", stdin);
	freopen(FILE_NAME ".out", "w", stdout);
#endif

	int n;
	while (cin >> n)
		solve(n);

#ifdef LOCAL
	cerr << "Time: " << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}
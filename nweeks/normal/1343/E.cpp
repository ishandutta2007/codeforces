#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())
#define FOR(i, j, n) for (int i(j); i < (n); ++i)
#define FORR(v, c) for (auto &v : (c))
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define pnl(x) cout << x << '\n'
#define pns(x) cout << x << ' '

typedef	long long ll;

int solve(int testcase);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int __t(1);
	cin >> __t;
	for (int _t(1); _t <= __t; _t++)
		solve(_t);
}

vector<vector<int>> G;
vector<ll> dis[3];
vector<ll> weight;
int nb_sommets, nb_aretes;
int nodes[3];

void bfs(int from)
{
	FOR(i,0, nb_sommets)
		dis[from][i]=-1;
	dis[from][nodes[from]]=0;

	queue<int> Q;
	Q.push(nodes[from]);
	while (SZ(Q))
	{
		int u = Q.front(); Q.pop();
		FORR(v, G[u])
			if (dis[from][v]==-1)
			{
				Q.push(v);
				dis[from][v] = dis[from][u]+1;
			}
	}
}

int solve(int testcase)
{
	G.clear();
	FOR(i,0,3) dis[i].clear();
	weight.clear();
	cin >> nb_sommets >> nb_aretes;
	FOR(i,0, 3) cin >> nodes[i];
	FOR(i,0, 3) --nodes[i];
	G.resize(nb_sommets);
	weight.resize(nb_aretes);
	FOR(i,0,3) dis[i].resize(nb_sommets);
	FOR(i,0,nb_aretes)
		cin >> weight[i];
	sort(all(weight));
	FOR(i,1, nb_aretes)
		weight[i]+=weight[i-1];
	FOR(i,0, nb_aretes)
	{
		int u, v;
		cin >>u>>v;
		--u,--v;
		G[u].pb(v);
		G[v].pb(u);
	}
	FOR(i,0,3) bfs(i);
	if (nodes[0]==nodes[1] and nodes[1]==nodes[2])
	{
		pnl(0);
		return 0;
	}
	ll ans = 1e18;
	FOR(middle, 0, nb_sommets)
	{
		int tot_dis = 0;
		FOR(i,0,3) tot_dis+=dis[i][middle];
		if (tot_dis > nb_aretes) continue;
		ans = min(ans, (dis[1][middle] ? weight[dis[1][middle]-1]:0) + weight[tot_dis-1]);
	}
	pnl(ans);
	return testcase;
}
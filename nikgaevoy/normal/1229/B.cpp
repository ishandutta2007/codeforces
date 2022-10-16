#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


const int mod = 1e9 + 7;

template<class T>
T sqr(T x)
{
	return x * x;
}


ll powmod(ll x, int y)
{
	return y ? (y & 1 ? x * powmod(x, y - 1) : sqr(powmod(x, y / 2))) % mod : 1;
}


ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}


void dfs(vector<vector<int>> &gr, int v)
{
	for (auto it : gr[v])
	{
		gr[it].erase(find(gr[it].begin(), gr[it].end(), v));

		dfs(gr, it);
	}
}


void build(const vector<vector<int>> &gr, const vector<ll> &x, vector<vector<pair<int, ll>>> &bup, int v)
{
	if (!bup[v].empty())
	{
		while (bup[bup[v].back().first].size() >= bup[v].size())
		{
			int p = bup[bup[v].back().first][bup[v].size() - 1].first;
			ll g = gcd(bup[bup[v].back().first][bup[v].size() - 1].second, bup[v].back().second);

			bup[v].emplace_back(p, g);
		}
	}

	for (auto it : gr[v])
	{
		bup[it] = {{v, x[it]}};

		build(gr, x, bup, it);
	}
}


ll foo(const vector<vector<int>> &gr, const vector<ll> &x, const vector<vector<pair<int, ll>>> &bup, int v, ll g = 0)
{
	if (v == 0)
		return gcd(x[v], g);

	int nxt = 0;

	auto ng = gcd(x[v], g);

	while (nxt < bup[v].size() && gcd(bup[v][nxt].second, g) == ng)
		nxt++;
	nxt--;

	return (foo(gr, x, bup, bup[v][nxt].first, ng) + (ng % mod) * powmod(2, nxt)) % mod;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<ll> x(n);

	for (auto &it : x)
		cin >> it;

	vector<vector<int>> gr(n);

	for (int i = 1; i < n; i++)
	{
		int a, b;

		cin >> a >> b;
		a--;
		b--;

		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	dfs(gr, 0);

	vector<vector<pair<int, ll>>> bup(n);

	build(gr, x, bup, 0);

	ll ans = 0;

	for (int i = 0; i < n; i++)
		ans += foo(gr, x, bup, i);

	cout << ans % mod << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}
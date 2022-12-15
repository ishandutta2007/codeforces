#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;

using ll = long long;

template<typename... Args>
void read(Args&... args)
{
	((cin >> args), ...);
}
template<typename T>
void read(vector<T> &vec)
{
	for (auto &v : vec) read(v);
}

void write() {}
template<typename H, typename... T>
void write(const H &h, const T&... t)
{
	cout << h;
	if (sizeof...(t)) {cout << ' '; write(t...);}
}

template<typename T>
void write(const vector<T> &vec)
{
	if (SZ(vec) == 0) return;
	write(vec[0]);
	for (int i(1); i < SZ(vec); ++i)
	{cout << ' '; write(vec[i]);}
}

template<typename... Args>
void writeln(Args... args)
{
	write(args...); cout << '\n';
}

template<class Fun>
class y_combinator_result {
	Fun fun_;
	public:
	template<class T>
		explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
		decltype(auto) operator()(Args &&...args) {
			return fun_(std::ref(*this), std::forward<Args>(args)...);
		}
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

ll solve()
{
	int nbSommets;
	read(nbSommets);
	vector<vector<int>> g(nbSommets);
	vector<int> par(nbSommets);
	vector<ll> val(nbSommets);
	vector<ll> dp(nbSommets);
	vector<vector<int>> atDepth;
	for (int i(1); i < nbSommets; ++i)
	{
		int v;
		read(v);
		--v;
		g[v].push_back(i);
		g[i].push_back(v);
	}

	auto dfs = y_combinator([&](auto dfs, int u, int p, int d) -> void
			{
				if (d == SZ(atDepth))
					atDepth.push_back({});
				par[u] = p;
				atDepth[d].push_back(u);
				for (auto v : g[u])
					if (v != p)
						dfs(v, u, d+1);
			});

	dfs(0, 0, 0);
	for (int i(1); i < nbSommets; ++i)
		read(val[i]);
	for (int i(1); i < SZ(atDepth); ++i)
		sort(atDepth[i].begin(), atDepth[i].end(),
				[&](int u, int v)
				{
					if (val[u] == val[v]) return u < v;
					return val[u] < val[v];
				});
	for (int d(1); d < SZ(atDepth); ++d)
	{
		int nbElem(SZ(atDepth[d]));
		vector<ll> lft(nbElem), rgt(nbElem);
		for (int i(0); i < nbElem; ++i)
		{
			int u = atDepth[d][i];
			lft[i] = dp[par[u]] - val[u];
			rgt[i] = dp[par[u]] + val[u];
		}
		for (int i(1); i < nbElem; ++i)
			lft[i] = max(lft[i], lft[i-1]);
		for (int i(nbElem-2); i >= 0; --i)
			rgt[i] = max(rgt[i], rgt[i+1]);
		for (int i(0); i < nbElem; ++i)
		{
			int u = atDepth[d][i];
			dp[u] = dp[par[u]] + max(val[u] - val[atDepth[d][0]],
					val[atDepth[d].back()] - val[u]);
			dp[u] = max({dp[u], lft[i] + val[u],  rgt[i] - val[u]});
		}
	}
	ll ans(0);
	for (auto v : atDepth.back())
		ans = max(ans, dp[v]);
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	read(t);
	while (t--)
		writeln(solve());
}
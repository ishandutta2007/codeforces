#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define pow2(x) (1ll << (x))

vector<vector<ll>> compute(int m, ll l, ll r) {
	if (l > r) {
		swap(l, r);
	}
	vector<vector<ll>> results(m + 1);
	std::function<void(int, ll)> dfs = [&](int bits, ll val) {
		ll z = val + pow2(bits + 1) - 1;
		if (z < l || val > r) {
			return;
		}
		if (val >= l && z <= r) {
			results[m - (bits + 1)].push_back(val);
			return;
		}
		dfs(bits - 1, val);
		dfs(bits - 1, val | pow2(bits));
	};
	dfs(m - 1, 0);
	return results;
}

const int MAXN = 53;

void compute2(int m, const vector<vector<ll>>& states, pair<int, int> g[MAXN][2][MAXN]) {
	map<ll, pair<int, int>> hmap[MAXN];
	for (int l = 0; l <= m; ++l) hmap[l].clear();
	for (int l = 0; l <= m; ++l) {
		for (int d = 0; d < states[l].size(); ++d) {
			for (int new_l = 0; new_l < l; ++new_l) {
				ll state = (states[l][d] >> (m - new_l));
				if (hmap[new_l].count(state)) {
					g[l][d][new_l] = hmap[new_l][state];
				}
				else {
					g[l][d][new_l] = make_pair(-1, -1);
					hmap[new_l][state] = make_pair(l, d);
				}
			}
		}
	}
}

int n;
int m;
int idx[MAXN][MAXN];
vector<vector<ll>> states[MAXN];
pair<int, int> g_state[MAXN][MAXN][2][MAXN];
ll cost[MAXN];
ll f[MAXN][MAXN][MAXN][MAXN][2][2];

ll dp(int s, int ls, int ds, int t, int lt, int dt) {
	int l = min(ls, lt);
	ll& ret = f[s + 1][t + 1][ls][lt][ds][dt];
	assert(ret < 0);
	if (s >= 0 && ls > l&& g_state[s][ls][ds][l].first >= 0) {
		const auto& w = g_state[s][ls][ds][l];
		return ret = f[s + 1][t + 1][w.first][lt][w.second][dt];
	}
	if (t < n && lt > l&& g_state[t][lt][dt][l].first >= 0) {
		const auto& w = g_state[t][lt][dt][l];
		return ret = f[s + 1][t + 1][ls][w.first][ds][w.second];
	}
	ll state = 0;
	if (s >= 0 && t < n) {
		state = (states[s][ls][ds] ^ states[t][lt][dt]);
	}
	if (s + 1 == t) {
		if (state == 0) {
			return ret = 0;
		}
		ret = 0;
		for (int i = m - l; i < m; ++i) {
			if (state & pow2(i)) {
				ret += cost[i];
			}
		}
		return ret;
	}
	ret = pow2(58);
	ll cost0 = 0;
	for (int i = 1; i <= l; ++i) {
		if (state & pow2(m - i)) {
			cost0 += cost[m - i];
		}
	}
	for (int lk = 0; lk <= l; ++lk) {
		if (lk > 0 && (state & pow2(m - lk))) {
			cost0 -= cost[m - lk];
		}
		for (int k = s + 1; k < t; ++k) {
			for (int dk = 0; dk < states[k][lk].size(); ++dk) {
				ret = min(ret, f[s + 1][k + 1][ls][lk][ds][dk] + f[k + 1][t + 1][lk][lt][dk][dt] + cost0);
			}
		}
	}
	return ret;
}

ll solve_one_case() {
	cin >> m;
	for (int i = 0; i < n; ++i) {
		ll l, r;
		cin >> l >> r;
		states[i] = compute(m, l, r);
		compute2(m, states[i], g_state[i]);
	}
	for (int i = 0; i < m; ++i) {
		cin >> cost[i];
	}

	memset(f, 255, sizeof(f));
	for (int s = n; s >= -1; --s) {
		for (int t = s + 1; t <= n; ++t) {
			for (int ls = 0; ls <= m; ++ls) {
				for (int lt = 0; lt <= m; ++lt) {
					vector<ll> state_s;
					if (s >= 0) {
						state_s = states[s][ls];
					}
					else {
						if (ls == m) state_s = { 0 };
					}
					vector<ll> state_t;
					if (t < n) {
						state_t = states[t][lt];
					}
					else {
						if (lt == m) state_t = { 0 };
					}
					for (int ds = 0; ds < state_s.size(); ++ds) {
						for (int dt = 0; dt < state_t.size(); ++dt) {
							dp(s, ls, ds, t, lt, dt);
						}
					}
				}
			}
		}
	}
	return f[0][n + 1][m][m][0][0];
}

int main()
{
#ifdef _MSC_VER
	freopen("e.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	while (cin >> n) cout << solve_one_case() << endl;
	return 0;
}
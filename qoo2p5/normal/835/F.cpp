#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

const int N = (int) 2e5 + 2;
const long long INF = (long long) 1e18 + 123;

int n;
vector<pair<int, int>> g[N];
vector<int> cycle;
int color[N];
bool vis[N];
long long depth[N], weight[N];
long long pref_diam[N], suff_diam[N];
long long pref_far[N], suff_far[N];

int dfs(int v, int from = -1) {
	static int cycle_start = -1;
	color[v] = 1;
	for (auto &e : g[v]) {
		int u = e.first;
		if (u == from) {
			continue;
		}
		
		if (color[u] == 1) {
			cycle.push_back(v);
			cycle_start = u;
			return 1;
		} else if (color[u] == 0) {
			int res = dfs(u, v);
			if (res == -1) {
				return -1;
			}
			if (res == 1) {
				cycle.push_back(v);
				if (v == cycle_start) {
					return -1;
				}
				return 1;
			}
		}
	}
	color[v] = 2;
	return 0;
}

pair<long long, int> farest(int v, pair<int, int> deny = {-1, -1}) {
	pair<long long, int> ans = {0, v};
	vis[v] = 1;
	for (auto &e : g[v]) {
		int u = e.first;
		if (deny == make_pair(u, v) || deny == make_pair(v, u) || vis[u]) {
			continue;
		}
		
        auto tmp = farest(u, deny);
        tmp.first += e.second;
		ans = max(ans, tmp);
	}
	return ans;
}

long long get_diam(pair<int, int> deny) {
    fill(vis, vis + n + 1, 0);
    auto tmp = farest(1, deny);
    fill(vis, vis + n + 1, 0);
    return farest(tmp.second, deny).first;
}

int main() {
    scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
		g[u].push_back({v, l});
		g[v].push_back({u, l});
	}
	
	dfs(1);
	int k = (int) cycle.size();
	assert(k >= 3);
	
	for (int v : cycle) {
		vis[v] = 1;
	}
	for (int i = 0; i < k; i++) {
		depth[i] = farest(cycle[i]).first;
	}
    cycle.push_back(cycle[0]);
	for (int i = 0; i < k; i++) {
		int v = cycle[i];
		int u = cycle[i + 1];
		for (auto &e : g[v]) {
			if (e.first == u) {
				weight[i] = e.second;
			}
		}
	}
    
    pref_diam[0] = depth[0];
    pref_far[0] = depth[0];
    long long cur_len = 0;
    long long cur_far = -INF;
    for (int i = 1; i < k; i++) {
        cur_len += weight[i - 1];
        cur_far = max(cur_far, depth[i - 1]) + weight[i - 1];
        assert(cur_far >= 0);
        pref_far[i] = max(pref_far[i - 1], cur_len + depth[i]);
        pref_diam[i] = max(pref_diam[i - 1], cur_far + depth[i]);
    }
    
    suff_diam[k] = -INF;
    suff_far[k] = -INF;
    cur_len = 0;
    cur_far = -INF;
    for (int i = k - 1; i > 0; i--) {
        cur_len += weight[i];
        cur_far = max(cur_far, depth[i + 1]) + weight[i];
        assert(cur_far >= 0);
        suff_far[i] = max(suff_far[i + 1], cur_len + depth[i]);
        suff_diam[i] = max(suff_diam[i + 1], cur_far + depth[i]);
    }
    
    pair<long long, int> ans = {INF, -1};
    
    for (int i = 0; i < k; i++) {
        long long cur = max(pref_far[i] + suff_far[i + 1], max(pref_diam[i], suff_diam[i + 1]));
        if (cur < ans.first) {
            ans = {cur, i};
        }
    }
    
    assert(ans.second != -1);
	cout << get_diam({cycle[ans.second], cycle[ans.second + 1]}) << "\n";
	
	return 0;
}
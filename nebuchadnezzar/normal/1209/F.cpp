// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

const int MOD = 1000000007;

const int bp = 22;

struct node {
	vector<int> go;
	int val, depth;
	vector<int> binup;
	int p, pd;
	node() : go(10, -1), val(0), depth(0), binup(bp), p(0), pd(-1) {}
};

vector<node> trie;

int add_node(int p, int d) {
	int v = szof(trie);
	trie.push_back(node());
	trie[v].val = ((ll) trie[p].val * 10 + d) % MOD;
	trie[v].depth = trie[p].depth + 1;
	trie[v].binup[0] = p;
	trie[v].p = p;
	trie[v].pd = d;
	for (int i = 1; i < bp; ++i) {
		trie[v].binup[i] = trie[trie[v].binup[i - 1]].binup[i - 1];
	}
	return v;
}

struct path_weight {
	int node_ind;

	path_weight(int _node_ind) : node_ind(_node_ind) {}

	bool operator<(path_weight const& other) const {
		if (node_ind == -1) {
			return false;
		}
		if (other.node_ind == -1) {
			return true;
		}
		int a = node_ind;
		int b = other.node_ind;
		if (trie[a].depth != trie[b].depth) {
			return trie[a].depth < trie[b].depth;
		}
		if (a == b) {
			return false;
		}
		for (int i = bp - 1; i >= 0; --i) {
			if (trie[a].binup[i] != trie[b].binup[i]) {
				a = trie[a].binup[i];
				b = trie[b].binup[i];
			}
		}
		return trie[a].pd < trie[b].pd;
	}

	void add(int d) {
		if (trie[node_ind].go[d] == -1) {
			trie[node_ind].go[d] = add_node(node_ind, d);
		}
		node_ind = trie[node_ind].go[d];
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<pii>> graph(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back({b, i + 1});
		graph[b].push_back({a, i + 1});
	}

	vector<path_weight> dist(n, path_weight(-1));
	trie.push_back(node());
	dist[0] = path_weight(0);
	set<pair<path_weight, int>> st;
	st.insert({dist[0], 0});
	vector<int> ans(n);
	vector<int> digits;
	while (szof(st)) {
		int v = st.begin()->ss;
		st.erase(st.begin());
		// cerr << v + 1 << " " << dist[v].node_ind << endl;
		ans[v] = trie[dist[v].node_ind].val;
		for (auto to : graph[v]) {
			digits.clear();
			int tmp = to.ss;
			while (tmp) {
				digits.push_back(tmp % 10);
				tmp /= 10;
			}
			reverse(digits.begin(), digits.end());
			auto new_weight = dist[v];
			for (int d : digits) {
				new_weight.add(d);
			}
			if (new_weight < dist[to.ff]) {
				st.erase({dist[to.ff], to.ff});
				dist[to.ff] = new_weight;
				st.insert({dist[to.ff], to.ff});
			}
		}
	}

	for (int i = 1; i < n; ++i) {
		cout << ans[i] << "\n";
	}
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}
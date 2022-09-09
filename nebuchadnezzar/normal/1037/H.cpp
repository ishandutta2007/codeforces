#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#  define _GLIBCXX_DEBUG_PEDANTIC
#endif

#include "bits/stdc++.h"
#define ff first
#define ss second
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

struct node {
	vector<int> go;
	int link, len;
	node() : go(26, -1), link(-1), len(0) {}
	node(node const& other) : go(other.go), link(other.link), len(other.len) {}
};

void solve() {
	vector<node> automaton;
	automaton.push_back(node());
	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<vector<tuple<int, int, string>>> here(szof(s));
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		--l; --r;
		string w;
		cin >> w;
		here[r].push_back(make_tuple(i, l, w));
	}

	vector<int> nodes;
	int last = 0;
	for (int i = 0; i < szof(s); ++i) {
		int c = s[i] - 'a';
		int next = szof(automaton);
		nodes.push_back(next);
		automaton.push_back(node());
		automaton[next].len = automaton[last].len + 1;
		while (last != -1) {
			if (automaton[last].go[c] != -1) {
				break;
			}
			automaton[last].go[c] = next;
			last = automaton[last].link;
		}

		if (last != -1) {
			int prev = automaton[last].go[c];
			if (automaton[prev].len == automaton[last].len + 1) {
				automaton[next].link = prev;
			} else {
				automaton.push_back(automaton[prev]);
				int newv = szof(automaton) - 1;
				automaton[newv].len = automaton[last].len + 1;
				automaton[prev].link = newv;
				automaton[next].link = newv;
				while (last != -1 && automaton[last].go[c] == prev) {
					automaton[last].go[c] = newv;
					last = automaton[last].link;
				}
			}
		} else {
			automaton[next].link = 0;
		}

		last = next;
	}

	vector<vector<int>> graph(szof(automaton));
	for (int i = 1; i < szof(automaton); ++i) {
		graph[automaton[i].link].push_back(i);
		//cerr << i << " " << automaton[i].link << endl;
	}

	vector<int> tin(szof(automaton)), tout(szof(automaton));

	int tcounter = 0;
	function<void(int)> dfs = [&](int v) {
		tin[v] = tcounter++;
		for (int to : graph[v]) {
			dfs(to);
		}
		tout[v] = tcounter;
	};

	dfs(0);

	int bpv = 1;
	while (bpv < tcounter) {
		bpv *= 2;
	}

	vector<int> rmq(bpv * 2, -1);

	auto rmq_set = [&](int pos, int val) {
		pos += bpv;
		rmq[pos] = val;
		pos /= 2;
		while (pos) {
			rmq[pos] = max(rmq[pos * 2], rmq[pos * 2 + 1]);
			pos /= 2;
		}
	};

	function<int(int, int, int, int, int)> rmq_get = [&](int v, int vl, int vr, int l, int r) {
		if (r <= vl || vr <= l) {
			return -1;
		}
		if (l <= vl && vr <= r) {
			return rmq[v];
		}
		int vm = (vl + vr) / 2;
		return max(rmq_get(v * 2, vl, vm, l, r), rmq_get(v * 2 + 1, vm, vr, l, r));
	};

	vector<string> ans(n);

	for (int i = 0; i < szof(s); ++i) {
		// cerr << i << " " << nodes[i] << endl;
		rmq_set(tin[nodes[i]], i + 1);
		for (auto& p : here[i]) {
			auto& w = get<2>(p);
			int cur = 0;
			vector<int> path = {cur};
			for (char c : w) {
				if (cur != -1) {
					cur = automaton[cur].go[c - 'a'];
				}
				path.push_back(cur);
			}
			int l = get<1>(p);

			bool found = false;
			char symb = 'a' - 1;
			for (int j = szof(path) - 1; j >= 0; --j) {
				if (path[j] != -1) {
					for (char c = symb + 1; c <= 'z'; ++c) {
						int end = automaton[path[j]].go[c - 'a'];
						// cerr << get<0>(p) << " " << j << " " << c << " " << end << endl;
						// if (end != -1) {
						// 	cerr << get<0>(p) << " " << j << " " << c << " " << end << " " << rmq_get(1, 0, bpv, tin[end], tout[end]) << endl;
						// }
						if (end != -1 && rmq_get(1, 0, bpv, tin[end], tout[end]) - (j + 1) >= l) {
							ans[get<0>(p)] = w.substr(0, j);
							ans[get<0>(p)] += c;
							found = true;
							break;
						}
					}
				}
				if (found) {
					break;
				}
				if (j) {
					symb = w[j - 1];
				}
			}

			if (!found) {
				ans[get<0>(p)] = "-1";
			}
		}
	}

	for (auto& t : ans) {
		cout << t << "\n";
	}
}


int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	cerr << fixed << setprecision(15);
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(false);

	int tests = 1;
	// cin >> tests;
	for (int it = 1; it <= tests; ++it) {
		solve();
	}
	
	#ifdef LOCAL
		cerr << "time: " << clock() << " ms\n";
	#endif
	return 0;
}
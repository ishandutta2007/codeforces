#include <bits/stdc++.h>
using namespace std;

struct bigraph {
	struct edge {
		int u, v;
		edge(int u, int v) : u(u), v(v) {}
	};

	int l, r, m;
	std::vector<edge> edges;
	std::vector<std::vector<int>> adj;
	std::vector<int> pl, pr;
	std::vector<bool> visited;

	bigraph() : l(), r(), m() {}
	bigraph(int l, int r, int m = 0) : l(l), r(r), m(), adj(l), pl(l, -1), pr(r, -1), visited(l) {
		edges.reserve(m);
	}

	int add_edge(int u, int v) {
		adj[u].push_back(v);
		edges.emplace_back(u, v);
		return m++;
	}

	bool dfs(int x) {
		visited[x] = true;
		for (int i : adj[x]) {
			if (pr[i] == -1) {
				pl[x] = i;
				pr[i] = x;
				return true;
			}
		}
		for (int i : adj[x]) {
			if (!visited[pr[i]] && dfs(pr[i])) {
				pl[x] = i;
				pr[i] = x;
				return true;
			}
		}
		return false;
	}

	int matching() {
		int ans = 0;
		while (true) {
			std::fill(visited.begin(), visited.end(), false);
			int add = 0;
			for (int i = 0; i < l; i++)
				if (pl[i] == -1)
					add += dfs(i);
			if (!add) break;
			ans += add;
		}
		return ans;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	struct edge { int u, v; };

	int n, m, k;
	cin >> n >> m >> k;

	vector<bool> marked(m);
	vector<edge> e(m);

	vector<vector<int>> in(n), out(n);
	for (int i = 0; i < m; i++) {
		cin >> e[i].u >> e[i].v;
		out[--e[i].u].push_back(i);
		in[--e[i].v].push_back(i);
	}

	vector<int> x(k), y(k);
	for (int i = 0; i < k; i++) cin >> x[i] >> y[i];

	auto path_cover = [&](void) -> int {
		bigraph bp(n, n);
		for (int i = 0; i < m; i++) {
			if (!marked[i]) {
				bp.add_edge(e[i].u, e[i].v);
			}
		}
		return n - bp.matching();
	};

	int cover_size = path_cover();

	auto mark = [&](int u, int f) -> bool {
		vector<int> now_marked;
		if (!f) for (int i : in[u]) {
			if (!marked[i]) {
				now_marked.push_back(i);
				marked[i] = true;
			}
		} else for (int i : out[u]) {
			if (!marked[i]) {
				now_marked.push_back(i);
				marked[i] = true;
			}
		}
		if (now_marked.empty()) {
			return false;
		}
		int return_value = path_cover();
		if (return_value == cover_size) {
			for (int i : now_marked) {
				marked[i] = false;
			}
			return false;
		}
		cover_size = return_value;
		return true;
	};

	vector<vector<int>> pos(k, vector<int>(k, -1));
	vector<vector<int>> solutions(k);

	int min_y = 0;
	for (int turn = 0; turn < k; turn++) {
		for (int i = 0; i < k; i++) {
			pos[i][turn] = solutions[i].size();
			solutions[i].push_back(0);
		}
		if (y[turn] < y[min_y]) {
			min_y = turn;
		}
		if (cover_size == turn + 1) {
			int v = 0;
			for (int u = 0; u < n && v == 0; u++) {
				if (mark(u, 0)) {
					v = - u - 1;
				} else if (mark(u, 1)) {
					v = u + 1;
				}
			}
			for (int i = 0; i <= turn; i++) {
				solutions[i].insert(solutions[i].begin() + pos[i][i], v);
				for (int j = i; j <= turn; j++) {
					pos[i][j] += 1;
				}
			}
			for (int i = turn + 1; i < k; i++) {
				solutions[i].insert(solutions[i].begin() + pos[i][min_y], v);
				for (int j = min_y; j <= turn; j++) {
					pos[i][j] += 1;
				}
			}
		}
	}

	int best_solution = -1;
	long long best_solution_value = -1;

	for (int i = 0; i < k; i++) {
		long long solution_value = 0;
		int j = 0, t = 0;
		for (int action : solutions[i]) {
			if (action == 0) {
				solution_value += max(0ll, x[j] - (long long)t * y[j]);
				j += 1, t = 0;
			} else {
				t += 1;
			}
		}
		if (solution_value > best_solution_value) {
			best_solution = i;
			best_solution_value = solution_value;
		}
	}

	cout << solutions[best_solution].size() << '\n';
	for (int move : solutions[best_solution]) cout << move << ' ';
	cout << '\n';
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

class DiGraph {
public:
    struct edge {
        int u, v;
        edge(int u, int v): u(u), v(v) {}
    };

    int n, m;
    vector<edge> edges;
    vector<vector<int>> adj;

    DiGraph(): n(), m(), adj(), edges() {}
    DiGraph(int n): n(n), m(), adj(n), edges() {}

    const vector<int>& operator[](const int& x) const { return adj[x]; }
    vector<int>& operator[](const int &x) { return adj[x]; }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        edges.emplace_back(u, v);
        m++;
    }

    DiGraph transpose() const {
        DiGraph rev(n);
        for (auto &[u, v] : edges) {
            rev.addEdge(v, u);
        }
        return rev;
    }
};

class Kosaraju {
public:
    const DiGraph& g;
    DiGraph grev;
    int timer;
    vector<int> f, visited;
    Kosaraju(const DiGraph& g): g(g), timer(), f(g.n), visited(g.n) {
        grev = g.transpose();
    }
    void dfs(int x) {
        visited[x] = true;
        for (auto& i : grev[x]) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        f[timer++] = x;
    }
    void dfs(int x, int s, vector<int>& l) {
        visited[x] = true;
        l[x] = s;
        for (auto& i : g[x]) {
            if (!visited[i]) {
                dfs(i, s, l);
            }
        }
    }
    vector<int> SCC() {
        for (int i = 0; i < g.n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        fill(visited.begin(), visited.end(), false);
        vector<int> l(g.n);
        for (int i = g.n - 1; i >= 0; i--) {
            if (!visited[f[i]]) {
                dfs(f[i], f[i], l);
            }
        }
        return l;
    }
};

vector<int> eulerCircuit(DiGraph& g) {
	int v = -1;
	for (int i = 0; i < g.n; i++) {
		if (!g[i].empty()) {
			v = i;
			break;
		}
	}

	if (v == -1) {
		return {};
	}

	vector<int> in(g.n), out(g.n);
	for (auto& [u, v] : g.edges) {
		out[u]++;
		in[v]++;
	}

	int start = -1, end = -1;
	for (int i = 0; i < g.n; i++) {
		if (abs(in[i] - out[i]) > 1) {
			return {-1};
		} else if (in[i] == out[i] + 1) {
			if (end != -1) {
				return {-1};
			}
			end = i;
		} else if (out[i] == in[i] + 1) {
			if (start != -1) {
				return {-1};
			}
			start = i;
		}
	}

	if ((start == -1) != (end == -1)) {
		return {-1};
	}

	if (start != -1 and end != -1) {
		g.addEdge(end, start);
		in[start]++;
		out[end]++;
	}

	vector<int> l = Kosaraju(g).SCC();
	for (int i = 0; i < g.n; i++) {
		if (!g[i].empty() and l[i] != l[v]) {
			return {-1};
		}
	}

	stack<int> cur_path;
	vector<int> circuit;

	cur_path.push(start != -1 ? start : v);
	while (!cur_path.empty()) {
		int cur_v = cur_path.top();
		if (out[cur_v]) {
			int next_v = g[cur_v][out[cur_v] - 1];
			out[cur_v]--;
			cur_path.push(next_v);
		} else {
			cur_path.pop();
			circuit.push_back(cur_v);
		}
	}
	reverse(circuit.begin(), circuit.end());
	for (int i = 1; i < circuit.size(); i++) {
		if (circuit[i] == start and circuit[i - 1] == end) {
			rotate(circuit.begin(), circuit.begin() + i, circuit.end());
			circuit.erase(circuit.end() - i);
			break;
		}
	}
	return circuit;
}

int pos[256];
int id(char i, char j) {
	return pos[i] * 62 + pos[j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	string s, temp;
	for (char ch = 'A'; ch <= 'Z'; ch++) s += ch;
	for (char ch = 'a'; ch <= 'z'; ch++) s += ch;
	for (char ch = '0'; ch <= '9'; ch++) s += ch;

	for (int i = 0; i < s.size(); i++) {
		pos[s[i]] = i;
	}

	int n;
	cin >> n;

	DiGraph g(62 * 62);
	vector<string> a(n);

	for (int i = 0; i < n; i++) {
		cin >> temp;
		g.addEdge(id(temp[0], temp[1]), id(temp[1], temp[2]));
	}

	auto v = eulerCircuit(g);
	if (v.front() == -1) {
		cout << "NO\n";
	} else {
		string ans;
		ans += s[v.front() / 62];
		for (int i : v) {
			ans += s[i % 62];
		}
		cout << "YES\n" << ans << '\n';
	}
    return 0;
}
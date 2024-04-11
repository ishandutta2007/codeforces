#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

class Edge {
public:
	int to;
	int max_flow;
	int rev;
};

class Dinic {
	int V;
	bool directed;
public:
	vector<vector<Edge>>edge;
	vector<int>depth;
	vector<int>index;
	Dinic(int n, bool D) {
		n++;
		V = n;
		edge.resize(V);
		depth.resize(V);
		index.resize(V);
		directed = D;
		return;
	}
	void Add_Edge(int l, int r, int max_flow) {
		edge[l].push_back({ r,max_flow,(int)edge[r].size() });
		if (directed) {
			edge[r].push_back({ l,0,(int)edge[l].size() - 1 });
		}
		else {
			edge[r].push_back({ l,max_flow,(int)edge[l].size() - 1 });
		}
		return;
	}
	void Check_Depth(int s) {
		for (int i = 0; i < V; i++) {
			depth[i] = INT_MAX;
		}
		depth[s] = 0;
		queue<int>Q;
		Q.push(s);
		while (!Q.empty()) {
			int cn = Q.front();
			Q.pop();
			for (auto i : edge[cn]) {
				if (i.max_flow > 0 && depth[i.to] == INT_MAX) {
					depth[i.to] = depth[cn] + 1;
					Q.push(i.to);
				}
			}
		}
		return;
	}
	int max_flow(int v, int g, int ret) {
		if (v == g) {
			return ret;
		}
		for (int &i = index[v]; i < edge[v].size(); i++) {
			if (edge[v][i].max_flow > 0 && depth[v] < depth[edge[v][i].to]) {
				int d = max_flow(edge[v][i].to, g, min(ret, edge[v][i].max_flow));
				if (d > 0) {
					edge[v][i].max_flow -= d;
					edge[edge[v][i].to][edge[v][i].rev].max_flow += d;
					return d;
				}
			}
		}
		return 0;
	}
	long long Solve(int s, int g) {
		int ret = 0;
		while (1) {
			Check_Depth(s);
			if (depth[g] == INT_MAX) {
				return ret;
			}
			for (int i = 0; i < V; i++) {
				index[i] = 0;
			}
			int add = 0;
			while ((add = max_flow(s, g, INT_MAX)) > 0) {
				ret += add;
			}
		}
		return ret;
	}
};

void Solve() {
	cin >> N;
	vector<int>v(N);
	vector<int>w(N);
	for (auto &i : v)cin >> i;
	for (auto &i : w)cin >> i;
	Dinic d(N + 103, true);
	int s = N + 101;
	int t = N + 102;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (w[i] < 0) {
			d.Add_Edge(s, i, -w[i]);
		}
		else {
			sum += w[i];
			d.Add_Edge(i, t, w[i]);
		}
	}
	for (int i = 0; i < N; i++) {
		int flag[101] = {};
		for (int j = i + 1; j < N; j++) {
			if ((v[j] % v[i] == 0 && !flag[v[j]])) {
				flag[v[j]] = 1;
				d.Add_Edge(i, j, MOD);
			}
		}
	}
	cout << sum - d.Solve(s, t) << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	//cin >> T;
	while (T--) {
		Solve();
	}
}
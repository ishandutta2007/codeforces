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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;

class Edge {
public:
	long long int to;
	long long int max_flow;
	long long int rev;
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
	long long int max_flow(int v, int g, long long int ret) {
		if (v == g) {
			return ret;
		}
		for (int i = index[v]; i < edge[v].size(); i++) {
			if (edge[v][i].max_flow > 0 && depth[v] < depth[edge[v][i].to]) {
				long long int d = max_flow(edge[v][i].to, g, min(ret, edge[v][i].max_flow));
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
		long long int ret = 0;
		while (1) {
			Check_Depth(s);
			if (depth[g] == INT_MAX) {
				return ret;
			}
			for (int i = 0; i < V; i++) {
				index[i] = 0;
			}
			long long int add = 0;
			while ((add = max_flow(s, g, INT_MAX)) > 0) {
				ret += add;
			}
		}
		return ret;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<int>p(N);
	vector<vector<int>>edge(M, vector<int>(5000));
	for (auto &i : p)cin >> i;
	vector<int>c(N);
	for (auto &i : c) {
		cin >> i;
		i--;
	}
	cin >> K;
	vector<int>pop(K);
	vector<int>st(N,1);
	for (auto &i : pop) {
		cin >> i;
		i--;
		st[i] = 0;
	}
	Dinic dn(10002, true);
	for (int i = 0; i < M; i++) {
		dn.Add_Edge(10000, i, 1);
	}
	dn.Add_Edge(5000, 10001, 1);
	for (int i = 0; i < N; i++) {
		if (!st[i])continue;
		if (!edge[c[i]][p[i]]) {
			//cout << c[i] << " " << p[i] << endl;
			edge[c[i]][p[i]]++;
			dn.Add_Edge(c[i], p[i] + 5000, 1);
		}
	}
	int score = 0;
	//cout << dn.Solve(10000, 10001) << endl;
	while (1 == dn.Solve(10000, 10001)) {
		score++;
		dn.Add_Edge(score + 5000, 10001,1);
	}
	vector<int>ans;
	ans.push_back(score);
	reverse(pop.begin(), pop.end());
	for (auto i : pop) {
		if (edge[c[i]][p[i]]) {
			ans.push_back(score);
			continue;
		}
		dn.Add_Edge(c[i], p[i] + 5000, 1);
		edge[c[i]][p[i]]++;
		while (1 == dn.Solve(10000, 10001)) {
			score++;
			dn.Add_Edge(score + 5000, 10001, 1);
		}
		ans.push_back(score);
	}
	ans.pop_back();
	reverse(ans.begin(), ans.end());
	for (auto i : ans)cout << i << endl;
	return 0;
}
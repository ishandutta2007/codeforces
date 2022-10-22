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

//constexpr long long int MOD = 1000000007;
constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

long long int power(long long int x, long long int n, long long int M) {
	long long int ret = 1;
	long long int by = x;
	while (n) {
		if (n & 1) {
			ret *= by;
			ret %= M;
		}
		by *= by;
		by %= M;
		n >>= 1;
	}
	return ret;
}

class Lowest_Common_Ancestor {
	vector<int>depth;
	vector<vector<int>>parent;
	vector<vector<int>>edge;
	int height = 0;
	int node;
public:
	Lowest_Common_Ancestor(int num) {
		num++;
		node = num;
		while (num) {
			height++;
			num /= 2;
		}
		parent.resize(height);
		edge.resize(node);
		depth.resize(node);
		for (int i = 0; i < height; i++)parent[i].resize(node);
	}
	void Add_Edge(int a, int b) {
		edge[a].push_back(b);
		edge[b].push_back(a);
		return;
	}
	void Update(int rtnode) {
		queue<int>QQ;
		for (int i = 0; i < node; i++) depth[i] = INT_MAX;
		depth[rtnode] = 0;
		QQ.push(rtnode);
		while (!QQ.empty()) {
			int c = QQ.front();
			for (auto i : edge[c]) {
				if (depth[i] > depth[c] + 1) {
					depth[i] = depth[c] + 1;
					QQ.push(i);
				}
			}
			QQ.pop();
		}
		parent[0][rtnode] = -1;
		for (int i = 0; i < node; i++) {
			for (auto j : edge[i]) {
				if (depth[i] - 1 == depth[j]) {
					parent[0][i] = j;
					break;
				}
			}
		}
		for (int i = 0; i < height - 1; i++) {
			for (int j = 0; j < node; j++) {
				if (parent[i][j] < 0)parent[i + 1][j] = -1;
				else parent[i + 1][j] = parent[i][parent[i][j]];
			}
		}
		return;
	}
	int LCA(int u, int v) {
		if (depth[u] > depth[v])swap(u, v);
		for (int i = 0; i < height; i++) {
			if ((depth[v] - depth[u]) >> i & 1) {
				v = parent[i][v];
			}
		}
		if (u == v)return u;
		for (int i = height - 1; i >= 0; i--) {
			if (parent[i][v] != parent[i][u]) {
				u = parent[i][u];
				v = parent[i][v];
			}
		}
		return parent[0][u];
	}
	int Dist(int u, int v) {
		return depth[u] + depth[v] - depth[LCA(u, v)] * 2;
	}
};

void Solve() {
	cin >> N;
	vector<vector<int>>edge(N);
	vector<vector<int>>dis(N, vector<int>(N, MOD));
	Lowest_Common_Ancestor lca(N);
	for (int i = 1; i < N; i++) {
		cin >> L >> R;
		L--, R--;
		dis[L][R] = 1;
		dis[R][L] = 1;
		lca.Add_Edge(L, R);
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	for (int i = 0; i < N; i++) {
		dis[i][i] = 0;
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	vector<vector<long long int>>num(N, vector<long long int>(N));
	for (int i = 0; i < N; i++) {
		num[i][0] = 0;
		num[0][i] = 1;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			num[i][j] = num[i - 1][j] + num[i][j - 1];
			num[i][j] *= power(2, MOD - 2, MOD);
			num[i][j] %= MOD;
		}
	}
	long long ans = 0;
	for (int k = 0; k < N; k++) {
		lca.Update(k);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i; j++) {
				long long add = 0;
				if (dis[i][k] + dis[i][j] == dis[j][k]) {
					add++;
				}
				else if (dis[j][k] + dis[i][j] == dis[i][k]) {
					
				}
				else {
					int idx = lca.LCA(i, j);
					add += num[dis[idx][i]][dis[idx][j]];
					add %= MOD;

				}
				add *= power(N, MOD - 2, MOD);
				ans += add;
				ans %= MOD;
			}
		}
	}
	cout << ans << endl;
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
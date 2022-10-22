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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

class Lowest_Common_Ancestor {
public:
	vector<int>depth;
	vector<vector<int>>parent;
	vector<vector<int>>edge;
	int height = 0;
	int node;
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
		for (int i = 1; i < node; i++) depth[i] = INT_MAX;
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
		for (int i = 1; i < node; i++) {
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

void Calculate_Depth(vector<vector<int>>&edge, vector<int>&depth, int stnode) {
	depth[stnode] = 0;
	queue<int>Q;
	Q.push(stnode);
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		for (auto i : edge[cn]) {
			if (depth[i] > depth[cn] + 1) {
				depth[i] = depth[cn] + 1;
				Q.push(i);
			}
		}
	}
	return;
}

void Search(vector<vector<int>>&edge, vector<int>&sum, vector<int>&depth, int node) {
	sum[node] = 1;
	for (auto i : edge[node]) {
		if (depth[i] > depth[node]) {
			Search(edge, sum, depth, i);
			sum[node] += sum[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<vector<int>>edge(N + 1);
	Lowest_Common_Ancestor lca(N);
	for (int i = 1; i < N; i++) {
		cin >> L >> R;
		edge[L].push_back(R);
		edge[R].push_back(L);
		lca.Add_Edge(L, R);
	}
	vector<int>depth(N + 1, MOD);
	vector<int>sum(N + 1, 0);
	Calculate_Depth(edge, depth, 1);
	cin >> M;
	lca.Update(1);
	Search(edge, sum, depth, 1);
	for (int i = 0; i < M; i++) {
		cin >> L >> R;
		if (L == R) {
			cout << N << endl;
			continue;
		}
		H = depth[L];
		W = depth[R];
		if ((H & 1) != (W & 1)) {
			cout << 0 << endl;
			continue;
		}
		if (H > W) {
			swap(H, W);
			swap(L, R);
		}
		int cn = lca.LCA(L, R);
		K = depth[cn];
		int num = H - K + W - K;
		int r = R;
		num >>= 1;
		for (int i = 0; i < lca.parent.size(); i++) {
			if ((num >> i) & 1) {
				R = lca.parent[i][R];
			}
		}
		num--;
		for (int i = 0; i < lca.parent.size(); i++) {
			if ((num >> i) & 1) {
				r = lca.parent[i][r];
			}
		}
		//cout << H << "    " << W << endl;
		if (H != W) {
			cout << sum[R] - sum[r] << endl;
		}
		else {
			//cout << "hi";
			int l = L;
			for (int i = 0; i < lca.parent.size(); i++) {
				if ((num >> i) & 1) {
					l = lca.parent[i][l];
				}
			}
			cout << N - sum[r] - sum[l] << endl;
		}
	}
}
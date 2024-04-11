#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"
#include "string"
#include "map"
#include "unordered_map"
#include "iomanip"
#include "random"

using namespace std;
const long long int MOD = 1000000007;

long long int power(long long int x, long long int n, long long int M) {
	long long int tmp = 1;

	if (n > 0) {
		tmp = power(x, n / 2, M);
		if (n % 2 == 0) tmp = (tmp*tmp) % M;
		else tmp = (((tmp*tmp) % M)*x) % M;
	}
	return tmp;
}

long long int N, M, K, Q, W, H, L, R;
long long int ans;

class Lowest_Common_Ancestor {
	vector<int>depth;
	vector<int>parent[25];
	list<int>edge[1000001];
	int node;
public:
	Lowest_Common_Ancestor(int num) {
		node = num;
		num++;
		depth.resize(num);
		for (int i = 0; i < 25; i++)parent[i].resize(num);
	}
	void Add_Edge(int a, int b) {
		edge[a].push_back(b);
		edge[b].push_back(a);
		return;
	}
	void Update() {
		queue<int>QQ;
		depth[1] = 0;
		for (int i = 2; i <= node; i++) depth[i] = INT_MAX;
		QQ.push(1);
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
		parent[0][1] = -1;
		for (int i = 2; i <= node; i++) {
			for (auto j : edge[i]) {
				if (depth[i] - 1 == depth[j]) {
					parent[0][i] = j;
					break;
				}
			}
		}
		for (int i = 0; i < 24; i++) {
			for (int j = 1; j <= node; j++) {
				if (parent[i][j] < 0)parent[i + 1][j] = -1;
				else parent[i + 1][j] = parent[i][parent[i][j]];
			}
		}
		return;
	}
	int LCA(int u, int v) {
		if (depth[u] > depth[v])swap(u, v);
		for (int i = 0; i < 25; i++) {
			if ((depth[v] - depth[u]) >> i & 1) {
				v = parent[i][v];
			}
		}
		if (u == v)return u;
		for (int i = 24; i >= 0; i--) {
			if (parent[i][v] != parent[i][u]) {
				u = parent[i][u];
				v = parent[i][v];
			}
		}
		return parent[0][u];
	}
	int Dist(int u, int v) {
		return depth[u] + depth[v] - depth[LCA(u, v)]*2;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	Lowest_Common_Ancestor lca(N);
	for (int i = 2; i <= N; i++) {
		int a;
		cin >> a;
		lca.Add_Edge(i, a);
	}
	lca.Update();
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		int d[3];
		d[0] = lca.Dist(a, b);
		d[1] = lca.Dist(c, b);
		d[2] = lca.Dist(a, c);
		sort(d, d + 3);
		
		cout << (d[2] + d[1] - d[0]) / 2 + 1 << endl;
	}
	return 0;
}
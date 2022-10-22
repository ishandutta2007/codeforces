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

//constexpr long long MOD = 1000000007;
constexpr long long MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

class UnionFind {
	vector<int>parent;
	vector<int>rank;
public:
	UnionFind(int num) {
		num++;
		parent.resize(num);
		rank.resize(num);
		for (int i = 0; i < num; i++) {
			parent[i] = i;
			rank[i] = 0;
		}
	}
	int Find(int node) {
		if (parent[node] == node)return node;
		else return parent[node] = Find(parent[node]);
	}
	void Unite(int u, int v) {
		u = Find(u);
		v = Find(v);
		if (u == v)return;
		if (rank[u] < rank[v])parent[u] = v;
		else {
			parent[v] = u;
			if (rank[u] == rank[v])rank[u]++;
		}
	}
	bool Check_Same(int u, int v) {
		return Find(u) == Find(v);
	}
};

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

void func(vector<vector<int>>& edge, vector<int>& p, vector<vector<int>>& dp, int node = 0, int pa = -1) {
	dp[node][0] = 0;
	dp[node][1] = 1;
	for (auto i : edge[node]) {
		if (i == pa)continue;
		func(edge, p, dp, i, node);
		vector<int>nx(2, MOD);
		nx[0] = min(nx[0], dp[node][0] + dp[i][0]);
		nx[1] = min(nx[1], dp[node][0] + dp[i][0] + 1);
		nx[0] = min(nx[0], dp[node][0] + dp[i][1]);
		nx[1] = min(nx[1], dp[node][0] + dp[i][1]);
		nx[0] = min(nx[0], dp[node][1] + dp[i][0]);
		nx[1] = min(nx[1], dp[node][1] + dp[i][0]);
		nx[0] = min(nx[0], dp[node][1] + dp[i][1] - 1);
		nx[1] = min(nx[1], dp[node][1] + dp[i][1]);
		p[node] += p[i];
		dp[node] = nx;
	}
	if (p[node] & 1) {
		dp[node][1] = min(dp[node][1], dp[node][0] + 1);
		dp[node][0] = MOD;
	}
	else {
		dp[node][0] = min(dp[node][0], dp[node][1] + 1);
		dp[node][1] = MOD;
	}
	return;
}


void Solve() {
	cin >> N >> M;
	UnionFind uf(N);
	vector<vector<int>>edge(N);
	Lowest_Common_Ancestor LCA(N);
	for (int i = 0; i < M; i++) {
		cin >> L >> R;
		L--, R--;
		if (uf.Check_Same(L, R))continue;
		edge[L].push_back(R);
		edge[R].push_back(L);
		LCA.Add_Edge(L, R);
		uf.Unite(L, R);
	}
	LCA.Update(0);
	vector<int>p(N);
	cin >> K;
	vector<vector<int>>ans;
	while (K--) {
		cin >> L >> R;
		L--, R--;
		p[L]++;
		p[R]++;
		int rt = LCA.LCA(L, R);
		p[rt] -= 2;
		vector<int>a;
		vector<int>b;
		a.push_back(L);
		while (L != rt) {
			L = LCA.parent[0][L];
			a.push_back(L);
		}
		while (R != rt) {
			b.push_back(R);
			R = LCA.parent[0][R];
		}
		reverse(b.begin(), b.end());
		ans.push_back(a);
		for (auto i : b) {
			ans.back().push_back(i);
		}
	}
	vector<vector<int>>dp(N, vector<int>(2, MOD));
	func(edge, p, dp);
	//for (int i = 0; i < N; i++) {
	//	cout << i << " " << p[i] << " " << dp[i][0] << " " << dp[i][1] << endl;
	//}
	if (dp[0][0]) {
		cout << "No\n";
		cout << min(dp[0][0],dp[0][1]) << endl;
	}
	else {
		cout << "Yes\n";
		for (auto i : ans) {
			cout << i.size() << endl;
			for (auto j : i)cout << j+1 << " ";
			cout << endl;
		}
	}
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
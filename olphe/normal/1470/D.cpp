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
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

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

void Solve() {
	cin >> N >> M;
	vector<vector<int>>edge(N);
	vector<int>used(N);
	UnionFind uf(N);
	int comp = N;
	vector<int>ans;
	for (int i = 0; i < M; i++) {
		cin >> L >> R;
		L--, R--;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	ans.push_back(0);
	set<int>st;
	used[0] = 1;
	for (auto i : edge[0]) {
		uf.Unite(0, i);
		comp--;
		st.erase(i);
		used[i] = 1;
		for (auto j : edge[i]) {
			if (!uf.Check_Same(0, j))st.insert(j);
		}
	}
	while (!st.empty()) {
		int cn = *st.begin();
		st.erase(st.begin());
		if (uf.Check_Same(0, cn))continue;
		ans.push_back(cn);
		for (auto i : edge[cn]) {
			if (!uf.Check_Same(cn, i)) {
				comp--;
				uf.Unite(cn, i);
			}
			if (!used[i]) {
				used[i] = 1;
				for (auto j : edge[i]) {
					if (!uf.Check_Same(0, j))st.insert(j);
				}
			}
			st.erase(i);
		}
	}
	sort(ans.begin(), ans.end());
	if (comp > 1) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
		cout << ans.size() << "\n";
		for (auto i : ans)cout << i + 1 << " ";
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}
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
	stack<int>child;
	vector<int>sz;
public:
	UnionFind(int num) {
		parent.resize(num);
		sz.resize(num, 1);
		for (int i = 0; i < num; i++) {
			parent[i] = i;
		}
	}
	int Find(int node) {
		if (parent[node] == node)return node;
		else return Find(parent[node]);
	}
	void ReversibleUnite(int u, int v) {
		u = Find(u);
		v = Find(v);
		if (u == v)return;
		if (sz[u] < sz[v]) {
			parent[u] = v;
			sz[v] += sz[u];
			child.push(u);
		}
		else {
			sz[u] += sz[v];
			parent[v] = u;
			child.push(v);
		}
	}
	void Undo() {
		int c = child.top();
		child.pop();
		parent[c] = c;
	}
	bool Check_Same(int u, int v) {
		return Find(u) == Find(v);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	vector<int>v(N);
	vector<vector<int>>box(K);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		v[i]--;
		box[v[i]].push_back(i);
	}
	vector<vector<int>>edge(N);
	UnionFind uf(2 * N);
	UnionFind node_uf(N);
	set<pair<int, int>>st;
	vector<map<int, vector<pair<int, int>>>>mp_edge(K);
	for (int i = 0; i < M; i++) {
		cin >> L >> R;
		L--, R--;
		if (v[L] == v[R]) {
			uf.ReversibleUnite(L, R + N);
			uf.ReversibleUnite(L + N, R);
			node_uf.ReversibleUnite(L, R);
		}
		else {
			int a = min(v[L], v[R]);
			int b = max(v[L], v[R]);
			mp_edge[a][b].push_back({ L,R });
			st.insert({ a,b });
		}
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	vector<int>ok(K, 1);
	for (int i = 0; i < N; i++) {
		if (uf.Check_Same(i, i + N)) {
			ok[v[i]] = 0;
		}
	}
	long long int ans = 0;
	for (int i = 0; i < K; i++) {
		ans += ok[i];
	}
	ans = ans * (ans - 1) / 2;
	for (auto i : st) {
		int a = i.first;
		int b = i.second;
		if (!ok[a] || !ok[b])continue;
		int num = 0;
		bool flag = true;
		for (auto j : mp_edge[a][b]) {
			L = j.first, R = j.second;
			if (!uf.Check_Same(L, R + N) && node_uf.Check_Same(L, R)) {
				flag = false;
				break;
			}
			if (uf.Check_Same(L, R + N))continue;
			num++;
			node_uf.ReversibleUnite(L, R);
			uf.ReversibleUnite(L, R + N);
			uf.ReversibleUnite(R, L + N);
		}
		if (flag) {

		}
		else {
			ans--;
		}
		while (num--) {
			uf.Undo();
			uf.Undo();
			node_uf.Undo();
		}
	}
	cout << ans << endl;
}
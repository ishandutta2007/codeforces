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

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<pair<int, int>>v(N);
	for (auto &i : v)cin >> i.first >> i.second;
	UnionFind uf(N);
	map<int, int>m;
	for (int i = 0; i < N; i++) {
		auto a = m.find(v[i].first), b = m.find(v[i].second);
		if (a == m.end()) {
			m[v[i].first] = i;
		}
		else {
			uf.Unite(a->second, i);
		}
		if (b == m.end()) {
			m[v[i].second] = i;
		}
		else {
			uf.Unite(b->second, i);
		}
	}
	int ans = 0;
	vector<int>num(N + 1);
	vector<set<int>>box(N + 1);
	for (int i = 0; i < N; i++) {
		num[uf.Find(i)]++;
		box[uf.Find(i)].insert(-v[i].first);
		box[uf.Find(i)].insert(-v[i].second);
	}
	for (int i = 0; i < N; i++) {
		if (!num[i])continue;
		//cout << box[i].size() << " " << num[i] << endl;
		if (box[i].size() < num[i]) {
			cout << -1 << endl;
			return 0;
		}
		while (box[i].size() > num[i]) {
			box[i].erase(box[i].begin());
		}
		ans = max(ans, -(*box[i].begin()));
	}
	cout << ans << endl;
	return 0;
}
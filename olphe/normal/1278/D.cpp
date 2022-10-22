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
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

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
	for (auto &i : v)cin >> i.first>>i.second;
	sort(v.begin(), v.end());
	set<pair<int, int>>st;
	vector<vector<int>>edge(N);
	int num = 0;
	UnionFind uf(N);
	for (int i = 0; i < N; i++) {
		while (!st.empty() && st.begin()->first < v[i].first) {
			st.erase(st.begin());
		}
		for (auto j : st) {
			if (j.first < v[i].second) {
				int a = j.second;
				int b = i;
				if (uf.Check_Same(a, b)) {
					cout << "NO\n";
					return 0;
				}
				num++;
				uf.Unite(a, b);
			}
			else break;
		}
		st.insert({ v[i].second, i });
	}
	if (num < N - 1) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
}
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
constexpr double EPS = 1e-9;

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

void dfs(int u, vector<int> &trail, vector<multiset<int>>&edge) {
	while (!edge[u].empty()) {
		int v = *edge[u].begin();
		edge[u].erase(edge[u].begin());
		edge[v].erase(edge[v].find(u));
		dfs(v, trail, edge);
	}
	trail.push_back(u);
}

class XorShift {
	unsigned int x, y, z, w, t;
public:
	XorShift() {
		x = 133553533;
		y = 314867339;
		z = 664298413;
		w = 999999937;
		t = 0;
	}
	unsigned int rand() {
		t = x ^ (x << 11);
		x = y;
		y = z;
		z = w;
		w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
		return w & 0x7fffffff;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	XorShift xs;
	cin >> N;
	vector<int>v(N * 2);
	for (auto &i : v)cin >> i;
	//for (auto &i : v)i = xs.rand() % (1 << 20);
	L = 0, R = 21;
	while (R - L > 1) {
		int i = (L + R) / 2;
		vector<int>num(1 << i);
		UnionFind uf(1 << i);
		for (int j = 0; j < N; j++) {
			int a = v[j * 2] & ((1 << i) - 1);
			int b = v[j * 2 + 1] & ((1 << i) - 1);
			uf.Unite(a, b);
			num[a]++, num[b]++;
		}
		int st = -1;
		bool flag = true;
		for (int j = 0; j < 1 << i; j++) {
			if (num[j]) {
				if (st == -1)st = uf.Find(j);
				else if (st != uf.Find(j)) {
					flag = false;
				}
			}
		}
		for (auto j : num) {
			if (j & 1)flag = false;
		}
		if (flag) {
			L = i;
		}
		else R = i;
	}
	int i = (L + R) / 2;
	vector<int>num(1 << i);
	UnionFind uf(1 << i);
	vector<multiset<int>>edge(1 << i);
	map<pair<int, int>, vector<pair<int, int>>>mp;
	for (int j = 0; j < N; j++) {
		int a = v[j * 2] & ((1 << i) - 1);
		int b = v[j * 2 + 1] & ((1 << i) - 1);
		uf.Unite(a, b);
		if (a <= b) {
			mp[{a, b}].push_back({ j * 2 + 1,j * 2 + 2 });
		}
		else {
			mp[{b, a}].push_back({ j * 2 + 2,j * 2 + 1 });
		}
		num[a]++, num[b]++;
		edge[a].insert(b);
		edge[b].insert(a);
	}
	int st = -1;
	bool flag = true;
	for (int j = 0; j < 1 << i; j++) {
		if (num[j]) {
			if (st == -1)st = uf.Find(j);
			else if (st != uf.Find(j)) {
				flag = false;
			}
		}
	}
	cout << i << endl;
	vector<int>trail;
	dfs(st, trail, edge);
	for (int j = 1; j <= N; j++) {
		int a = trail[j - 1], b = trail[j];
		if (a > b) {
			auto it = mp.find({ b,a });
			cout << it->second.back().second << " " << it->second.back().first << " ";
			it->second.pop_back();
		}
		else {
			auto it = mp.find({ a,b });
			cout << it->second.back().first << " " << it->second.back().second << " ";
			it->second.pop_back();
		}
	}
	cout << endl;
	return 0;
}
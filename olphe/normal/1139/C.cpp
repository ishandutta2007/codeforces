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

class UnionFind {
	vector<int>parent;
	vector<int>rank;
public:
	vector<int>sz;
	UnionFind(int num) {
		num++;
		parent.resize(num);
		rank.resize(num);
		sz.resize(num);
		for (int i = 0; i < num; i++) {
			parent[i] = i;
			rank[i] = 0;
			sz[i] = 1;
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
		if (rank[u] < rank[v]) {
			parent[u] = v;
			sz[v] += sz[u];
		}
		else {
			parent[v] = u;
			sz[u] += sz[v];
			if (rank[u] == rank[v])rank[u]++;
		}
	}
	bool Check_Same(int u, int v) {
		return Find(u) == Find(v);
	}
};


long long int power(long long int x, long long int n, long long int M) {
	long long int tmp = 1;

	if (n > 0) {
		tmp = power(x, n / 2, M);
		if (n % 2 == 0) tmp = (tmp*tmp) % M;
		else tmp = (((tmp*tmp) % M)*x) % M;
	}
	return tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	UnionFind uf(N);
	for (int i = 1; i < N; i++){
		cin >> L >> R >> M;
		L--;
		R--;
		if (!M) {
			uf.Unite(L, R);
		}
	}
	long long int ans = power(N, K, MOD);
	for (int i = 0; i < N; i++) {
		if (i != uf.Find(i))continue;
		ans -= power(uf.sz[i], K, MOD);
		ans += MOD;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
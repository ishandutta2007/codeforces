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
#include "ctime"

using namespace std;

const long long int MOD = 1000000007;

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
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	cin >> N >> M >> K;
	vector<long long int>v(N+1);
	unordered_map<long long int, unordered_map<long long int,long long int>>m;
	unordered_map<long long int, vector<pair<int, int>>>edge;
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &v[i]);
		//cin >> v[i];
	}
	long long int ans = power(2, N, MOD);
	long long int by = 1LL << K;
	by %= MOD;
	ans *= by;
	ans %= MOD;
	for (int i = 0; i < M; i++) {
		//cin >> L >> R;
		scanf("%lld %lld", &L, &R);
		long long int bag = v[L] ^ v[R];
		m[bag][L]++;
		m[bag][R]++;
		edge[bag].emplace_back(L, R);
	}
	vector<int>converter(N + 1);
	for (auto i : m) {
		int index = 0;
		for (auto j : i.second) {
			converter[j.first] = index++;
		}
		UnionFind uf(index);
		for (auto j : edge[i.first]) {
			uf.Unite(converter[j.first], converter[j.second]);
		}
		unordered_set<int>node;
		for (int j = 0; j < index; j++) {
			node.insert(uf.Find(j));
		}
		long long int box = power(2, N, MOD);
		ans -= box;
		ans += MOD;
		long long int bag = i.second.size() - node.size();
		box *= power(2, MOD - 1 - bag, MOD);
		box %= MOD;
		ans += box;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
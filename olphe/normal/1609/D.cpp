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
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

class UnionFind {
	vector<int>parent;
public:
	vector<int>sz;
	UnionFind(int num) {
		num++;
		parent.resize(num);
		sz.resize(num);
		for (int i = 0; i < num; i++) {
			parent[i] = i;
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
		if (sz[u] < sz[v]) {
			parent[u] = v;
			sz[v]+=sz[u];
		}
		else {
			parent[v] = u;
			sz[u] += sz[v];
		}
	}
	bool Check_Same(int u, int v) {
		return Find(u) == Find(v);
	}
};

void Solve() {
	cin >> N >> K;
	int sz = 1;
	int num = 1;
	UnionFind uf(N);
	multiset<int>unuse;
	multiset<int>use;
	use.insert(1);
	for (int i = 1; i < N; i++) {
		unuse.insert(1);
	}
	int ans = 1;
	while (K--) {
		cin >> L >> R;
		L--, R--;
		if (uf.Check_Same(L, R)) {
			num++;
		}
		else {
			int a = uf.sz[uf.Find(L)];
			int b = uf.sz[uf.Find(R)];
			if (unuse.find(a) == unuse.end()) {
				ans -= a;
				use.erase(use.find(a));
			}
			else {
				unuse.erase(unuse.find(a));
			}
			if (unuse.find(b) == unuse.end()) {
				ans -= b;
				use.erase(use.find(b));
			}
			else {
				unuse.erase(unuse.find(b));
			}
			uf.Unite(L, R);
			use.insert(a + b);
			ans += a + b;
		}
		while(use.size() > num) {
			ans -= *use.begin();
			unuse.insert(*use.begin());
			use.erase(use.begin());
		}
		while (unuse.size() && use.size() < num) {
			ans += *unuse.rbegin();
			use.insert(*unuse.rbegin());
			unuse.erase(unuse.find(*unuse.rbegin()));
		}
		cout << ans - 1 << endl;
		//for (auto i : use)cout << i << " ";
		//cout << endl;
		//for (auto i : unuse)cout << i << " ";
		//cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
//	cin >> T;
	while (T--) {
		Solve();
	}
}
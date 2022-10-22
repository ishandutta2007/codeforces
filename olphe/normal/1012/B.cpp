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

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 1e-8;

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

	cin >> N >> M >> K;
	if (!K) {
		cout << N + M - 1 << endl;
		return 0;
	}
	UnionFind h(N + 1);
	UnionFind w(M + 1);
	map<int, vector<int>>mh;
	map<int, vector<int>>mw;
	for (int i = 0; i < K; i++) {
		cin >> H >> W;
		mh[H].push_back(W);
		mw[W].push_back(H);
	}
	for (auto i : mh) {
		int bef = -1;
		for (auto j : i.second) {
			if (bef == -1) {
				bef = j;
			}
			else {
				w.Unite(bef, j);
				bef = j;
			}
		}
	}
	for (auto i : mw) {
		int bef = -1;
		for (auto j : i.second) {
			if (bef == -1) {
				bef = j;
			}
			else {
				h.Unite(bef, j);
				bef = j;
			}
		}
	}
	set<int>hs;
	set<int>ws;
	for (int i = 1; i <= N; i++) {
		hs.insert(h.Find(i));
	}
	for (int i = 1; i <= M; i++) {
		ws.insert(w.Find(i));
	}
	int mn = N - mh.size();
	int mm = M - mw.size();
	cout << max(hs.size() - mn, ws.size() - mm) - 1 + mn + mm << endl;
	return 0;
}
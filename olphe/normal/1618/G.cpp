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
	vector<int>mx;
	UnionFind(int num) {
		num++;
		parent.resize(num);
		sz.resize(num);
		mx.resize(num);
		for (int i = 0; i < num; i++) {
			parent[i] = i;
			mx[i] = i;
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
			mx[v] = max(mx[u], mx[v]);
			sz[v] += sz[u];
		}
		else {
			parent[v] = u;
			mx[u] = max(mx[u], mx[v]);
			sz[u] += sz[v];
		}
	}
	bool Check_Same(int u, int v) {
		return Find(u) == Find(v);
	}
};


void Solve() {
	cin >> N >> M >> K;
	vector<pair<int, int>>vp(N + M);
	long long score = 0;
	for (int i = 0; i < N; i++) {
		cin >> vp[i].first;
		score += vp[i].first;
	}
	for (int i = 0; i < M; i++) {
		cin >> vp[i + N].first;
		vp[i + N].second = 1;
	}
	vector<long long>sum(N + M + 1);
	sort(vp.begin(), vp.end());
	for (int i = 1; i <= N + M; i++) {
		sum[i] = sum[i - 1] + vp[i - 1].first;
	}
	UnionFind uf(N + M);
	for (int i = 0; i < N + M; i++) {
		if (vp[i].second == 0) {
			uf.sz[i] = 1;
		}
	}
	vector<pair<int, int>>query;
	for (int i = 1; i < N + M; i++) {
		query.push_back({ vp[i].first - vp[i - 1].first,i - 1 });
	}
	sort(query.begin(), query.end());
	int idx = 0;
	vector<pair<int, int>>que(K);
	for (int i = 0; i < K; i++) {
		cin >> que[i].first;
		que[i].second = i;
	}
	sort(que.begin(), que.end());
	vector<long long>ans(K);
	for (auto q : que) {
		while (idx < query.size() && query[idx].first <= q.first) {
			score -= (sum[query[idx].second + 1] - sum[query[idx].second + 1 - uf.sz[uf.Find(query[idx].second)]]);
			score -= (sum[uf.mx[uf.Find(query[idx].second + 1)] + 1] - sum[uf.mx[uf.Find(query[idx].second + 1)] + 1 - uf.sz[uf.Find(query[idx].second + 1)]]);
			uf.Unite(query[idx].second, query[idx].second + 1);
			score += (sum[uf.mx[uf.Find(query[idx].second + 1)] + 1] - sum[uf.mx[uf.Find(query[idx].second + 1)] + 1 - uf.sz[uf.Find(query[idx].second + 1)]]);
			idx++;
		}
		ans[q.second] = score;
	}
	for (auto i : ans)cout << i << endl;
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
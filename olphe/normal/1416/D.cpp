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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

class UnionFind {
	vector<int>parent;
	stack<int>child;
	stack<int>Par;
	stack<vector<int>>merged;
public:
	vector<set<int>>st;
	UnionFind(int num, vector<int>v) {
		parent.resize(num);
		st.resize(num);
		for (int i = 0; i < num; i++) {
			parent[i] = i;
			st[i].insert(v[i]);
		}
	}
	int Find(int node) {
		if (parent[node] == node)return node;
		else return Find(parent[node]);
	}
	void Unite(int u, int v) {
		u = Find(u);
		v = Find(v);
		if (u == v)return;
		if (st[u].size() < st[v].size()) {
			parent[u] = v;
			for (auto i : st[u])st[v].insert(i);
		}
		else {
			parent[v] = u;
			for (auto i : st[v])st[u].insert(i);
		}
	}
	void ReversibleUnite(int u, int v) {
		u = Find(u);
		v = Find(v);
		if (u == v)return;
		if (st[u].size() < st[v].size()) {
			parent[u] = v;
			child.push(u);
			Par.push(v);
			vector<int>box;
			for (auto i : st[u]) {
				st[v].insert(i);
				box.push_back(i);
			}
			merged.push(box);
		}
		else {
			parent[v] = u;
			child.push(v);
			Par.push(u);
			vector<int>box;
			for (auto i : st[v]) {
				st[u].insert(i);
				box.push_back(i);
			}
			merged.push(box);
		}
	}
	void Undo() {
		int c = child.top();
		child.pop();
		int p = Par.top();
		Par.pop();
		for (auto i : merged.top()) {
			auto it = st[p].find(i);
			if (it == st[p].end()) {
				st[c].erase(i);
				continue;
			}
			st[p].erase(it);
		}
		parent[c] = c;
		merged.pop();
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
	for (auto &i : v)cin >> i;
	vector<pair<int, int>>edge(M+1);
	for(int i=1;i<=M;i++){
		cin >> edge[i].first >> edge[i].second;
		edge[i].first--, edge[i].second--;
	}
	vector<pair<int, int>>query(K);
	vector<int>use(M + 1, 1);
	for (auto &i : query) {
		cin >> i.first >> i.second;
		if (i.first == 2)use[i.second] = 0;
	}
	UnionFind uf(N + 1, v);
	for (int i = 1; i <= M; i++) {
		if (use[i]) {
			uf.Unite(edge[i].first, edge[i].second);
		}
	}
	vector<pair<int, int>>nquery;
	for (int i = K - 1; i >= 0; i--) {
		if (query[i].first == 1) {
			nquery.push_back(query[i]);
		}
		else {
			if (uf.Check_Same(edge[query[i].second].first, edge[query[i].second].second))continue;
			uf.ReversibleUnite(edge[query[i].second].first, edge[query[i].second].second);
			nquery.push_back(query[i]);
		}
	}
	reverse(nquery.begin(), nquery.end());
	query = nquery;
	for (auto i : nquery) {
		if (i.first == 1) {
			i.second--;
			int cn = uf.Find(i.second);
			if (uf.st[cn].empty()) {
				cout << 0 << endl;
			}
			else {
				int ret = *uf.st[cn].rbegin();
				cout << ret << endl;
				uf.st[cn].erase((--uf.st[cn].end()));
			}
		}
		else {
			uf.Undo();
		}
	}
}
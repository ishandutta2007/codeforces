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
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

struct Node {
	int node, idx;
	long long int cost;
	Node(int node, int idx, long long int cost) :node(node), idx(idx), cost(cost) {

	}
	bool operator<(const Node& n)const {
		return cost > n.cost;
	}
};

void Solve() {
	cin >> N >> M;
	vector<vector<pair<int, int>>>edge(N);
	for (int i = 0; i < M; i++) {
		cin >> L >> R >> K;
		L--, R--;
		edge[L].emplace_back(R, K);
		edge[R].emplace_back(L, K);
	}
	vector<long long int>dis(N, MOD * MOD);
	vector<vector<long long int>>mid(N, vector<long long int>(51, MOD * MOD));
	dis[0] = 0;
	priority_queue<Node>PQ;
	PQ.push(Node(0, 0, 0));
	while (!PQ.empty()) {
		auto box = PQ.top();
		PQ.pop();
		if (box.idx == 0) {
			if (dis[box.node] < box.cost)continue;
			for (auto i : edge[box.node]) {
				if (mid[i.first][i.second] > box.cost) {
					mid[i.first][i.second] = box.cost;
					PQ.push(Node(i.first, i.second, box.cost));
				}
			}
		}
		else {
			if (mid[box.node][box.idx] < box.cost)continue;
			for (auto i : edge[box.node]) {
				if (dis[i.first] > box.cost + (box.idx + i.second) * (box.idx + i.second)) {
					dis[i.first] = box.cost + (box.idx + i.second) * (box.idx + i.second);
					PQ.push(Node(i.first, 0, dis[i.first]));
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (dis[i] == MOD * MOD)dis[i] = -1;
		if (i)cout << " ";
		cout << dis[i];
	}
	cout << endl;
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
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

struct Node {
	int idx, bit;
	long long int cost;
	Node(int i, int b, long long int c) :idx(i), bit(b), cost(c) {

	}
	bool operator<(const Node&n)const {
		return cost > n.cost;
	}
};

void Solve() {
	cin >> N >> M;
	vector<vector<pair<int, int>>>edge(N);
	for (int i = 0; i < M; i++) {
		cin >> L >> R >> K;
		L--, R--;
		edge[L].push_back({ R,K });
		edge[R].push_back({ L,K });
	}
	vector<vector<long long int>>dis(N, vector<long long int>(4, MOD*MOD));
	dis[0][0] = 0;
	priority_queue<Node>PQ;
	PQ.push(Node(0, 0, 0));
	while (!PQ.empty()) {
		auto box = PQ.top();
		PQ.pop();
		if (dis[box.idx][box.bit] < box.cost)continue;
		for (auto i : edge[box.idx]) {
			for (int j = 0; j <= 3; j++) {
				if (box.bit + j != (box.bit^j))continue;
				int add = i.second;
				if (j == 1)add *= 2;
				if (j == 2)add = 0;
				if (dis[i.first][box.bit + j] > box.cost + add) {
					dis[i.first][box.bit + j] = box.cost + add;
					PQ.push(Node(i.first, box.bit + j, box.cost + add));
				}
			}
		}
	}
	for (int i = 1; i < N; i++) {
		cout << dis[i].back() << " ";
	}
	cout << endl;
	return;
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
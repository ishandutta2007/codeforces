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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

struct OV_Node {
	long long int a, b;
	int node, turn;
	OV_Node(long long int aa,long long int bb,int id,int pa):a(aa),b(bb),node(id),turn(pa){}
	bool operator<(const OV_Node &n)const {
		return make_pair(a, b) > make_pair(n.a, n.b);
	}
};

struct Node {
	int node, turn, cost;
	Node(int n, int t, int c) :node(n), turn(t), cost(c){}
	bool operator<(const Node&n)const {
		return cost > n.cost;
	}
};

long long int power(long long int x, long long int n, long long int M) {
	long long int ret = 1;
	long long int by = x;
	while (n) {
		if (n & 1) {
			ret *= by;
			ret %= M;
		}
		by *= by;
		by %= M;
		n >>= 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<vector<int>>edge(N);
	vector<vector<int>>rev_edge(N);
	for (int i = 0; i < M; i++) {
		cin >> L >> R;
		L--, R--;
		//	if (i & 1) {
		//		L = i + 1, R = i;
		//	}
		//	else {
		//		L = i, R = i + 1;
		//	}
		edge[L].push_back(R);
		rev_edge[R].push_back(L);
	}
	vector<vector<long long int>>dis(N, vector<long long int>(51, MOD*MOD));
	dis[0][0] = 0;
	vector<vector<pair<long long int, long long int>>>ov_dis(N, vector<pair<long long int, long long int>>(2, { MOD,MOD }));
	priority_queue<OV_Node>OV_PQ;
	priority_queue<Node>PQ;
	PQ.push(Node(0, 0, 0));
	while (!PQ.empty()) {
		auto box = PQ.top();
		PQ.pop();
		if (dis[box.node][box.turn] < box.cost)continue;
		if (box.turn & 1) {
			for (auto i : edge[box.node]) {
				if (dis[i][box.turn + 1] > box.cost + 1) {
					dis[i][box.turn + 1] = box.cost + 1;
					PQ.push(Node(i, box.turn + 1, box.cost + 1));
				}
			}
			for (auto i : rev_edge[box.node]) {
				if (dis[i][box.turn] > box.cost + 1) {
					dis[i][box.turn] = box.cost + 1;
					PQ.push(Node(i, box.turn, box.cost + 1));
				}
			}
		}
		else {
			for (auto i : rev_edge[box.node]) {
				if (box.turn + 1 > 50) {
					if (ov_dis[i][1] > make_pair(51LL, box.cost + 1LL)) {
						ov_dis[i][1] = make_pair(51LL, box.cost + 1LL);
						OV_PQ.push(OV_Node(51, box.cost + 1, i, 1));
					}
				}
				else {
					if (dis[i][box.turn + 1] > box.cost + 1) {
						dis[i][box.turn + 1] = box.cost + 1;
						PQ.push(Node(i, box.turn + 1, box.cost + 1));
					}
				}
			}
			for (auto i : edge[box.node]) {
				if (dis[i][box.turn] > box.cost + 1) {
					dis[i][box.turn] = box.cost + 1;
					PQ.push(Node(i, box.turn, box.cost + 1));
				}
			}
		}
	}
	while (!OV_PQ.empty()) {
		auto box = OV_PQ.top();
		OV_PQ.pop();
		if (ov_dis[box.node][box.turn] < make_pair(box.a, box.b))continue;
		if (box.turn) {
			for (auto i : edge[box.node]) {
				if (ov_dis[i][0] > make_pair(box.a + 1, box.b + 1)) {
					ov_dis[i][0] = make_pair(box.a + 1, box.b + 1);
					OV_PQ.push(OV_Node(box.a + 1, box.b + 1, i, 0));
				}
			}
			for (auto i : rev_edge[box.node]) {
				if (ov_dis[i][1] > make_pair(box.a, box.b + 1)) {
					ov_dis[i][1] = make_pair(box.a, box.b + 1);
					OV_PQ.push(OV_Node(box.a, box.b + 1, i, 1));
				}
			}
		}
		else {
			for (auto i : rev_edge[box.node]) {
				if (ov_dis[i][1] > make_pair(box.a + 1, box.b + 1)) {
					ov_dis[i][1] = make_pair(box.a + 1, box.b + 1);
					OV_PQ.push(OV_Node(box.a + 1, box.b + 1, i, 1));
				}
			}
			for (auto i : edge[box.node]) {
				if (ov_dis[i][0] > make_pair(box.a, box.b + 1)) {
					ov_dis[i][0] = make_pair(box.a, box.b + 1);
					OV_PQ.push(OV_Node(box.a, box.b + 1, i, 0));
				}
			}
		}
	}
	long long int ans = MOD * MOD;
	for (int i = 0; i <= 50; i++) {
		ans = min(ans, dis.back()[i] + (1LL << i) - 1);
	}
	if (ans != MOD * MOD) {
		cout << ans % MOD << endl;
		return 0;
	}
	auto ret = make_pair(MOD, MOD);
	ret = min(ret, ov_dis.back()[0]);
	ret = min(ret, ov_dis.back()[1]);
	//cout << ret.first << " " << ret.second << endl;
	ans = power(2, ret.first, MOD) + MOD - 1;
	ans += ret.second;
	ans %= MOD;
	cout << ans << endl;
}
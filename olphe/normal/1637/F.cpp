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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

struct Node {
	long long sum;
	int mx;
	Node(long long sum = LLONG_MAX / 5, long long mx = INT_MIN / 5) :sum(sum), mx(mx) {
	}
	bool operator<(const Node& n)const {
		return make_pair(sum, -mx) < make_pair(n.sum, -n.mx);
	}
};

void func(vector<vector<int>>& edge, vector<vector<Node>>& dp, vector<int>& v, int node = 0, int p = -1) {
	bool leaf = true;
	long long sum = 0;
	int mx = 0;
	long long mxone = 0;
	long long mxtwo = 0;
	for (auto i : edge[node]) {
		if (i == p)continue;
		func(edge, dp, v, i, node);
		leaf = false;
		sum += dp[i][0].sum + dp[i][0].mx;
		mx = max(mx, dp[i][0].mx);
		long long box = -(dp[i][1].sum - dp[i][0].sum - dp[i][0].mx);
		if (mxone < box) {
			mxtwo = mxone;
			mxone = box;
		}
		else if (mxtwo < box) {
			mxtwo = box;
		}

	}
	if (leaf) {
		dp[node][0] = Node(0, v[node]);
		dp[node][1] = Node(0, 0);
	}
	else {
		dp[node][0] = Node(sum - mx, max(mx, v[node]));
		dp[node][1] = Node(sum - mxone, 0);
	}
	if (p == -1) {
		dp[node][2] = Node(sum - mxone - mxtwo, 0);
	}
}

void Solve() {
	cin >> N;
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	vector<vector<int>>edge(N);
	for (int i = 1; i < N; i++) {
		cin >> L >> R;
		L--, R--;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	int st = 0;
	int mx = *max_element(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		if (v[i]==mx) {
			st = i;
		}
	}
	long long ans = mx * 2;
	vector<vector<Node>>dp(N, vector<Node>(3));
	func(edge, dp, v, st);
	ans += min(dp[st][2].sum, dp[st][1].sum);
	cout << ans << endl;
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
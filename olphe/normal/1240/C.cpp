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
#include "functional"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

struct Edge {
	int to, cost;
	Edge(const int tt, const int cc) {
		to=tt, cost = cc;
		return;
	}
};

void Calculate_Depth(vector<vector<Edge>>&edge, vector<int>&depth, int stnode) {
	depth[stnode] = 0;
	queue<int>Q;
	Q.push(stnode);
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		for (auto i : edge[cn]) {
			if (depth[i.to] > depth[cn] + 1) {
				depth[i.to] = depth[cn] + 1;
				Q.push(i.to);
			}
		}
	}
	return;
}

void Search(vector<vector<Edge>>&edge, vector<int>&depth, vector<vector<long long int>>&dp, int node) {
	//cout << node << endl;
	dp[node][0] = dp[node][1] = 0;
	long long int p = 0, q = 0;
	long long int sum = 0;
	vector<long long int>dif;
	long long int upcost = 0;
	for (auto i : edge[node]) {
	//	cout << i.to << endl;
		if (depth[i.to] < depth[node]) {
			upcost = i.cost;
			continue;
		}
		Search(edge, depth, dp, i.to);
		sum += dp[i.to][0];
		dif.push_back(dp[i.to][1] - dp[i.to][0]);
	}
	//cout << "hoge " << endl;
	sort(dif.begin(), dif.end());
	//cout << "fuga" << endl;
	//cout<< ((int)edge[node].size()) - M << endl;
	for (int i = 0; i < ((int)edge[node].size()) - M - 1; i++) {
		p += dif[i];
	}
	q = p;
	if (((int)edge[node].size()) - M -1>= 0&& ((int)edge[node].size()) - M-1<dif.size())q += dif[((int)edge[node].size()) - M-1];
	dp[node][0] = sum + q;
	dp[node][1] = sum + p + upcost;
	if(node)dp[node][0] = min(dp[node][0], dp[node][1]);
	//cout <<"Search "<< node << " " << dp[node][0] << " " << dp[node][1] << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N >> M;
		vector<vector<Edge>>edge(N);
		long long int ans = 0;
		for (int i = 1; i < N; i++) {
			cin >> L >> R >> H;
			L--;
			R--;
			edge[L].push_back(Edge(R, H));
			edge[R].push_back(Edge(L, H));
			ans += H;
		}
		vector<vector<long long int>>dp(N, vector<long long int>(2, MOD*MOD));
		vector<int>depth(N, MOD);
		Calculate_Depth(edge, depth, 0);
		//cout << ans << endl;
		Search(edge, depth, dp, 0);
		for (int i = 0; i < N; i++) {
		//	cout << i << " " << dp[i][0] << " " << dp[i][1] << endl;
		}
		ans -= dp[0][0];
		cout << ans << endl;
	}
}
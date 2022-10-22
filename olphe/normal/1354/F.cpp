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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

struct Node {
	long long int a, b, index;
	bool operator<(const Node&n)const {
		return b < n.b;
	}
	void Input() {
		cin >> a >> b;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N >> M;
		vector<Node>nnode(N);
		for (int i = 0; i < N; i++) {
			nnode[i].Input();
			nnode[i].index = i + 1;
		}
		sort(nnode.begin(), nnode.end());
		vector<int>ans;
		long long int cscore = -MOD;
		for (int loop = 0; loop < N; loop++) {
			vector<Node>node;
			for (int i = 0; i < N; i++) {
				if (i != loop)node.push_back(nnode[i]);
			}
			node.push_back(nnode[loop]);
			vector<vector<long long int>>dp(N + 1, vector<long long int>(N + 1, -MOD * MOD));
			dp[0][0] = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] - (M-1-j) * node[i].b);
					dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - node[i].a );
				}
			}
			vector<int>num(M + 1);
			vector<int>waste;
			int p = M - 1;
			for (int i = N-1; i > 0; i--) {
				if (dp[i][p] == dp[i - 1][p] - node[i - 1].a)waste.push_back(node[i - 1].index);
				else {
					num[p] = node[i - 1].index;
					p--;
				}
			}
			long long int score = dp[N - 1][M - 1];
			//score += (M - 1)*node.back().b;
			num.back() = node.back().index;
		//	cout << loop << " " << score << endl;
			if (cscore < score) {
				cscore = score;
				ans.clear();
				for (int i = 1; i < M; i++) {
					ans.push_back(num[i]);
				}
				for (auto i : waste) {
					ans.push_back(i);
					ans.push_back(-i);
				}
				ans.push_back(num.back());
			}
		}
		cout << ans.size() << endl;
		for (auto i : ans)cout << i << " ";
		cout << endl;
	}
}
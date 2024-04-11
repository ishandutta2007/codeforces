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
constexpr double EPS = 1e-5;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

//int dist(vector<int>)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N + 1, 1);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	int num = 0;
	vector<int>w;
	for (auto i : v) {
		if (i == 1) {
			w.push_back(num);
			M += num;
			num = 0;
		}
		else {
			num++;
		}
	}
	int ans = M * M;
	for (auto i : w) {
		ans -= i * i;
	}
	ans /= 2;
	K = (N - 1)*N / 2;
	vector<long long int>ret(N*(N - 1) / 2+1);
	ret[0] = ans;
	vector<vector<int>>dp(M*M + 1, vector<int>(M + 1, MOD));
	dp[0][0] = 0;
	int bef = 0;
	for (auto num : w) {
		vector<vector<int>>ndp(M*M + 1, vector<int>(M + 1, MOD));
		for (int i = 0; i <= M * M; i++) {
			for (int j = 0; j <= M; j++) {
				if (dp[i][j] == MOD)continue;
				for (int k = j; k <= M; k++) {
					ndp[i + (k - j)*(k - j)][k] = min(ndp[i + (k - j)*(k - j)][k], dp[i][j] + abs(j - bef));
				}
			}
		}
		dp = ndp;
		bef += num;
	}
	for (int i = 0; i <= M * M; i++) {
		for (int j = M; j <= M; j++) {
			if (dp[i][j] <= K) {
				ret[dp[i][j]] = max(ret[dp[i][j]], (M*M - i) / 2);
			}
		}
	}
	for (int i = 1; i <= K; i++)ret[i] = max(ret[i], ret[i - 1]);
	for (auto i : ret) {
		cout << i << " ";
	}
	cout << endl;
}
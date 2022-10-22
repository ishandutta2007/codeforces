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
constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N+1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}
	vector<int>b(N);
	for (int i = 1; i < N; i++) {
		cin >> b[i];
	}
	cin >> K;
	while (K--) {
		cin >> M;
		vector<vector<vector<long long>>>dp(N + 1, vector<vector<long long>>(10001, vector<long long>(2)));
		for (int i = 0; i <= v[1]; i++) {
			dp[1][i][i >= M] = 1;
		}
		long long sum = 0;
		long long add = 0;
		for (int i = 1; i < N; i++) {
			add += b[i];
			sum += add;
			//cout << i << " " << sum << endl;
			for (int j = 0; j <= 9900; j++) {
				for (int k = 0; k < 2; k++) {
					if (dp[i][j][k] == 0)continue;
				//	cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
					for (int l = 0; l <= v[i + 1]; l++) {
						int nk = k & (j + l >= (i + 1)* M + sum);
						dp[i + 1][j + l][nk] += dp[i][j][k];
						dp[i + 1][j + l][nk] %= MOD;
					}

				}
			}
		}
		long long ans = 0;
		for (int i = 0; i <= 10000; i++) {
			ans += dp[N][i][1];
			ans %= MOD;
		}
		cout << ans << endl;
	}
}
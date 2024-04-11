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

using namespace std;

//constexpr long long int MOD = 1000000007;
constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

int N, M, K, H, W, L, R;
//long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<string>s(N);
	for (auto &i : s)cin >> i;
	vector<vector<int>>sum(N+1, vector<int>(N+1));
	vector<int>l(N, MOD);
	vector < int>r(N, -MOD);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (s[i][j] == 'B') {
				l[i] = min(l[i], j);
				r[i] = max(r[i], j);
			}
		}
	}
	vector<int>d(N, MOD);
	vector<int>u(N, -MOD);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (s[i][j] == 'B') {
				d[j] = min(d[j], i);
				u[j] = max(u[j], i);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (l[i] == MOD) {
			sum[0][0]++;
			sum[N - M+1][0]--;
			sum[0][N - M+1]--;
			sum[N - M+1][N - M+1]++;
		}
		else if (r[i] - l[i] < M) {
			sum[max(0, i - M + 1)][max(0, r[i] - M + 1)]++;
			sum[max(0, i - M + 1)][min(N - M+1, l[i] + 1)]--;
			sum[min(N - M+1, i + 1)][max(0, r[i] - M + 1)]--;
			sum[min(N - M+1, i + 1)][min(N - M+1, l[i] + 1)]++;
		}
		if (d[i] == MOD) {
			sum[0][0]++;
			sum[N - M+1][0]--;
			sum[0][N - M+1]--;
			sum[N - M+1][N - M+1]++;
		}
		else if (u[i] - d[i] < M) {
			sum[max(0, u[i] - M + 1)][max(0, i - M + 1)]++;
			sum[min(N - M+1, d[i] + 1)][max(0, i - M + 1)]--;
			sum[max(0, u[i] - M + 1)][min(N - M+1, i + 1)]--;
			sum[min(N - M+1, d[i] + 1)][min(N - M+1, i + 1)]++;
		}
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 1; j <= N; j++)sum[i][j] += sum[i][j - 1];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j++)sum[i][j] += sum[i - 1][j];
	}
	int ans = 0;
	for (auto i : sum)for (auto j : i)ans = max(ans, j);
	cout << ans << endl;
}
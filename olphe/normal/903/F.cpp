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
#include "iomanip"
#include "cmath"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>cost(4);
	vector<vector<int>>v(4, vector<int>(N + 5));
	vector<int>bi(N + 5);
	for (int i = 0; i < 4; i++) {
		cin >> cost[i];
	}
	string s;
	for (int i = 0; i < 4; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == '*') {
				v[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		bi[i] = v[0][i] + (v[1][i] << 1) + (v[2][i] << 2) + (v[3][i] << 3);
	}
	vector<vector<int>>dp(10, vector<int>(65536, INT_MAX));
	vector<queue<int>>Q(10);
	int box = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (v[i][j]) {
				box += pow(2, 4 * j + i);
			}
		}
	}
	dp[0][box] = 0;
	Q[0].push(box);
	for (int i = 0; i < N; i++) {
		while (!Q[i%10].empty()) {
			int cn = Q[i % 10].front();
			Q[i % 10].pop();
			if ((cn & 15) == 0) {
				int nn= (cn >> 4) + (bi[i + 4] << 12);
				if (dp[(i + 1) % 10][nn] > dp[i % 10][cn]) {
					dp[(i + 1) % 10][nn] = dp[i % 10][cn];
					Q[(i + 1) % 10].push(nn);
				}
			}
			if (dp[i % 10][0] > dp[i % 10][cn] + cost[3]) {
				dp[i % 10][0] = dp[i % 10][cn] + cost[3];
				Q[i % 10].push(0);
			}
			for (int j = 0; j < 4; j++) {
				int nn = cn - (cn & (1 << j));
				if (dp[i % 10][nn] > dp[i % 10][cn] + cost[0]) {
					dp[i % 10][nn] = dp[i % 10][cn] + cost[0];
					Q[i % 10].push(nn);
				}
			}
			for (int j = 0; j < 3; j++) {
				int nn = cn - (cn & (1 << j)) - (cn & (1 << (j + 1))) - (cn & (1 << (j + 4))) - (cn & (1 << (j + 5)));
				if (dp[i % 10][nn] > dp[i % 10][cn] + cost[1]) {
					dp[i % 10][nn] = dp[i % 10][cn] + cost[1];
					Q[i % 10].push(nn);
				}
			}
			for (int j = 0; j < 2; j++) {
				int nn = cn - (cn & (1 << j)) - (cn & (1 << (j + 1))) - (cn & (1 << (j + 2))) - (cn & (1 << (j + 4))) - (cn & (1 << (j + 5))) - (cn & (1 << (j + 6))) - (cn & (1 << (j + 8))) - (cn & (1 << (j + 9))) - (cn & (1 << (j + 10)));
				if (dp[i % 10][nn] > dp[i % 10][cn] + cost[2]) {
					dp[i % 10][nn] = dp[i % 10][cn] + cost[2];
					Q[i % 10].push(nn);
				}
			}
		}
		if (i + 10 < N) {
			for (int j = 0; j < 65536; j++) {
				dp[i % 10][j] = INT_MAX;
			}
		}
	}
	cout << dp[(N - 1) % 10][0] << endl;
	return 0;
}
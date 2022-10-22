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

using namespace std;

const long long  int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<vector<int>>>dp(31, vector<vector<int>>(31, vector<int>(51, MOD)));
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= i; j++) {
			dp[1][i][j] = 1;
			dp[i][1][j] = 1;
		}
	}
	for (int i = 0; i <= 30; i++) {
		for (int j = 0; j <= 30; j++)dp[i][j][0] = 0;
	}
	for (int i = 0; i <= 30; i++) {
		for (int j = 0; j <= 30; j++) {
			if (i*j <= 50)dp[i][j][i*j] = 0;
		}
	}
	for (int i = 2; i <= 30; i++) {
		for (int j = i; j <= 30; j++) {
			for (int k = 1; k <= 50; k++) {
				for (int l = 1; l < i; l++) {
					int nx = k - j * l;
					//for (int m = 0; m <= nx; m++) {
						if(nx>=0)dp[i][j][k] = min(dp[i][j][k], dp[l][j][0] + dp[i - l][j][nx] + j*j);
					//}
					for (int m = 0; m <= k; m++) {
						dp[i][j][k] = min(dp[i][j][k], dp[l][j][m] + dp[i - l][j][k - m] + j*j);
					}
					nx = k - j * (i - l);
					//for (int m = 0; m <= nx; m++) {
						if(nx>=0)dp[i][j][k] = min(dp[i][j][k], dp[l][j][nx] + dp[i - l][j][0] + j*j);
					//}
				}
				for (int l = 1; l < j; l++) {
					int nx = k - i * l;
					//for (int m = 0; m <= nx; m++) {
						if(nx>=0)dp[i][j][k] = min(dp[i][j][k], dp[i][l][0] + dp[i][j - l][nx] + i*i);
					//}
					for (int m = 0; m <= k; m++) {
						dp[i][j][k] = min(dp[i][j][k], dp[i][l][m] + dp[i][j - l][k - m] + i*i);
					}
					nx = k - i * (j - l);
					//for (int m = 0; m <= nx; m++) {
						if(nx>=0)dp[i][j][k] = min(dp[i][j][k], dp[i][l][nx] + dp[i][j - l][0] + i*i);
					//}
				}
				dp[j][i][k] = dp[i][j][k];
			}
		}
	}
	//for (int i = 1; i <= 30; i++) {
	//	for (int j = i; j <= 30; j++) {
	//		for (int k = 1; k <= min(i*j, 50); k++) {
	//			cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
	//		}
	//	}
	//}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> H >> W >> M;
		if (H > W)swap(H, W);
		cout << dp[H][W][M] << endl;
	}
	return 0;
}
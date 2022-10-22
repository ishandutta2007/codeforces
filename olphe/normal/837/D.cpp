#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"
#include "string"
#include "map"
#include "unordered_map"
#include "iomanip"
#include "random"

using namespace std;
const long long int MOD = 1000000007;

long long int power(long long int x, long long int n, long long int M) {
	long long int tmp = 1;

	if (n > 0) {
		tmp = power(x, n / 2, M);
		if (n % 2 == 0) tmp = (tmp*tmp) % M;
		else tmp = (((tmp*tmp) % M)*x) % M;
	}
	return tmp;
}

long long int N, M, K, Q, W, H, L, R;
long long int ans;



int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	int two[1000];
	int five[1000];
	for (int i = 0; i < N; i++) {
		cin >> K;
		while (K % 2 == 0) {
			two[i]++;
			K /= 2;
		}
		while (K % 5 == 0) {
			five[i]++;
			K /= 5;
		}
	}
	int dp[201][6000] = {};
	for (int i = 0; i < 201; i++) {
		for (int j = 0; j < 6000; j++)dp[i][j] = INT_MIN;
	}
	cout <<"" ;
	dp[0][0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 200; j >= 0; j--) {
			for (int k = 5999; k >= 0; k--) {
				if (k >= five[i]&&j) {
					if (dp[j - 1][k - five[i]] != INT_MIN) {
						dp[j][k] = max(dp[j][k], dp[j - 1][k - five[i]] + two[i]);
					}
				}
			}
		}
	}
	for (int i = 0; i < 6000; i++) {
		ans = max((int)ans, min(i, dp[M][i]));
	}
	cout << ans << endl;
	return 0;
}
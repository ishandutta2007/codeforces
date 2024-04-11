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
#include "map"

using namespace std;
const long long int MOD = 1000000007;

int N, K, X;
int dp[2][1024];
int box;
int m[1024];
int a, b;

int main() {
	cin >> N >> K >> X;
	for (int i = 0; i < N; i++) {
		cin >> box;
		dp[0][box]++;
	}
	for (int i = 0; i < 1024; i++) {
		m[i] = (i^X);
	}
	a = 0;
	b = 100000;
	box = 0;
	for (int i = 1; i <= K; i++) {
		box = 0;
		for (int j = 0; j < 1024; j++) {
			if (dp[(i - 1) % 2][j] % 2) {
				if (box % 2) {
					dp[i % 2][j] += (dp[(i - 1) % 2][j] + 1) / 2;
					dp[i % 2][m[j]] += (dp[(i - 1) % 2][j]) / 2;
				}
				else {
					dp[i % 2][m[j]] += (dp[(i - 1) % 2][j] + 1) / 2;
					dp[i % 2][j] += (dp[(i - 1) % 2][j]) / 2;
				}
			}
			else {
				dp[i % 2][m[j]] += (dp[(i - 1) % 2][j]) / 2;
				dp[i % 2][j] += (dp[(i - 1) % 2][j]) / 2;
			}
			box += dp[(i - 1) % 2][j];
			dp[(i - 1) % 2][j] = 0;
		}
	}
	for (int i = 0; i < 1024; i++) {
		if (dp[K % 2][i]) {
			a = max(a, i);
			b = min(b, i);
		}
	}
	cout << a << " " << b << endl;
	return 0;
}
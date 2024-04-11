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
	cin >> N >> Q >> K;
	int num[101][101][11] = {};
	for (int i = 0; i < N; i++) {
		int x, y, s;
		cin >> x >> y >> s;
		num[x][y][s]++;
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			for (int k = 0; k <= K; k++) {
				num[i][j][k] += num[i][j - 1][k];
			}
		}
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			for (int k = 0; k <= K; k++) {
				num[i][j][k] += num[i - 1][j][k];
			}
		}
	}
	for (int i = 0; i < Q; i++) {
		int t, sx, sy, gx, gy;
		cin >> t >> sx >> sy >> gx >> gy;
		ans = 0;
		for (int j = 0; j <= K; j++) {
			int box = 0;
			box = num[gx][gy][j];
			box -= num[gx][sy - 1][j];
			box -= num[sx - 1][gy][j];
			box += num[sx - 1][sy - 1][j];
			ans += box*((j + t) % (K + 1));
		}
		cout << ans << endl;
	}
	return 0;
}
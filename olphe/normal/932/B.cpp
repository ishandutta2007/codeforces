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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<int>>sum(10, vector<int>(1000001));
	for (int i = 1; i <= 1000000; i++) {
		int box = i;
		while (box >= 10) {
			int bag = 1;
			while (box) {
				if (box % 10==0) {
					box /= 10;
					continue;
				}
				bag *= box % 10;
				box /= 10;
			}
			box = bag;
		}
		sum[box][i]++;
	}
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j <= 1000000; j++) {
			sum[i][j] += sum[i][j - 1];
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> L >> R >> K;
		cout << sum[K][R] - sum[K][L - 1] << endl;
	}
	return 0;
}
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
#include "iomanip"
#include "random"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 0.00000001;

long long int N, M, K, W, H, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin >> H >> W;
	int num[100][100] = {};
	long long int two[55] = {};
	two[0] = 1;
	for (int i = 1; i <= 50; i++) {
		two[i] = two[i - 1] * 2;
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> num[i][j];
		}
	}
	K = H*W;
	for (int i = 0; i < H; i++) {
		int box = 0;
		for (int j = 0; j < W; j++) {
			box += num[i][j];
		}
		if (box > 1) {
			K += two[box];
			K--;
			K -= box;
		}
		if (W - box > 1) {
			K += two[W - box];
			K--;
			K -= W-box;
		}
	}
	for (int i = 0; i < W; i++) {
		int box = 0;
		for (int j = 0; j < H; j++) {
			box += num[j][i];
		}
		if (box > 1) {
			K += two[box];
			K--;
			K -= box;
		}
		if (H - box > 1) {
			K += two[H - box];
			K--;
			K -= H-box;
		}
	}
	cout << K << endl;
	return 0;
}
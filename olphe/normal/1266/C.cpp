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

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W;
	if (H == 1 && W == 1) {
		cout << 0 << endl;
		return 0;
	}
	if (H == 1) {
		for (int i = 0; i < W; i++) {
			cout << i + 2 << " ";
		}
		cout << endl;
		return 0;
	}
	if (W == 1) {
		for (int i = 0; i < H; i++) {
			cout << i + 2 << endl;
		}
		return 0;
	}
	for (int i = 1; i <= H; i++) {
		for (int j = H + 1; j <= H + W; j++) {
			cout << i * j << " ";
		}
		cout << endl;
	}
}
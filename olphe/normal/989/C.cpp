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

	cin >> N >> M >> L >> R;
	H = 50;
	W = 50;
	vector<string>v(H);
	for (int i = 0; i < H; i++) {
		v[i].resize(W);
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W / 2; j++) {
			if (i % 2 && j % 2)continue;
			v[i][j] = 'A';
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = W / 2; j < W; j++) {
			if (i % 2 && j % 2 == 0)continue;
			v[i][j] = 'B';
		}
	}
	N--;
	M--;
	for (int i = 1; i < H; i += 2) {
		for (int j = 1; j < W/2; j += 2) {
			if (M) {
				v[i][j] = 'B';
				M--;
			}
			else if (R) {
				v[i][j] = 'D';
				R--;
			}
			else {
				v[i][j] = 'A';
			}
		}
	}
	for (int i = 1; i < H; i+=2) {
		for (int j = 26; j < W; j += 2) {
			if (N) {
				v[i][j] = 'A';
				N--;
			}
			else if (L) {
				v[i][j] = 'C';
				L--;
			}
			else {
				v[i][j] = 'B';
			}
		}
	}
	cout << H << " " << W << endl;
	for (auto i : v) {
		cout << i << endl;
	}
	return 0;
}
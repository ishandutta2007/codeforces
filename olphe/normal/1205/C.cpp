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

void rev_out(vector<vector<int>>&v) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << (v[i][j] + ((i + j) & 1)) % 2;
		}
		cout << endl;
	}
}

void norev_out(vector<vector<int>>&v) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << (v[i][j]);
		}
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<vector<int>>v(N, vector<int>(N, -1));
	v[0][0] = 1;
	v.back().back() = 0;
	for (int i = 2; i < N; i += 2) {
		cout << "? " << 1 << " " << i - 1 << " " << 1 << " " << i + 1 << endl;
		cin >> v[0][i];
		v[0][i] ^= v[0][i - 2] ^ 1;
	}
	for (int i = 1; i < N; i += 2) {
		cout << "? " << 1 << " " << i << " " << 2 << " " << i + 1 << endl;
		cin >> v[1][i];
		v[1][i] ^= v[0][i - 1] ^ 1;
	}
	for (int i = 2; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((i + j) & 1)continue;
			cout << "? " << i - 1 << " " << j + 1 << " " << i + 1 << " " << j + 1 << endl;
			cin >> v[i][j];
			v[i][j] ^= v[i - 2][j] ^ 1;
		}
	}
	v[0][1] = 0;
	for (int i = 3; i < N; i += 2) {
		cout << "? " << 1 << " " << i - 1 << " " << 1 << " " << i + 1 << endl;
		cin >> v[0][i];
		v[0][i] ^= v[0][i - 2] ^ 1;
	}
	cout << "? " << 1 << " " << 2 << " " << 2 << " " << 3 << endl;
	cin >> v[1][2];
	v[1][2] ^= v[0][1] ^ 1;
	cout << "? " << 2 << " " << 1 << " " << 2 << " " << 3 << endl;
	cin >> v[1][0];
	v[1][0] ^= v[1][2] ^ 1;
	for (int i = 4; i < N; i += 2) {
		cout << "? " << 2 << " " << i - 1 << " " << 2 << " " << i + 1 << endl;
		cin >> v[1][i];
		v[1][i] ^= v[1][i - 2] ^ 1;
	}
	for (int i = 2; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((i + j) & 1) {
				cout << "? " << i - 1 << " " << j + 1 << " " << i + 1 << " " << j + 1 << endl;
				cin >> v[i][j];
				v[i][j] ^= v[i - 2][j] ^ 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//if ((i + j) & 1)continue;
			for (int k = i; k < N; k++) {
				for (int l = j; l < N; l++) {
					if (k + l - i - j != 3)continue;
					bool a = false, b = false;
					if (i + 3 == k) {
						a = v[i][j] == v[k][j] && v[i + 1][j] == v[k - 1][j];
						b = v[i][j] == (v[k][j] ^ 1) && (v[i + 1][j] ^ 1) == v[k - 1][j];
					}
					else if (i + 2 == k) {
						a |= v[i][j] == v[k][l] && v[i + 1][j] == v[i + 2][j];
						a |= v[i][j] == v[k][l] && v[i + 1][j] == v[i + 1][l];
						a |= v[i][j] == v[k][l] && v[i][l] == v[i + 1][l];
						b |= v[i][j] == (v[k][l] ^ 1) && (v[i + 1][j] ^ 1) == v[i + 2][j];
						b |= v[i][j] == (v[k][l] ^ 1) && (v[i + 1][j] ^ 1) == v[i + 1][l];
						b |= v[i][j] == (v[k][l] ^ 1) && (v[i][l] ^ 1) == v[i + 1][l];
					}
					else if (i + 1 == k) {
						a |= v[i][j] == v[k][l] && v[i][j + 1] == v[i][j + 2];
						a |= v[i][j] == v[k][l] && v[i][j + 1] == v[i + 1][j + 1];
						a |= v[i][j] == v[k][l] && v[i + 1][j] == v[i + 1][j + 1];
						b |= v[i][j] == (v[k][l] ^ 1) && (v[i][j + 1] ^ 1) == v[i][j + 2];
						b |= v[i][j] == (v[k][l] ^ 1) && (v[i][j + 1] ^ 1) == v[i + 1][j + 1];
						b |= v[i][j] == (v[k][l] ^ 1) && (v[i + 1][j] ^ 1) == v[i + 1][j + 1];
					}
					else {
						a = v[i][j] == v[k][l] && v[i][j + 1] == v[k][l - 1];
						b = v[i][j] == (v[k][l] ^ 1) && (v[i][j + 1] ^ 1) == v[k][l - 1];
					}
					if (a != b) {
						cout << "? " << i + 1 << " " << j + 1 << " " << k + 1 << " " << l + 1 << endl;
						cin >> M;
						if (M^a ^ 1) {
							cout << "!" << endl;
							norev_out(v);
							return 0;
						}
						else {
							cout << "!" << endl;
							rev_out(v);
							return 0;
						}
					}
				}
			}
		}
	}
}
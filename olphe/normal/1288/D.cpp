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
constexpr long double EPS = 1e-12;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<vector<int>>v(N, vector<int>(M));
	for (auto &i : v)for (auto &j : i)cin >> j;
	L = -1, R = MOD;
	int a = 0, b = 0;
	while (R - L > 1) {
		int mid = (R + L) / 2;
		vector<int>box(1 << M);
		for (int i = 0; i < N; i++) {
			int bag = 0;
			for (int j = 0; j < M; j++) {
				bag <<= 1;
				bag |= v[i][j] >= mid;
			}
			box[bag] = i+1;
		}
		bool flag = false;
		for (int i = 0; i < 1 << M; i++) {
			for (int j = i; j < 1 << M; j++) {
				if ((i | j) == (1 << M) - 1) {
					if (box[i] && box[j]) {
						flag = true;
						a = box[i], b = box[j];
					}
				}
			}
		}
		if (flag)L = mid;
		else R = mid;
	}
	cout << a << " " << b << endl;
	return 0;
}
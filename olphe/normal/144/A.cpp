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
#include "ctime"

using namespace std;

const long long int MOD = 1000000007;
//const long long  int MOD = 998244353;
//long long int N, M, K, H, W, L, R;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>v(N);
	L = MOD;
	R = 0;
	for (auto &i : v) {
		cin >> i;
		R = max(R, i);
		L = min(L, i);
	}
	while (v[0] != R) {
		for (int i = 1; i < N; i++) {
			if (v[i] == R) {
				swap(v[i], v[i - 1]);
				K++;
				break;
			}
		}
	}
	while (v.back() != L) {
		for (int i = N-2; i >=0 ; i--) {
			if (v[i] == L) {
				swap(v[i], v[i + 1]);
				K++;
				break;
			}
		}
	}
	cout << K << endl;
	return 0;
}
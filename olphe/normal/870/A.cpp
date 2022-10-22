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

	cin >> N >> M;
	vector<int>v(10);
	vector<int>w(10);
	for (int i = 0; i < N; i++) {
		cin >> K;
		v[K]++;
	}
	for (int i = 0; i < M; i++) {
		cin >> K;
		w[K]++;
	}
	for (int i = 1; i <= 9; i++) {
		if (v[i] && w[i]) {
			cout << i << endl;
			return 0;
		}
	}
	for (int i = 1; i <= 10; i++) {
		if (v[i]) {
			for (int j = 1; j <= 10; j++) {
				if (w[j]) {
					cout << min(i, j) << max(i, j) << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
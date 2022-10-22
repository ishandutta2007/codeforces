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

	cin >> N >> M >> K;
	bool flag = false;
	int box = 0;
	for (int i = 0; i <= N; i += M) {
		if ((N - i) % K == 0) {
			flag = true;
			box = i;
			break;
		}
	}
	if (!flag) {
		cout << -1 << endl;
		return 0;
	}
	vector<int>v(N);
	for (int i = 0; i < box / M; i++) {
		for (int j = 0; j < M; j++) {
			v[i*M + j] = i*M + j - 1;
		}
		v[i*M] += M;
	}
	int bag = box;
	for (int i = bag; i < N; i++) {
		v[i] = i - 1;
		if ((i - bag) % K == 0) {
			v[i] += K;
		}
	}
	for (auto i : v) {
		cout << i + 1 << " ";
	}
	cout << endl;
	return 0;
}
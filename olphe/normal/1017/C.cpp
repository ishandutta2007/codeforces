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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int length = 1;
	for (int i = 1; i <= N; i++) {
		if (length + N / length + !!(N%length) > i + N / i + !!(N%i)) {
			length = i;
		}
	}
	vector<int>ans;
	vector<int>box;
	for (int i = 0; i < length; i++) {
		if (i < N%length) {
			box.push_back(N / length + 1);
		}
		else {
			box.push_back(N / length);
		}
	}
	int c = N;
	for (auto i : box) {
		for (int j = 0; j < i; j++) {
			ans.push_back(c - i + j + 1);
		}
		c -= i;
	}
	for (auto i : ans) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
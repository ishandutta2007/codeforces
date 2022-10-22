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
#include "iomanip"
#include "cmath"
#include "random"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (v[i] > v[j]) {
				ans++;
			}
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> L >> R;
		int dis = R - L;
		int box = dis*(dis + 1) / 2;
		if (box % 2) {
			ans++;
		}
		if (ans % 2) {
			cout << "odd\n";
		}
		else {
			cout << "even\n";
		}
	}
	return 0;
}
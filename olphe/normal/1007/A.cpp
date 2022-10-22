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

	cin >> N;
	vector<int>a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ans = 0;
	int index = 0;
	for (int i = 0; i < N; i++) {
		while (index < N&&a[index] <= a[i]) {
			index++;
		}
		if (index < N) {
			ans++;
			index++;
		}
	}
	cout << ans << endl;
	return 0;
}
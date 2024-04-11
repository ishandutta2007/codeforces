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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	map<int, int>m;
	for (int i = 0; i < N; i++) {
		cin >> M;
		m[M]++;
	}
	int ans = 0;
	for (auto i : m) {
		ans = max(ans, i.second);
	}
	cout << ans << endl;
	return 0;
}
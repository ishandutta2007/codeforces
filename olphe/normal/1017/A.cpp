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
	vector<int>sum(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> M;
			sum[i] += M;
		}
	}
	int ans = 1;
	for (int i = 1; i < N; i++) {
		if (sum[0] < sum[i])ans++;
	}
	cout << ans << endl;
	return 0;
}
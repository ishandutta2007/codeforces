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
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	vector<long long int>v(N+2);
	int ans = 0;
	for (int i = 1; i <= N;i++) {
		cin >> v[i];
		if (v[i] > K) {
			ans++;
			if (v[i - 1] > K)ans--;
		}
	}
	for (int loop = 0; loop < M; loop++) {
		cin >> L;
		if (!L) {
			cout << ans << endl;
			continue;
		}
		cin >> H >> W;
		if (v[H] <= K && v[H] + W > K) {
			ans++;
			if (v[H - 1] > K)ans--;
			if (v[H + 1] > K)ans--;
		}
		v[H] += W;
	}
	return 0;
}
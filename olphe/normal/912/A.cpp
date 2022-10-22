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

	cin >> N >> M;
	cin >> K >> L >> R;
	long long int ans = 0;
	ans += max(K * 2, N) - N;
	ans += max(R * 3, M) - M;
	N -= min(N, K * 2);
	M -= min(M, R * 3);
	ans += L - min(L, N);
	ans += L - min(L, M);
	cout << ans << endl;
	return 0;
}
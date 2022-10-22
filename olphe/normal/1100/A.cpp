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
#include "complex"
using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	int ans = 0;
	for (int i = 0; i < K; i++) {
		int box = 0;
		for (int j = 0; j < N; j++) {
			if (i == j % K)continue;
			box += v[j];
		}
		ans = max(ans, abs(box));
	}
	cout << ans << endl;
	return 0;
}
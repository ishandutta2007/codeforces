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

//const long long int MOD = 1000000007;
const long long  int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	long long int ans = 0;
	vector<long long int>by(N + 1, 1);
	for (int i = 2; i <= N; i++) {
		by[i] = by[i - 1] * i;
		by[i] %= MOD;
	}
	ans = by[N];
	long long int box = 1;
	for (int i = 2; i < N; i++) {
		box *= N - i + 2;
		box %= MOD;
		ans += box * (by[N - i + 1] - 1);
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
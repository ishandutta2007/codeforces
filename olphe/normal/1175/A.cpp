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
#include "cassert"

using namespace std;

const long long int MOD = 1000000007;
//const long long int MOD = 1000003;
//const int MOD = 998244353;
//const long long int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> N >> M;
		long long int ans = 0;
		while (N) {
			ans += N % M;
			N /= M;
			ans++;
		}
		ans--;
		cout << ans << endl;
	}

}
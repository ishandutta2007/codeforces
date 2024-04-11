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

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M;
		long long int box = 1;
		while (box <= M)box <<= 1;
		box--;
		if (M != box)cout << box << endl;
		else {
			int ans = 1;
			for (int i = 2; i*i <= M; i++) {
				if ((M - i) % i == 0)ans = max(ans, (int)M / i);
			}
			cout << ans << endl;
		}
	}
}
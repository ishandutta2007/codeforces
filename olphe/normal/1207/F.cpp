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
#include "functional"

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int sum[701][700];
int num[500001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	while (N--) {
		cin >> L >> R >> K;
		if (L == 1) {
			num[R] += K;
			for (int i = 1; i <= 700; i++) {
				sum[i][R%i] += K;
			}
		}
		else {
			if (R <= 700)cout << sum[R][K] << endl;
			else {
				int ans = 0;
				for (int i = K; i <= 500000; i += R)ans += num[i];
				cout << ans << endl;
			}
		}
	}
}
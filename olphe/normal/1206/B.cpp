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
constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

int N, M, K, H, W, L, R;
//long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	long long int ans = 0;
	int num = 0;
	int zero = 0;
	for (int i = 0; i < N; i++) {
		cin >> M;
		if (M > 0)ans += M - 1;
		else if (!M)zero++;
		else {
			num++;
			ans += -1 - M;
		}
	}
	if (zero)ans += zero;
	else if (num & 1)ans += 2;
	cout << ans << endl;
}
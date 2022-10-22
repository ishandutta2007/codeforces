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
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	int ans = 1;
	int t = 10000000;
	for (int i = 0; i < N; i++) {
		cin >> L >> R;
		if (L >= K) {
			if (t >= L) {
				t = L;
				ans = i+1;
			}
		}
		else {
			int dif = K - L + R - 1;
			dif = dif / R * R;
			L += dif;
			if (t >= L) {
				t = L;
				ans = i+1;
			}
		}
	}
	cout << ans << endl;
}
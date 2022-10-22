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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N;
		vector<long long int>a(N);
		vector<long long int>b(N);
		for (int i = 0; i < N; i++) {
			cin >> a[i] >> b[i];
		}
		long long int ans = accumulate(a.begin(), a.end(), 0LL);
		long long int add = MOD * MOD;
		for (int i = 0; i < N; i++) {
			add = min(add, min(b[i], a[(i + 1) % N]));
			ans -= max(0LL, min(b[i] , a[(i + 1) % N]));
		}
		cout << ans + add << endl;
	}
}
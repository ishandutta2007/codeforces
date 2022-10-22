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
constexpr long double EPS = 1e-12;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> M >> N;
		if (N <= M) {
			cout << "YES\n";
			continue;
		}
		int ed = sqrt(N) * 2 + 100;
		bool flag = false;
		for (int i = 0; i <= ed; i++) {
			int sum = i + (N + i) / (i + 1);
			if (sum <= M)flag = true;
		}
		if (flag)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
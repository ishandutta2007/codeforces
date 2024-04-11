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

	cin >> N;
	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> L >> R;
		v[i] = L - R;
	}
	long long int sum = accumulate(v.begin(), v.end(), 0LL);
	int ans = 0;
	long long int score = abs(sum);
	for (int i = 0; i < N; i++) {
		if (score < abs(sum - v[i] * 2)) {
			score = abs(sum - v[i] * 2);
			ans = i + 1;
		}
	}
	cout << ans << endl;
}
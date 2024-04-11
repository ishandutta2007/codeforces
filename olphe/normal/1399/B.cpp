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
constexpr double EPS = 1e-12;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N;
		vector<int>v(N);
		vector<int>w(N);
		for (auto &i : v)cin >> i;
		for (auto &i : w)cin >> i;
		auto a = *min_element(v.begin(), v.end());
		auto b = *min_element(w.begin(), w.end());
		long long int ans = 0;
		for (int i = 0; i < N; i++) {
			ans += max(v[i] - a, w[i] - b);
		}
		cout << ans << endl;
	}
}
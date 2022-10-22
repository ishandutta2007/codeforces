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
		for (auto &i : v)cin >> i;
		int ans = 0;
		vector<int>num(N*2 + 1);
		for (auto i : v)num[i]++;
		for (int i = 1; i <= 2 * N; i++) {
			int box = 0;
			for (int j = 0; j * 2 <= i; j++) {
				if (j * 2 != i)box += min(num[j], num[i - j]);
				else box += num[j] / 2;
			}
			ans = max(ans, box);
		}
		cout << ans << endl;
	}
}
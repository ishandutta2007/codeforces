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
	for (auto &i : v)cin >> i;
	M = accumulate(v.begin(), v.end(), 0);
	if (M == 1) {
		cout << -1 << endl;
		return 0;
	}
	vector<int>w;
	for (int i = 0; i < N; i++) {
		if (v[i])w.push_back(i);
	}
	long long int ans = MOD * MOD;
	for (int i = 1; i *i <= M; i++) {
		if (M%i)continue;
		if (i != 1) {
			int used = 0;
			long long int box = 0;
			for (int k = 0; k < M / i; k++) {
				for (int j = used; j < used + i; j++) {
					box += abs(w[j] - w[used + i / 2]);
				}
				used += i;
			}
			ans = min(ans, box);
		}
		i = M / i;
		int used = 0;
		long long int box = 0;
		for (int k = 0; k < M / i; k++) {
			for (int j = used; j < used + i; j++) {
				box += abs(w[j] - w[used + i / 2]);
			}
			used += i;
		}
		ans = min(ans, box);
		i = M / i;
	}
	cout << ans << endl;
	return 0;
}
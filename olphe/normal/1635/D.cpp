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
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N >> K;
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	sort(v.begin(), v.end());
	set<int>s;
	for (auto i : v) {
		bool flag = true;
		int j = i;
		while (j) {
			if (j & 1) {
				j >>= 1;
			}
			else{
				if (j >> 1 & 1)break;
				j >>= 2;
			}
			if (s.find(j) != s.end())flag = false;
		}
		if (flag) {
			s.insert(i);
		}
	}
	long long ans = 0;
	vector<long long>num(222222);
	num[0] = num[1] = 1;
	for (int i = 2; i < 222222; i++) {
		num[i] = num[i - 1] + num[i - 2];
		num[i] %= MOD;
	}
	for (int i = 1; i < 222222; i++) {
		num[i] += num[i - 1];
		num[i] %= MOD;
	}
	for (auto i : s) {
		int b = 0;
		while (i) {
			b++;
			i >>= 1;
		}
		if (b > K)continue;
		ans += num[K - b];
		ans %= MOD;
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	//cin >> T;
	while (T--) {
		Solve();
	}
}
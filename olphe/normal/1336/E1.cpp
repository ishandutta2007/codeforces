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

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr long double EPS = 1e-8;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;

long long int power(long long int x, long long int n, long long int M) {
	long long int ret = 1;
	long long int by = x;
	while (n) {
		if (n & 1) {
			ret *= by;
			ret %= M;
		}
		by *= by;
		by %= M;
		n >>= 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	for (int i = 34; i >= 0; i--) {
		long long int box = 0;
		for (int j = 0; j < N; j++) {
			if ((v[j] >> i) & 1) {
				bool flag = true;
				for (int k = i + 1; k < 35; k++) {
					if ((v[j] >> k) & 1)flag = false;
				}
				if (!flag)continue;
				box = v[j];
				for (int k = 0; k < N; k++) {
					if (j == k)continue;
					if ((v[k] >> i) & 1)v[k] ^= box;
				}
				break;
			}
		}
	}
	L = 12, R = 35 - L;
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	while (v.back() == 0)v.pop_back();
	K = v.size();
	//assert(K <= M);
	vector<long long int>w;
	vector<long long int>x;
	for (auto i : v) {
		if (i >> L)w.push_back(i);
		else x.push_back(i);
	}
	if (w.size() > R)return 0;
	vector<long long int>num(1 << L);
	vector<vector<long long int>>nnum(R + 1, vector<long long int>(1 << L));
	for (long long int i = 0; i < 1LL << x.size(); i++) {
		long long int xo = 0;
		for (int j = 0; j < x.size(); j++) {
			if ((i >> j) & 1) {
				xo ^= x[j];
			}
		}
		num[xo]++;
	}
	long long int dp[1024*1024*8] = {};
	long long int box = 0;
	for (int i = 0; i < w.size(); i++) {
		for (int j = 0; j < 1LL << i; j++) {
		//	cout << i << " " << j << " " << (j ^ (1LL << i)) << endl;
			//if (j ^ (1LL << i) >= 1LL << w.size())return 0;
			box = max(box, j ^ (1LL << i));
			//if (j ^ (1LL << i) >= 1024 * 1024 * 8)assert(0);
			dp[j ^ (1LL << i)] = dp[j] ^ w[i];
		}
	}
	//if (w.size() > 10) {
	//	cout << w.size() << " " << box << endl;
	//	return 0;
	//}
	for (long long int i = 0; i < 1LL << w.size(); i++) {
		int b = 0;
		for (int j = L; j < 35; j++) {
			b += (dp[i] >> j) & 1;
		}
		dp[i] &= (1 << L) - 1;
		if (b > R)assert(0);
		nnum[b][dp[i]]++;
	}
	vector<long long int>ans(35 + 1);
	for (int i = 0; i < 1 << L; i++) {
		for (int j = 0; j < 1 << L; j++) {
			int xo = i ^ j;
			int add = 0;
			while (xo) {
				add += xo & 1;
				xo >>= 1;
			}
			for (int k = 0; k <= R; k++) {
				ans[k + add] += nnum[k][i] * num[j];
			}
		}
	}
	for (int i = 1; i <= M; i++) {
		ans[i] %= MOD;
		ans[i] *= power(2, N - K, MOD);
		ans[i] %= MOD;
	}
	ans[0] = power(2, N, MOD);
	for (int i = 1; i <= M; i++)ans[0] += MOD - ans[i];
	ans[0] %= MOD;
	for (int i = 0; i <= M; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}
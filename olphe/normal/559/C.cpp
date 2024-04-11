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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R

long long int power(long long int x, long long int n, long long int M) {
	long long int tmp = 1;

	if (n > 0) {
		tmp = power(x, n / 2, M);
		if (n % 2 == 0) tmp = (tmp*tmp) % M;
		else tmp = (((tmp*tmp) % M)*x) % M;
	}
	return tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W >> K;
	vector<pair<int, int>>v(K);
	for (auto &i : v)cin >> i.first >> i.second;
	v.push_back({ H,W });
	sort(v.begin(), v.end());
	vector<long long int>dp(K + 1);
	vector<long long int>by(H + W + 1, 1);
	vector<long long int>rev(H + W + 1, 1);
	for (int i = 2; i <= H + W; i++) {
		by[i] = by[i - 1] * i;
		by[i] %= MOD;
		rev[i] = power(by[i], MOD - 2, MOD);
	}
	for (int i = 0; i <= K; i++) {
		dp[i] = by[v[i].first + v[i].second-2];
		dp[i] *= rev[v[i].first-1];
		dp[i] %= MOD;
		dp[i] *= rev[v[i].second-1];
		dp[i] %= MOD;
		for (int j = 0; j < i; j++) {
			if (v[i].first < v[j].first||v[i].second < v[j].second)continue;
			dp[i] += MOD;
			long long int minus = dp[j];
			minus *= by[v[i].first - v[j].first + v[i].second - v[j].second];
			minus %= MOD;
			minus *= rev[v[i].first - v[j].first];
			minus %= MOD;
			minus *= rev[v[i].second - v[j].second];
			minus %= MOD;
			dp[i] -= minus;
			dp[i] %= MOD;
		}
	}
	cout << dp.back() << endl;
	return 0;
}
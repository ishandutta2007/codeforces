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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	vector<long long int>v(N);
	vector<long long int>w(M);
	vector<long long int>x(K);
	for (auto &i : v)cin >> i;
	for (auto &i : w)cin >> i;
	for (auto &i : x)cin >> i;
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	sort(x.begin(), x.end());
	N = accumulate(v.begin(), v.end(), 0LL);
	M = accumulate(w.begin(), w.end(), 0LL);
	K = accumulate(x.begin(), x.end(), 0LL);
	long long int ans = -MOD * MOD;
	ans = max(ans, N + M + K - min(w[0], (K - x[0] ? K - x[0] : MOD)) * 2 - min(x[0], (M - w[0] ? M - w[0] : MOD))*2) ;
	ans = max(ans, N + M + K - min(w[0], (N - v[0] ? N - v[0] : MOD)) * 2 - min(v[0], (M - w[0] ? M - w[0] : MOD))*2) ;
	ans = max(ans, N + M + K - min(v[0], (K - x[0] ? K - x[0] : MOD)) * 2 - min(x[0], (N - v[0] ? N - v[0] : MOD))*2) ;
	ans = max(ans, N + M - K);
	ans = max(ans, N - M + K);
	ans = max(ans, -N + M + K);
	cout << ans << endl;
}
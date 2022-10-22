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

	cin >> N >> M;
	string s;
	cin >> s;
	vector<int>v(256);
	for (int i = 0; i < M; i++) {
		char a;
		cin >> a;
		v[a]++;
	}
	vector<int>w(N + 1);
	for (int i = 0; i < N; i++) {
		w[i] = v[s[i]];
		if (i) {
			w[i] = (w[i - 1] + w[i])*w[i];
		}
	}
	long long int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (!w[i]) {
			ans += 1LL * w[i - 1] * (w[i - 1] + 1) / 2;
		}
	}
	cout << ans << endl;
}
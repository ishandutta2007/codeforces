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

long long int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(100001);
	for (int i = 0; i < N; i++) {
		cin >> M;
		v[M] = 1;
	}
	for (int i = 1; i <= 100000; i++) {
		if (!v[i])continue;
		for (int j = i * 2; j <= 100000; j += i) {
			if (v[j]) {
				v[i] = 0;
				break;
			}
		}
	}
	vector<int>w;
	for (int i = 1; i <= 100000; i++) {
		if (v[i])w.push_back(i);
	}
	reverse(w.begin(), w.end());
	long long int ans = w.back();
	for (int i = 0; i < w.size(); i++) {
		int bef = MOD;
		for (int j = i + 1; j < w.size(); j++) {
			if (ans >= 1LL * w[i] * w[j])break;
			if (w[j] % bef == 0)continue;
			int c = gcd(w[i], w[j]);
			if (bef <= c)continue;
			bef = c;
			ans = max(ans, 1LL * w[i] * w[j] / bef);
		}
	}
	cout << ans << endl;
}
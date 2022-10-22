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
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	L = LLONG_MAX;
	R = LLONG_MIN;
	long long ans = 0;
	long long single = LLONG_MAX;
	map<long long, long long>lft;
	map<long long, long long>rht;
	for (int i = 0; i < N; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a < L || b > R)single = LLONG_MAX;
		if (lft.find(a) == lft.end())lft[a] = LLONG_MAX;
		lft[a] = min(lft[a], c);
		if (rht.find(b) == rht.end())rht[b] = LLONG_MAX;
		rht[b] = min(rht[b], c);
		L = min(L, a);
		R = max(R, b);
		if (L == a && R == b) {
			single = min(single, c);
		}
		ans = lft[L] + rht[R];
		cout << min(single, ans) << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}
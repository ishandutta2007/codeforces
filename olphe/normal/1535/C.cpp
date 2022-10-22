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

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	string s;
	cin >> s;
	long long int ans = 0;
	int r = -1;
	for (int i = 0; i < s.size(); i++) {
		while (r + 1 < s.size() && (s[r + 1] == ((r + 1) & 1) + '0' || s[r + 1] == '?'))r++;
		ans += r - i + 1;
		r = max(r, i);
	}
	r = -1;
	for (int i = 0; i < s.size(); i++) {
		while (r + 1 < s.size() && (s[r + 1] == ((r) & 1) + '0' || s[r + 1] == '?'))r++;
		ans += r - i + 1;
		r = max(r, i);
	}
	r = -1;
	for (int i = 0; i < s.size(); i++) {
		while (r + 1 < s.size() && (s[r + 1] == '?'))r++;
		ans -= r - i + 1;
		r = max(r, i);
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}
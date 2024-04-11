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
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N >> M;
	string s, t;
	cin >> s >> t;
	vector<int>lst(M, -1);
	vector<int>fst(M, -1);
	int idx = 0;
	for (int i = 0; i < t.size(); i++) {
		while (idx < N && s[idx] != t[i]) {
			idx++;
		}
		if (idx < N && s[idx] == t[i]) {
			lst[i] = idx;
		}
		idx++;
	}
	idx = N - 1;
	for (int i = t.size() - 1; i >= 0; i--) {
		while (idx >= 0 && s[idx] != t[i]) {
			idx--;
		}
		if (idx >= 0 && s[idx] == t[i]) {
			fst[i] = idx;
		}
		idx--;
	}
	int ans = 0;
	for (int i = 0; i + 1 < M; i++) {
		ans = max(ans, fst[i + 1] - lst[i]);
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
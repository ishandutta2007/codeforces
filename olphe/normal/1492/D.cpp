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
	cin >> N >> M >> K;
	if (K == 0) {
		cout << "YES\n";
		cout << string(M, '1') + string(N, '0') << endl;
		cout << string(M, '1') + string(N, '0') << endl;
		return;
	}
	if (N + M <= K + 1) {
		cout << "NO\n";
		return;
	}
	if (N == 0) {
		if (K == 0) {
			cout << "Yes\n";
			cout << string(M, '1') << endl;
			cout << string(M, '1') << endl;
			return;
		}
		else {
			cout << "No\n";
			return;
		}
	}
	if (M == 1) {
		if (K == 0) {
			cout << "Yes\n";
			cout << "1" << string(N, '0') << endl;
			cout << "1" << string(N, '0') << endl;
			return;
		}
		else {
			cout << "No\n";
			return;
		}
	}
	string s(N + M, '?');
	string t(N + M, '?');
	s[0] = t[0] = '1';
	M--;
	t.back() = '1';
	s.back() = '0';
	s[N + M - K] = '1';
	t[N + M - K] = '0';
	M--;
	N--;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '?') {
			if (N) {
				s[i] = t[i] = '0';
				N--;
			}
			else {
				s[i] = t[i] = '1';
				M--;
			}
		}
	}
	cout << "YES\n";
	cout << s << endl;
	cout << t << endl;
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
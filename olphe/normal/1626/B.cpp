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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	string s;
	cin >> s;
	int idx = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] - '0' + s[i - 1] - '0' >= 10) {
			idx = i;
		}
	}
	if (idx == 0) {
		cout << s[0] - '0' + s[1] - '0';
		cout << s.substr(2, s.size()-2) << endl;
	}
	else {
		string t;
		for (int i = 0; i < idx - 1; i++) {
			t.push_back(s[i]);
		}
		t += to_string(s[idx - 1] - '0' + s[idx] - '0');
		for (int i = idx + 1; i < s.size(); i++) {
			t.push_back(s[i]);
		}
		cout << t << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}
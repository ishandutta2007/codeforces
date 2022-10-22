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
	string s;
	cin >> s;
	string u;
	u.push_back(s[0]);
	int same = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] > s[i - 1]) {
			break;
		}
		if (same && s[i] == s[i - 1]) {
			break;
		}
		u.push_back(s[i]);
		same &= s[i] == s[i - 1];
	}
	string t = u;
	reverse(u.begin(), u.end());
	t += u;
	cout << t << endl;
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
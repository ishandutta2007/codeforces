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
	string s, t;
	cin >> s >> t;
	for (int i = 1; i <= 30; i++) {
		string u;
		for (int j = 0; j < i; j++)u += s;
		bool flag = true;
		for (int j = 0; j < u.size(); j++) {
			flag &= u[j] == t[j%t.size()];
		}
		if (flag&&u.size()%t.size()==0) {
			cout << u << endl;
			return;
		}
	}
	cout << -1 << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}
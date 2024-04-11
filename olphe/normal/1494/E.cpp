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
	cin >> N >> K;
	vector<map<int, int>>mp(N);
	int odd = 0, even = 0;
	while (K--) {
		char c;
		cin >> c;
		if (c == '+') {
			cin >> L >> R;
			cin >> c;
			c -= 'a' - 1;
			L--, R--;
			mp[L][R] = c;
			if (mp[L][R] && mp[R][L])odd++;
			if (mp[L][R] == mp[R][L])even++;
		}
		else if (c == '-') {
			cin >> L >> R;
			L--, R--;
			c = mp[L][R];
			if (mp[L][R] && mp[R][L])odd--;
			if (mp[L][R] == mp[R][L])even--;
			mp[L][R] = 0;
		}
		else {
			cin >> M;
			//cout << odd << " " << even << endl;
			if (M & 1) {
				if (odd||even)cout << "YES\n";
				else cout << "NO\n";
			}
			else {
				if (even)cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
	return;
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
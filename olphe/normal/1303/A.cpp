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
constexpr long double EPS = 1e-12;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		int l = MOD, r = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0')continue;
			l = min(l, i);
			r = max(r, i);
		}
		int ans = 0;
		for (int i = l; i <= r; i++)ans += s[i] == '0';
		cout << ans << endl;
	}
	return 0;
}
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
#include "functional"

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	if (s.size()==1) {
		cout << 0 << endl;
		return 0;
	}
	N = s.size();
	int zero = 0;
	int one = 0;
	vector<int>dif(N,-MOD);
	for (int i = N - 1; i >= 0; i--) {
		if (i != N - 1) {
			dif[i] = zero - one;
		}
		if (one >= zero)zero = one;
		if (s[i] == '1')one++;
		else zero = max(zero + 1, one + 1);
	}
	zero = 0;
	one = 0;
	for (int i = 0; i < N; i++) {
		if (!i) {
			if (s[i] == '1') {
				if (dif[0] <= 0)s[i] = '0';
			}
		}
		else {
			if (s[i] == '1') {
				if (dif[i] <= 0 && zero >= one)s[i] = '0';
			}
		}
		if (zero > one)zero = one;
		if (s[i] == '1')one = max(one, zero) + 1;
		else zero++;
	}
	cout << s << endl;
}
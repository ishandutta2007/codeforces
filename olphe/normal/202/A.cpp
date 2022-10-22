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
#include "ctime"

using namespace std;

const long long int MOD = 1000000007;
//const long long  int MOD = 998244353;
//long long int N, M, K, H, W, L, R;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	N = s.size();
	string ans;
	ans.push_back(s[0]);
	for (int i = 1; i < 1 << N; i++) {
		string t;
		for (int j = 0; j < N; j++) {
			if ((i >> j) & 1)t.push_back(s[j]);
		}
		auto u = t;
		reverse(u.begin(), u.end());
		if (t == u) {
			if (ans < t)ans = t;
		}
	}
	cout << ans << endl;
	return 0;
}
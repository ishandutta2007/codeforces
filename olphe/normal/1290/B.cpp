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

	string s;
	cin >> s;
	N = s.size();
	cin >> K;
	vector<vector<int>>v(26, vector<int>(N + 1));
	for (int i = 0; i < N; i++) {
		v[s[i] - 'a'][i + 1] = 1;
		for (int j = 0; j < 26; j++) {
			v[j][i + 1] += v[j][i];
		}
	}
	while (K--) {
		cin >> L >> R;
		L--, R--;
		if (L == R) {
			cout << "Yes\n";
			continue;
		}
		if (s[L] != s[R]) {
			cout << "Yes\n";
			continue;
		}
		int num = 0;
		for (int i = 0; i < 26; i++) {
			if (v[i][R + 1] - v[i][L])num++;
		}
		if (num > 2) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
	return 0;
}
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
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<string>s(N);
	for (auto &i : s)cin >> i;
	for (int i = 0; i < N; i++) {
		if (s[0][0] != s[i][i]) {
			cout << "NO\n";
			return 0;
		}
		if (s[0][0] != s[i][N - i - 1]) {
			cout << "NO\n";
			return 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)continue;
			if (i + j == N - 1)continue;
			if (s[0][1] != s[i][j]) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	if (s[0][0] == s[0][1]) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
}
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
	string s, t;
	cin >> N;
	cin >> s >> t;
	int dif = 0;
	int num = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')dif++;
		else dif--;
	}
	for (int i = s.size() - 1; i >= 0; i--) {
		if (num ^ (s[i] != t[i])) {
			if (dif) {
				cout << "NO\n";
				return;
			}
			num ^= 1;
		}
		if (s[i] == '0')dif--;
		else dif++;
	}
	cout << "YES\n";
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
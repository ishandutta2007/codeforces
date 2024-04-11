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
	string s;
	cin >> s;
	int amari = 0;
	int dif = 0;
	for (auto i : s) {
		if (i == '(')dif++;
		if (i == ')')dif--;
		if (i == '?')amari++;
	}
	if (s.size() % 2) {
		cout << "NO\n";
		return;
	}
	for (auto& i : s) {
		if (i != '?')continue;
		if (amari == dif) {
			amari--;
			dif--;
			i = ')';
		}
		else {
			amari--;
			dif++;
			i = '(';
		}
	}
	if (dif) {
		cout << "NO\n";
		return;
	}
	for (auto i : s) {
		if (i == '(')dif++;
		else dif--;
		if (dif < 0) {
			cout << "NO\n";
			return;
		}
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
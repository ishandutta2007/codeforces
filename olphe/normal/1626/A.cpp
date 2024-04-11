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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	string s;
	cin >> s;
	map<char, int>mp;
	for (auto i : s) {
		mp[i]++;
	}
	string t;
	for (auto i : mp) {
		if (i.second == 2)t.push_back(i.first);
	}
	for (auto i : mp) {
		if (i.second == 2)t.push_back(i.first);
	}
	for (auto i : mp) {
		if (i.second == 1)t.push_back(i.first);
	}
	cout << t << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}
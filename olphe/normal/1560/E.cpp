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
constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

vector<string>t;

void Solve() {
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	string t, u;
	int used[256] = {};
	int num[256] = {};
	for (auto i : s) {
		num[i]++;
		if (used[i])continue;
		used[i] = 1;
		u.push_back(i);
	}
	reverse(u.begin(), u.end());
	int sum = 0;
	for (int i = 0; i < u.size(); i++) {
		if (num[u[i]] % (i + 1)) {
			cout << -1 << endl;
			return;
		}
		sum += num[u[i]] / (i + 1);
	}
	reverse(s.begin(), s.end());
	for (int i = 0; i < sum; i++)t.push_back(s[i]);
	int out[256] = {};
	string v;
	for (auto i : u) {
		for (auto j : t) {
			if (!out[j])v.push_back(j);
		}
		out[i] = 1;
	}
	if (s == v)	cout << t << " " << u << endl;
	else cout << -1 << endl;
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
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
	cin >> N;
	vector<string>s(N);
	for (auto& i : s)cin >> i;
	for (auto i : s) {
		auto j = i;
		reverse(j.begin(), j.end());
		if (i == j) {
			cout << "YES\n";
			return;
		}
	}
	set<string>st;
	for (int i = 0; i < N; i++) {
		auto t = s[i];
		reverse(t.begin(), t.end());
		if (st.find(t) != st.end()) {
			cout << "YES\n";
			return;
		}
		st.insert(s[i]);
	}
	st.clear();
	for (int i = 0; i < N; i++) {
		auto t = s[i];
		reverse(t.begin(), t.end());
		if (st.find(t) != st.end()) {
			cout << "YES\n";
			return;
		}
		st.insert(s[i]);
		if (s[i].size() == 3) {
			t = s[i];
			t.pop_back();
			st.insert(t);
		}
	}
	st.clear();
	for (int i = 0; i < N; i++) {
		auto t = s[i];
		reverse(t.begin(), t.end());
		if (st.find(t) != st.end()) {
			cout << "YES\n";
			return;
		}
		if (t.size() == 3) {
			t.pop_back();
			if (st.find(t) != st.end()) {
				cout << "YES\n";
				return;
			}
		}
		st.insert(s[i]);
	}
	cout << "NO\n";
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
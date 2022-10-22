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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void func(string s, int ed, set<string>& st) {
	if (s.size() == ed) {
		st.insert(s);
		return;
	}
	for (char c = 'a'; c <= 'z'; c++) {
		s.push_back(c);
		func(s, ed, st);
		s.pop_back();
	}
}

void Solve() {
	cin >> N;
	string s;
	cin >> s;
	for (int len = 1; len <= 5; len++) {
		set<string>st;
		func("", len, st);
		for (int i = 0; i + len <= N; i++) {
			string t;
			for (int j = i; j < i + len; j++) {
				t.push_back(s[j]);
			}
			if(st.find(t)!=st.end())			st.erase(t);
		}
		if (st.empty())continue;
		cout << *st.begin() << endl;
		return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}
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

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

string Add(string s, int num) {
	reverse(s.begin(), s.end());
	for (int i = 0; i < 30; i++) {
		s.push_back('0');
		if (num >> i & 1) {
			s[i]++;
		}
	}
	s.push_back('0');
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '2') {
			s[i] -= 2;
			s[i + 1]++;
		}
	}
	while (s.back() == '0'&&s.size()>N)s.pop_back();
	reverse(s.begin(), s.end());
	return s;
}

string stringXor(string s, string t) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			if (t[i] == '1')t[i] = '0';
			else t[i] = '1';
		}
	}
	return t;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	string s, t;
	cin >> s >> t;
	if (s[0] != t[0]) {
		cout << string(N, '1') << endl;
		return 0;
	}
	auto box = Add(s, 20);
	if (box.size() <= t.size() && box <= t) {
		if (t.back() == '0')t.back() = '1';
		cout << t << endl;
		return 0;
	}
	string ans = t;
	while (s != t) {
		auto u = s;
		auto v = u;
		ans = max(ans, u);
		while (v.size() <= t.size() && v <= t) {
			v = Add(v, 1);
			if (v.size() > t.size() || v > t)break;
			u = stringXor(u, v);
			ans = max(ans, u);
		}
		s = Add(s, 1);
	}
	cout << ans << endl;
}
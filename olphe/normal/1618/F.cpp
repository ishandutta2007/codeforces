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
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

bool in(string a, string b) {
	if (a.size() > b.size())return false;
	for (int i = 0; i + a.size() <= b.size(); i++) {
		bool ok = true;
		for (int j = 0; j < i; j++) {
			ok &= b[j] == '1';
		}
		for (int j = 0; j < a.size(); j++) {
			ok &= a[j] == b[i + j];
		}
		for (int j = a.size() + i; j < b.size(); j++) {
			ok &= b[j] == '1';
		}
		if (ok) {
			return true;
		}
	}
	return false;
}

void Solve() {
	cin >> N >> M;
	if (N != M && M % 2 == 0) {
		cout << "NO\n";
		return;
	}
	string s, t;
	while (N) {
		if (N & 1)s.push_back('1');
		else s.push_back('0');
		N >>= 1;
	}
	while (M) {
		if (M & 1)t.push_back('1');
		else t.push_back('0');
		M >>= 1;
	}
	while (s.size() && s.back() == '0')s.pop_back();
	while (t.size() && t.back() == '0')t.pop_back();
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	auto u = s;
	auto v = s;
	u.push_back('0');
	v.push_back('1');
	while (u.size() && u.back() == '0') {
		u.pop_back();
	}
	reverse(u.begin(), u.end());
	reverse(v.begin(), v.end());
	auto uu = u;
	auto vv = v;
	reverse(uu.begin(), uu.end());
	reverse(vv.begin(), vv.end());
	//cout << s << " " << t << " " << u << " " << v << " " << uu << " " << vv << endl;
	if (in(s, t) || in(u, t) || in(v, t) || in(uu, t) || in(vv, t)) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	//cin >> T;
	while (T--) {
		Solve();
	}
}
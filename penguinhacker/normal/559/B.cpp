#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array

ar<int, 26> get_cnt(string s) {
	ar<int, 26> res;
	for (int i = 0; i < 26; ++i) res[i] = 0;
	for (char c : s) ++res[c - 'a'];
	return res;
}

bool eq(string a, string b) {
	if (a == b) return 1;
	if (get_cnt(a) != get_cnt(b)) return 0;
	if (a.size() % 2 == 0) {
		int sz = a.size() / 2;
		return (eq(a.substr(0, sz), b.substr(0, sz)) && eq(a.substr(sz, sz), b.substr(sz, sz)))
			|| (eq(a.substr(0, sz), b.substr(sz, sz)) && eq(a.substr(sz, sz), b.substr(0, sz)));
	}
	return 0;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b; cin >> a >> b;
	cout << (eq(a, b) ? "YES" : "NO");
	return 0;
}
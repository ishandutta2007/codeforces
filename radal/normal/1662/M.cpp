//In the name of Allah :)
#include <bits/stdc++.h>
using namespace std;
string to_string(char c) { return string(1,c); }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char* s) { return (string)s; }
string to_string(string s) { return s; }
string to_string(vector<bool> v) { 
	string res = "{"; for(int i = 0; i < (int)v.size(); i++) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> string to_string(bitset<SZ> b) {
	string res = ""; for(size_t i = 0; i < SZ; i++) res += char('0'+b[i]);
	return res; }
template<class A, class B> string to_string(pair<A,B> p);
template<class T> string to_string(T v) { // containers with begin(), end()
	bool fst = 1; string res = "{";
	for (const auto& x: v) {
		if (!fst) res += ", ";
		fst = 0; res += to_string(x);
	}
	res += "}"; return res;
}
template<class A, class B> string to_string(pair<A,B> p) {
	return "("+to_string(p.first)+", "+to_string(p.second)+")"; }
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define wis(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "] : [", DBG(__VA_ARGS__)
#else
#define wis(...) 0
#endif
#define all(x) (x).begin(), (x).end()
typedef long long ll;

inline void test_case() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(m);
	int mx1 = 0, mx2 = 0;
	for (int i = 0; i < m; i++) {
		cin >> a[i].first >> a[i].second;
		mx1 = max(mx1, a[i].first), mx2 = max(mx2, a[i].second);
	}
	if (mx1 + mx2 > n) {
		cout << "IMPOSSIBLE" << '\n';
		return;
	}
	string ans(n - mx2, 'R');
	ans += string(mx2, 'W');
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
#ifndef LOCAL
	cin.tie(0);
#endif
	int tt;
	cin >> tt;
	while(tt--){
		test_case();
	}
}
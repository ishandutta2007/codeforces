#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <string>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

constexpr int inf = 1e9 + 7;
struct hash_stack {
	int p, mod, n;
	vector <int> ha, re, pw;
	hash_stack(string s, int p, int mod) : p(p), mod(mod) {
		n = s.size();
		pw.resize(n + 1);
		pw[0] = 1;
		for (int i = 1; i <= n; ++i)
			pw[i] = (pw[i - 1] * p) % mod;
		ha.resize(n + 1);
		for (int i = 1; i <= n; ++i) {
			ha[i] = ha[i - 1] + (s[i - 1] - 'a' + 1) * pw[i] % mod;
			ha[i] %= mod;
		}
		re.resize(n + 1);
		for (int i = n - 1; i >= 0; --i) {
			re[i] = re[i + 1] + (s[i] - 'a' + 1) * pw[n - i] % mod;
			re[i] %= mod;
		}
	}
	int get_ha(int l, int r) {
		int res = ha[r + 1] - ha[l];
		res = (res % mod) + mod;
		res %= mod;
		res = (res * pw[n - l - 1]) % mod;
		return res;
	}
	int get_re(int l, int r) {
		int res = re[l] - re[r + 1];
		res = (res % mod) + mod;
		res %= mod;
		res = (res * pw[r]) % mod;
		return res;
	}
	bool palindrome(int l, int r) {
		return get_ha(l, r) == get_re(l, r);
	}
};
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(8);
	int tt; cin >> tt;
	while (tt --> 0) {
		string s; cin >> s;
		int n = s.size();
		int board = 0;
		while (board < n - 1 - board) {
			if (s[board] == s[n - 1 - board])
				board++;
			else
				break;
		}
		if (board >= n - 1 - board) {
			cout << s << '\n';
			continue;
		}
		string vl, vr;
		hash_stack ok(s, 239, 1e9 + 7), ok2(s, 1344, 998343255);
		int lx = 0;
		for (int i = board; i < n - 1 - board; ++i) {
			if (ok.palindrome(board, i) and ok2.palindrome(board, i))
				lx = i;
		}
		vl = s.substr(board, lx - board + 1);
		int rx = 0;
		for (int i = n - 1 - board; i > board; --i) {
			if (ok.palindrome(i, n - board - 1) and ok2.palindrome(i, n - board - 1))
				rx = i;
		}
		vr = s.substr(rx, n - board - rx);
		string ans = "";
		for (int i = 0; i < board; ++i)
			ans += s[i];
		if (vl.size() > vr.size())
			ans += vl;
		else
			ans += vr;
		for (int i = n - board; i < n; ++i)
			ans += s[i];
		cout << ans << '\n';
	}
}
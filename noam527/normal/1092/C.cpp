#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

bool prefixof(string &pre, string &of) {
	for (int i = 0; i < pre.size(); i++)
		if (pre[i] != of[i]) return false;
	return true;
}
bool suffixof(string &suf, string &of) {
	for (int i = 0; i < suf.size(); i++)
		if (suf[suf.size() - 1 - i] != of[of.size() - 1 - i]) return false;
	return true;
}
struct str {
	string s;
	int ind;
	int type;
	str(string ss = "", int ii = 0) {
		s = ss;
		ind = ii;
	}
};

int n;
str s[101], t[101];
char ans[202];

bool check(string &cand) {
	for (int i = 1; i <= n - 1; i++) {
		if (prefixof(s[i].s, cand) && suffixof(t[i].s, cand)) {
			s[i].type = 1;
			t[i].type = 0;
		}
		else if (prefixof(t[i].s, cand) && suffixof(s[i].s, cand)) {
			s[i].type = 0;
			t[i].type = 1;
		}
		else return false;
	}
	return true;
}

int main() {
	fast;
	cin >> n;
	string tmp;
	for (int i = 0; i < 2 * n - 2; i++) {
		cin >> tmp;
		if (s[tmp.size()].s == "") s[tmp.size()] = str(tmp, i);
		else t[tmp.size()] = str(tmp, i);
	}
	tmp.clear();

	tmp = s[n - 1].s + t[n - 1].s.back();
	if (!check(tmp)) {
		tmp = t[n - 1].s + s[n - 1].s.back();
		check(tmp);
	}

	for (int i = 1; i <= n - 1; i++) {
		ans[s[i].ind] = (s[i].type ? 'P' : 'S');
		ans[t[i].ind] = (t[i].type ? 'P' : 'S');
	}
	for (int i = 0; i < 2 * n - 2; i++) cout << ans[i];
}
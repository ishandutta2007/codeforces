#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m, p;
vector<int> x, y;
string ans = "";

int f(int a, int b) {
	return (x[a] + y[b]) % p;
}

vector<ll> calc(int str, int stc, int enr, int enc, bool order) {
	vector<ll> rtn(enc - stc + 1);
	if (order) {
		rtn[0] = f(str, stc);
		for (int i = 1; i < rtn.size(); i++)
			rtn[i] = rtn[i - 1] + f(str, stc + i);
		for (int i = str + 1; i <= enr; i++) {
			rtn[0] += f(i, stc);
			for (int j = 1; j < rtn.size(); j++)
				rtn[j] = f(i, stc + j) + max(rtn[j - 1], rtn[j]);
		}
		return rtn;
	}
	rtn[enc - stc] = f(enr, enc);
	for (int i = enc - stc - 1; i >= 0; i--)
		rtn[i] = rtn[i + 1] + f(enr, stc + i);
	for (int i = enr - 1; i >= str; i--) {
		rtn[enc - stc] += f(i, enc);
		for (int j = enc - stc - 1; j >= 0; j--)
			rtn[j] = f(i, stc + j) + max(rtn[j], rtn[j + 1]);
	}
	return rtn;
}

ll solve(int str, int stc, int enr, int enc) {
	if (str == enr) {
		ll rtn = 0;
		for (int i = stc; i < enc; i++) ans.push_back('S'), rtn += f(str, i);
		return rtn + f(str, enc);
	}
	if (stc == enc) {
		ll rtn = 0;
		for (int i = str; i < enr; i++) ans.push_back('C'), rtn += f(i, stc);
		return rtn + f(enr, stc);
	}
	ll mx = -1;
	int at, mid = (str + enr) / 2;
	vector<ll> b = calc(str, stc, mid, enc, true), t = calc(mid + 1, stc, enr, enc, false);
	for (int i = 0; i < b.size(); i++) {
		if (mx < b[i] + t[i]) {
			mx = b[i] + t[i];
			at = i;
		}
	}
	solve(str, stc, mid, at + stc);
	ans.push_back('C');
	solve(mid + 1, at + stc, enr, enc);
	return mx;
}

int main() {
	fast;
	cin >> n >> m >> p;
	x.resize(n);
	y.resize(m);
	for (auto &i : x) cin >> i;
	for (auto &i : y) cin >> i;
	cout << solve(0, 0, n - 1, m - 1) << endl;
	cout << ans << endl;
}
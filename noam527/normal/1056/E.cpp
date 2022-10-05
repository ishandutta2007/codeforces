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

struct ha {
	int n;
	ll P, M;
	vector<ll> H, a;
	ha() {}
	ha(string s, ll p, ll m) {
		n = s.size();
		H.resize(s.size());
		P = p;
		M = m;
		H[0] = s[0];
		for (int i = 1; i < n; i++)
			H[i] = (s[i] + P * H[i - 1]) % M;

		a.resize(s.size());
		a[0] = 1;
		for (int i = 1; i < n; i++)
			a[i] = (a[i - 1] * P) % M;
	}
	ll calc(int l, int r) {
		if (l == 0) return H[r];
		ll rtn = H[r] - H[l - 1] * a[r - l + 1];
		rtn = (rtn % M + M) % M;
		return rtn;
	}
	bool equal(int l1, int r1, int l2, int r2) {
		return calc(l1, r1) == calc(l2, r2);
	}
};

string s, t;
int n, m, c[2] = {};
ha H1, H2;
vector<int> pos;

bool query(int l1, int r1, int l2, int r2) {
//	cout << "check " << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
	return H1.equal(l1, r1, l2, r2) && H2.equal(l1, r1, l2, r2);
}

bool check(int l1, int l2) {
//	cout << "check " << l1 << " " << l2 << endl;
	pos[0] = 0;
	for (int i = 1; i < n; i++) {
		pos[i] = pos[i - 1];
		if (s[i - 1] == '0') pos[i] += l1;
		else pos[i] += l2;
	}
	int st[2];
	for (int i = 0; i < n; i++)
		st[s[i] - '0'] = pos[i];

	if (l1 == l2 && query(st[0], st[0] + l1 - 1, st[1], st[1] + l1 - 1)) return false;
//	debug;
//	cout << st[0] << " " << st[1] << endl;
	for (int i = 0; i < n; i++) {
//		cout << "i " << i << endl;
		if (s[i] == '0') {
			if (!query(pos[i], pos[i] + l1 - 1, st[0], st[0] + l1 - 1)) return false;
		}
		else {
			if (!query(pos[i], pos[i] + l2 - 1, st[1], st[1] + l2 - 1)) return false;
		}
	}
	return true;
}

int main() {
	fast;
	cin >> s >> t;
	n = s.size();
	m = t.size();
	pos.resize(n);
	for (auto &i : s)
		c[i - '0']++;
	H1 = ha(t, 47, md);
	H2 = ha(t, hs, md + 2);
	
	int ans = 0;
	for (int r0 = 1; c[0] * r0 < m; r0++) {
		int r1 = m - c[0] * r0;
		if (r1 % c[1] == 0) {
			r1 /= c[1];
			if (check(r0, r1)) ans++;
		}
	}
	finish(ans);
	
}
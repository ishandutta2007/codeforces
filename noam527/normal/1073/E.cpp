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

int bitcount(int x) {
	int rtn = 0;
	for (int i = 1; i <= x; i <<= 1)
		if (x & i) rtn++;
	return rtn;
}

int S[20][1024][2]; // ind, used, can exceed
int C[20][1024][2]; // ind, used, can exceed
ll pw[20];

pair<int, int> solve(const vector<int> &lim, const int &c, int ind, int used, int can) {
	if (bitcount(used) > c) return{ 0, 0 };
	if (ind == lim.size()) return{ 0, 1 };
	if (S[ind][used][can] != -1) return{ S[ind][used][can], C[ind][used][can] };
	int &ss = S[ind][used][can];
	int &cc = C[ind][used][can];
	ss = cc = 0;
	pair<int, int> tmp;
	if (can) {
		for (int d = (used ? 0 : 1); d <= 9; d++) {
			tmp = solve(lim, c, ind + 1, used | (1 << d), 1);
			cc = (cc + tmp.second) % md;
			ss = (ss + (ll)d * pw[lim.size() - ind - 1] * (ll)tmp.second) % md;
			ss = (ss + tmp.first) % md;
		}
	}
	else {
		for (int d = (used ? 0 : 1); d <= lim[ind]; d++) {
			tmp = solve(lim, c, ind + 1, used | (1 << d), (d < lim[ind] ? 1 : 0));
			cc = (cc + tmp.second) % md;
			ss = (ss + (ll)d * pw[lim.size() - ind - 1] * (ll)tmp.second) % md;
			ss = (ss + tmp.first) % md;
		}
	}
	return{ ss, cc };
}

ll l, r;
int c;

int ans(ll lim) {
	if (lim == 0) return 0;
	for (int i = 0; i < 20; i++) for (int j = 0; j < 1024; j++) for (int k = 0; k < 2; k++)
		S[i][j][k] = C[i][j][k] = -1;
	vector<int> s;
	while (lim > 0) {
		s.push_back(lim % 10);
		lim /= 10;
	}
	reverse(s.begin(), s.end());
	int rtn = solve(s, c, 0, 0, 0).first;
	for (int i = 1; i <= s.size(); i++)
		rtn = (rtn + solve(s, c, i, 0, 1).first) % md;
	return rtn;
}

int main() {
	fast;
	pw[0] = 1;
	for (int i = 1; i < 20; i++)
		pw[i] = 10LL * pw[i - 1] % md;
	cin >> l >> r >> c;
	int a = ans(r), b = ans(l - 1);
	cout << (a - b + md) % md << endl;
}
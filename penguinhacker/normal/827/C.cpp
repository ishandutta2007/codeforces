#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

template<class T, int n> struct BIT { //try to always use long long
	vector<T> bit;
	BIT() {
		bit.resize(n + 1);
	}
	void upd(int i, T val) {
		for (++i; i <= n; i += i & -i)
			bit[i] += val;
	}
	T qry(int i) {T res = 0;
		for (++i; i > 0; i -= i & -i)
			res += bit[i];
		return res;
	}
	T qry(int l, int r) {
		return qry(r) - qry(l - 1);
	}
};

const int mxN = 100000;
int n, q, c[256];
string s;
vector<vector<BIT<int, mxN>>> b[11];

void upd(int ind, int inc) {
	int x = c[s[ind]];
	for (int i = 1; i <= 10; ++i) {
		b[i][ind % i][x].upd(ind, inc);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s, n = s.size();
	c['A'] = 0;
	c['T'] = 1;
	c['C'] = 2;
	c['G'] = 3;
	for (int i = 1; i <= 10; ++i) {
		b[i].assign(i, vector<BIT<int, mxN>>(4));
	}
	for (int i = 0; i < n; ++i) {
		upd(i, 1);
	}
	cin >> q;
	while(q--) {
		int t; cin >> t;
		if (t == 1) {
			int i; char c; cin >> i >> c, --i;
			upd(i, -1);
			s[i] = c;
			upd(i, 1);
		}
		else if (t == 2) {
			int l, r; cin >> l >> r, --l, --r;
			string e; cin >> e;
			int k = e.size();
			int ans = 0;
			for (int i = 0; i < k; ++i) {
				ans += b[k][(i + l) % k][c[e[i]]].qry(l, r);
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
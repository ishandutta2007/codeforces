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

vector<int> tmpl, tmpr;
int nxtl, nxtr;
vector<int>::iterator stable(vector<int>::iterator st, vector<int>::iterator en, int mid) {
	nxtl = nxtr = 0;
	for (auto i = st; i != en; i++)
		if (*i <= mid)
			tmpl[nxtl++] = *i;
		else
			tmpr[nxtr++] = *i;
	vector<int>::iterator p = st;
	for (int i = 0; i < nxtl; i++) {
		*p = tmpl[i];
		p++;
	}
	for (int i = 0; i < nxtr; i++) {
		*p = tmpr[i];
		p++;
	}
	return st + nxtl;
}

struct wavelet {
	wavelet *l, *r;
	vector<int> a;
	int lo, hi;
	// values in range [x, y], in positions [st, en)
	wavelet() {}
	wavelet(int x, int y, vector<int>::iterator st, vector<int>::iterator en) {
		lo = x, hi = y;
		if (lo == hi) return;
		int mid = (lo + hi) / 2;
		a.reserve(en - st + 1);
		a.push_back(0);
		for (auto i = st; i != en; i++)
			a.push_back(a.back() + (*i <= mid ? 1 : 0));
		auto piv = stable(st, en, mid);
		l = new wavelet(x, mid, st, piv);
		r = new wavelet(mid + 1, y, piv, en);
	}
	int query(int L, int R, int x, int y) {
		if (x <= lo && hi <= y) return R - L + 1;
		if (hi < x || y < lo) return 0;
		int cl = a[L - 1], cr = a[R];
		return l->query(cl + 1, cr, x, y) + r->query(L - cl, R - cr, x, y);
	}
};

int lst = 0;
int n, q;
vector<int> a, pos;
wavelet W;

int f(int z) {
	return ((z - 1 + lst) % n) + 1;
}

int main() {
	fast;
	cin >> n;
	a.resize(n);
	pos.resize(n);
	tmpl.resize(n);
	tmpr.resize(n);
	for (auto &i : a) cin >> i;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		pos[x - 1] = i + 1;
	}
	for (auto &i : a) i = pos[i - 1];

	W = wavelet(1, n, a.begin(), a.end());

	cin >> q;
	int par[4];
	int l1, r1, l2, r2;
	while (q--) {
		cin >> par[0] >> par[1] >> par[2] >> par[3];
		l1 = min(f(par[0]), f(par[1]));
		r1 = max(f(par[0]), f(par[1]));
		l2 = min(f(par[2]), f(par[3]));
		r2 = max(f(par[2]), f(par[3]));
		lst = W.query(l1, r1, l2, r2);
		cout << lst << endl;
		lst++;
	}
}
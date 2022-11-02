#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <unordered_set>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct S {
	int lval, rval, maxDiff, left, lind, rind;
};

const int sz = 3e5;
int n, q;
vector<ll> a;
S seg[3 * sz];

inline S def(int ind) {
	S ret;
	ret.maxDiff = 0;
	ret.lval = a[ind];
	ret.rval = a[ind];
	ret.left = ind;
	ret.lind = ind;
	ret.rind = ind;
	return ret;
}

S action(const S& l, const S& r) {
	S ret;
	ret.lval = l.lval;
	ret.rval = r.rval;
	ret.lind = l.lind;
	ret.rind = r.rind;
	if (l.maxDiff > r.maxDiff) {
		ret.maxDiff = l.maxDiff;
		ret.left = l.left;
	}
	else {
		ret.maxDiff = r.maxDiff;
		ret.left = r.left;
	}
	if (abs(r.lval - l.rval) >= ret.maxDiff) {
		ret.maxDiff = abs(r.lval - l.rval);
		ret.left = l.rind;
	}
	return ret;
}

void build(int i, int l, int r) {
	if (l == r)seg[i] = def(l);
	else if (l > r)return;
	else {
		int mid = (l + r) / 2;
		build(2 * i, l, mid);
		build(2 * i + 1, mid + 1, r);
		seg[i] = action(seg[2 * i], seg[2 * i + 1]);
	}
}

S queryUtil(int i, int cl, int cr, int l, int r) {
	if (cl >= l and cr <= r)return seg[i];
	else {
		int mid = (cl + cr) / 2;
		if (mid < l)return queryUtil(2 * i + 1, mid + 1, cr, l, r);
		else if (mid + 1 > r)return queryUtil(2 * i, cl, mid, l, r);
		else return action(queryUtil(2 * i, cl, mid, l, r), queryUtil(2 * i + 1, mid + 1, cr, l, r));
	}
}

S query(int l, int r) {
	return queryUtil(1, 0, n - 1, l, r);
}

ll calc(int l, int r) {
	if (l >= r)return 0;
	S qu = query(l, r);
	ll tot = (ll)qu.maxDiff*(qu.left - l + 1)*(r - qu.left);
	return tot + calc(l, qu.left) + calc(qu.left + 1, r);
}

int main() {
	fast;
	cin >> n >> q;
	a.resize(n);
	foru(i, 0, n)cin >> a[i];
	build(1, 0, n - 1);
	while (q--) {
		int l, r;
		cin >> l >> r; l--; r--;
		cout << calc(l, r) << '\n';
	}
	return 0;
}
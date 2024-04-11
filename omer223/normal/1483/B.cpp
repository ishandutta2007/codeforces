#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <queue>
#include <numeric>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


struct S {
	int amt = 1, leftest = -1;
	S() { amt = 1, leftest = -1; }
	S(int x, int y): amt(x), leftest(y){}
};

using T = S;
struct segmentree {
private:
	vector<T> seg, original;
	int n;
	T action(const T& lhs, const T& rhs) {
		if (lhs.leftest != -1)return S(lhs.amt + rhs.amt, lhs.leftest);
		else if (rhs.leftest!=-1) return S(lhs.amt + rhs.amt, rhs.leftest);
		else return S(lhs.amt + rhs.amt, -1);
	}
	void build(int i, int l, int r) {
		if (l > r)return;
		else if (l == r)seg[i] = original[l];
		else {
			int mid = (l + r) / 2;
			build(2 * i, l, mid);
			build(2 * i + 1, mid + 1, r);
			seg[i] = action(seg[2 * i], seg[2 * i + 1]);
		}
	}
	T queryUtil(int i, int cl, int cr, int l, int r) {
		if (l > r)return S(1, -1); //CHECK
		else if (l == cl && r == cr)return seg[i];
		else {
			int mid = (cl + cr) / 2;
			T a = queryUtil(2 * i, cl, mid, l, min(mid, r)),
				b = queryUtil(2 * i + 1, mid + 1, cr, max(mid + 1, l), r);
			return action(a, b);
		}
	}
	void updateUtil(int i, int l, int r, int pos, int val) {
		if (l == r)seg[i].leftest = val;
		else {
			int mid = (l + r) / 2;
			if (pos <= mid)updateUtil(2 * i, l, mid, pos, val);
			else updateUtil(2 * i + 1, mid + 1, r, pos, val);
			seg[i] = action(seg[2 * i], seg[2 * i + 1]);
		}
	}
public:
	segmentree(int size) {
		n = size;
		seg.resize(4 * n);
		fill(seg.begin(), seg.end(), S(1, -1));
	}
	T query(int l, int r) {
		return queryUtil(1, 0, n - 1, l, r);
	}
	void update(int i, int val) {
		updateUtil(1, 0, n - 1, i, val);
	}
};

const int sz = 5e5;
int prv[sz], nxt[sz], n, a[sz];
bitset<sz> marked, deld;



void solve() {
	cin >> n;
	foru(i, 0, n) {
		marked[i] = 0;
		deld[i] = 0;
		cin >> a[i]; nxt[i] = (i + 1) % n, prv[i] = (i - 1 + n) % n;
	}
	segmentree seg(n);
	foru(i, 0, n) {
		if (gcd(a[i], a[nxt[i]]) == 1)
			marked[nxt[i]] = 1, seg.update(nxt[i], nxt[i]);
	}
	vector<int> ret;
	int cur = 0, arrsz = n;
	bool change = 1;
	while (arrsz) {
		change = 0;
		int q = seg.query(cur + 1, n - 1).leftest;
		if (q != -1) {
			ret.pb(q);
			deld[q] = 1;
			seg.update(q, -1);
			arrsz--;

			prv[nxt[q]] = prv[q];
			nxt[prv[q]] = nxt[q];
			if (gcd(a[nxt[q]], a[prv[q]]) == 1)
				seg.update(nxt[q], nxt[q]);
			else
				seg.update(nxt[q], -1);
			cur = nxt[q];
		}
		else {//update cur
			int q = seg.query(0, cur).leftest;
			if (q != -1) {
				ret.pb(q);
				deld[q] = 1;
				seg.update(q, -1);
				arrsz--;

				prv[nxt[q]] = prv[q];
				nxt[prv[q]] = nxt[q];
				if (gcd(a[nxt[q]], a[prv[q]]) == 1)
					seg.update(nxt[q], nxt[q]);
				else
					seg.update(nxt[q], -1);
				cur = nxt[q];
			}
			else
				break;
		}
	}
	cout << ret.size() << ' ';
	for (int x : ret)cout << x +1<< ' ';
	cout << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}
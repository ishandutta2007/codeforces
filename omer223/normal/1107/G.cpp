#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const ll inf = 1e15;

struct S {
	bool empty = 0;
	ll mxp = -inf, mxs = -inf, mxsum = -inf, sum = 0;
	S() :mxp(-inf), mxs(-inf), mxsum(-inf), sum(0) {}
	S(ll mp, ll ms, ll mxs, ll sm) :mxp(mp), mxs(ms), mxsum(mxs), sum(sm) {}
	S(ll val) :mxp(val), mxs(val), mxsum(val), sum(val) {}
	S(ll val, bool mt) : empty(mt) {}
};

using T = S;
struct segmentree {
private:
	vector<T> seg;
	vector<ll> original;
	int n;
	T action(const T& lhs, const T& rhs) {
		if (rhs.empty)return lhs;
		if (lhs.empty) return rhs;
		S ret;
		ret.mxp = max(lhs.mxp, lhs.sum + rhs.mxp);
		ret.mxs = max(rhs.mxs, rhs.sum + lhs.mxs);
		ret.mxsum = max({ lhs.mxsum,rhs.mxsum,lhs.mxs + rhs.mxp });
		ret.sum = lhs.sum + rhs.sum;
		return ret;
	}
	void build(int i, int l, int r) {
		if (l > r)return;
		else if (l == r)seg[i] = S(original[l]);
		else {
			int mid = (l + r) / 2;
			build(2 * i, l, mid);
			build(2 * i + 1, mid + 1, r);
			seg[i] = action(seg[2 * i], seg[2 * i + 1]);
		}
	}
	T queryUtil(int i, int cl, int cr, int l, int r) {
		if (l > r)return S(-1, true);
		else if (l == cl && r == cr)return seg[i];
		else {
			int mid = (cl + cr) / 2;
			T a = queryUtil(2 * i, cl, mid, l, min(mid, r)),
				b = queryUtil(2 * i + 1, mid + 1, cr, max(mid + 1, l), r);
			return action(a, b);
		}
	}
	void updateUtil(int i, int l, int r, int pos, T val) {
		if (l == r)seg[i] = val;
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
		fill(seg.begin(), seg.end(), 0);
	}
	segmentree(vector<ll> orig) {
		original = orig;
		n = orig.size();
		seg.resize(4 * n);
		build(1, 0, n - 1);
	}
	T query(int l, int r) {
		return queryUtil(1, 0, n - 1, l, r);
	}
	void update(int i, T val) {
		updateUtil(1, 0, n - 1, i, val);
	}
};
struct dsu {
	vector<int> par, rnk;
	vector<int> lptr, rptr;
	int n;
	dsu(int n) {
		this->n = n;
		par.resize(n);
		rnk.assign(n, 0);
		lptr.resize(n); 
		rptr.resize(n);
		foru(i, 0, n)par[i] = lptr[i] = rptr[i] = i;
	}
	int find_set(int x) {
		if (x == par[x])return x;
		return par[x] = find_set(par[x]);
	}
	bool unite(int a, int b) {
		int para = find_set(a), parb = find_set(b);
		if (para == parb)return 0;
		if (rnk[para] < rnk[parb])swap(para, parb);
		par[parb] = para;
		rnk[para] = max(rnk[para], rnk[parb] + 1);
		lptr[para] = min(lptr[para], lptr[parb]);
		rptr[para] = max(rptr[para], rptr[parb]);
		return 1;
	}
};
int n, a;

vector<pair<ll, vector<int>>> make(vector<ll>& d) {
	vector<pair<ll, vector<int>>> v;
	vector<pair<ll, int>> difs;
	foru(i, 0, n - 1)difs.pb({ d[i + 1] - d[i],i });
	sort(difs.begin(), difs.end());
	vector<int> curinds;
	ll curdif = -1;
	for (auto ii : difs) {
		if (ii.ff != curdif) {
			if (!curinds.empty())v.pb({ curdif,curinds });
			curinds.clear();
		}
		curdif = ii.ff;
		curinds.pb(ii.ss);
	}
	v.pb({ curdif,curinds });
	return v;
}

int main() {
	fast;
	cin >> n >> a;
	vector<ll> c(n), d(n);
	foru(i, 0, n) {
		cin >> d[i] >> c[i];
		c[i] = a - c[i];
	}
	vector<pair<ll, vector<int>>> v = make(d);
	ll bst = 0, crd = 0;
	segmentree seg(c);
	dsu uni(n);
	foru(i, 0, n)bst = max(bst, c[i]);
	for (auto ii : v) {
		crd = ii.ff;
		for (int i : ii.ss) {
			uni.unite(i, i + 1);
			int rep = uni.find_set(i);
			int lptr = uni.lptr[rep], rptr = uni.rptr[rep];
			bst = max(bst, seg.query(lptr, rptr).mxsum - crd * crd);
		}
	}
	cout << bst;
	return 0;
}
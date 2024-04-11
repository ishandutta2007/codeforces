#define _CRT_SECURE_NO_WARNINGS
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
#include <bitset>
#include <queue>
#include <map>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class T>
struct segmentree {
private:
	vector<T> seg;
	vector<int> original;
	int n;
	T action(const T& lhs, const T& rhs) {
		vector<int> ret;
		int lhsize = lhs.size(), rhsize=rhs.size(), i = 0, j = 0;
		while (i < lhsize&&j < rhsize) {
			if (lhs[i] < rhs[j])ret.pb(lhs[i++]);
			else ret.pb(rhs[j++]);
		}
		while (i < lhsize)ret.pb(lhs[i++]);
		while (j < rhsize)ret.pb(rhs[j++]);
		return ret;
	}
	int calc(vector<int> v, int val) {
		int size = v.size(), l = 1, r = size, bst = size + 1, mid;
		while (l <= r) {
			mid = (l + r + 1) / 2;
			if (v[mid - 1] >= val) {
				bst = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		return size + 1 - bst;
	}
	void build(int i, int l, int r) {
		if (l > r)return;
		else if (l == r)seg[i] = { original[l] };
		else {
			int mid = (l + r) / 2;
			build(2 * i, l, mid);
			build(2 * i + 1, mid + 1, r);
			seg[i] = action(seg[2 * i], seg[2 * i + 1]);
		}
	}
	int queryUtil(int i, int cl, int cr, int l, int r, int val) {
		if (l > r)return 0; //CHECK
		else if (l == cl && r == cr)return calc(seg[i], val);
		else {
			int mid = (cl + cr) / 2;
			int a = queryUtil(2 * i, cl, mid, l, min(mid, r), val),
				b = queryUtil(2 * i + 1, mid + 1, cr, max(mid + 1, l), r, val);
			return a + b;
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
	segmentree(vector<int> orig) {
		original = orig;
		n = orig.size();
		seg.resize(4 * n);
		build(1, 0, n - 1);
	}
	int query(int l, int r) {
		return queryUtil(1, 0, n - 1, l, r, l);
	}
	void update(int i, T val) {
		updateUtil(1, 0, n - 1, i, val);
	}
};

const int sz = 1e5 + 1;
int n, k;
int a[sz];
vector<int> values[sz], vec;

int main() {
	fast;
	scanf("%d %d", &n, &k);
	vec.resize(n);
	foru(i, 0, n) {
		scanf("%d", &a[i]);
		values[a[i]].pb(i);
	}
	foru(i, 0, sz) {
		int mySize = values[i].size();
		foru(j, 0, mySize) {
			if (j < k)vec[values[i][j]] = -1;
			else vec[values[i][j]] = values[i][j - k];
		}
	}
	segmentree<vector<int>> stree(vec);
	int q, prv = 0, l, r;
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d", &l, &r);
		l = (prv + l) % n;
		r = (prv + r) % n;
		if (l > r)swap(l, r);
		prv = (r-l+1)- stree.query(l, r);
		printf("%d\n", prv);
	}
	return 0;
}
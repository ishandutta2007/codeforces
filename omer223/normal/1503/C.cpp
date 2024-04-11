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

template<class T>
struct segmentree {
private:
	vector<T> seg, original;
	int n;
	T action(const T& lhs, const T& rhs) {
		return min(lhs,rhs); //CHECK
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
		if (l > r)return 1e16; //CHECK
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
	segmentree(vector<T> orig) {
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
	void print() {
		foru(i, 0, n)cout << query(i, i) << ' ';
		cout << '\n';
	}
};

const int sz = 5e5;
int n;
pll ac[sz];
pll biggestSufSum[sz];
ll dpsuf[sz];

int main() {
	fast;
	cin >> n;
	foru(i, 0, n)cin >> ac[i].ff >> ac[i].ss;
	sort(ac, ac + n);
	ll ret = 0;
	foru(i, 0, n)ret += ac[i].ss;
	dpsuf[n - 1] = ac[n - 1].ff;
	vector<ll> dp(n, 0);
	segmentree<ll> seg(dp);
	ford(i, n - 2, 0) {
		int l = i + 1, r = n, mid, bst = i;
		while (l <= r) {
			mid = (l + r + 1) / 2;
			if (ac[mid - 1].ff <= ac[i].ff + ac[i].ss) {
				bst = mid - 1;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (bst == i) {
			seg.update(i, dpsuf[i + 1] - ac[i].ff - ac[i].ss);
		}
		else if (bst==n-1) {
			seg.update(i, seg.query(i + 1, n - 1));
		}
		else {
			seg.update(i, min(dpsuf[bst + 1] - ac[i].ff - ac[i].ss, seg.query(i + 1, bst)));
		}
		dpsuf[i] = min(dpsuf[i + 1], ac[i].ff + seg.query(i, i));
	}
	cout << ret + seg.query(0,0);
	return 0;
}
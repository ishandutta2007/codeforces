#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

struct wavelet {
	int n, mn, mx;
	vector<int> b[20];
	wavelet() {}
	wavelet(vector<int> a) {
		mn = *min_element(a.begin(), a.end());
		mx = *max_element(a.begin(), a.end());
		n = a.size();
		for (int i = 0; i < 20; i++) b[i].resize(n);
		construct(a, 0, 0, n, mn, mx);
		for (int lv = 0; lv < 20; lv++)
			for (int i = 1; i < n; i++) b[lv][i] += b[lv][i - 1];
	}
	void construct(vector<int> &a, int lv, int l, int r, int lo, int hi) {
		if (l >= r) return;
		int mid = (lo + hi) >> 1;
		for (int i = l; i < r; i++) b[lv][i] = (a[i] <= mid ? 1 : 0);
		if (lo == hi) return;
		int m = stable_partition(a.begin() + l, a.begin() + r, [mid](int x) {
			return x <= mid;
		}) - a.begin();
		construct(a, lv + 1, l, m, lo, mid);
		construct(a, lv + 1, m, r, mid + 1, hi);
	}
	int clt(int l, int r, int x) {
		return clt(l, r, x, 0, 0, n - 1, mn, mx);
	}
	int clt(int l, int r, int x, int lv, int nl, int nr, int lo, int hi) {
		if (l > r || x <= lo) return 0;
		if (hi < x) return r - l + 1;
		int mid = (lo + hi) >> 1;
		int cl = (l ? b[lv][l - 1] : 0) - (nl ? b[lv][nl - 1] : 0);
		int cr = b[lv][r] - (nl ? b[lv][nl - 1] : 0);
		int m = nl + b[lv][nr] - (nl ? b[lv][nl - 1] : 0);
		return
			clt(nl + cl, nl + cr - 1, x, lv + 1, nl, m - 1, lo, mid) +
			clt(m + l - nl - cl, m + r - nl - cr, x, lv + 1, m, nr, mid + 1, hi);
	}
};

int n, k, q, last = 0, x, y, temp, l, r;
vector<int> a, b[100001];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		if (b[temp].size() < k) a.push_back(0);
		else a.push_back(b[temp][b[temp].size() - k]);
		b[temp].push_back(i);
	}
	wavelet w = wavelet(a);
	cin >> q;
	while (q--) {
		cin >> x >> y;
		l = (x + last) % n + 1;
		r = (y + last) % n + 1;
		if (l > r) swap(l, r);
		last = w.clt(l - 1, r - 1, l);
		cout << last << endl;
	}
}
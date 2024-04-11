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

int n, m;
vector<int> a, b, c, k;

wavelet W;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	for (int i = 0, x; i < n; i++)
		cin >> x, a[x - 1] = i;
	for (int i = 0, x; i < m; i++)
		cin >> x, b[x - 1] = i;
	c.reserve(n + m);
	for (auto &i : a) c.push_back(i);
	for (auto &i : b) c.push_back(i);
	W = wavelet(c);
	k.resize(n + m, 0);
	for (int i = 1; i < n + m; i++) {
		if (i == n) {
			k[i] = 1;
			continue;
		}
		int l = k[i - 1];
		while (l == n || (l > 0 && W.clt(0, l - 1, c[l]) != W.clt(i - l, i - 1, c[i]))) l = k[l - 1];
		k[i] = l + 1;
	}
	int ans = 0;
	for (auto &i : k) if (i == n) ans++;
	finish(ans);
}
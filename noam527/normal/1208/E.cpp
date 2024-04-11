#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

struct maxqueue {
	int n;
	ll A[1000005];
	int I[1000005];
	int nxtin, nxtout, l, r;
	maxqueue() {
		nxtin = nxtout = l = r = 0;
	}
	void restart() {
		nxtin = nxtout = l = r = 0;
	}
	void push(ll x) {
		while (l < r && A[r - 1] <= x) r--;
		A[r] = x;
		I[r] = nxtin++;
		r++;
	}
	void pop() {
		if (I[l] == nxtout) l++;
		nxtout++;
	}
	ll query() {
		return A[l];
	}
};

int t, w;
vector<ll> ans;
vector<ll> a;
maxqueue Q;
int curl, curr;

ll query(int nl, int nr) {
	while (curr < nr) {
		curr++;
		Q.push(a[curr]);
	}
	while (curl < nl) {
		Q.pop();
		curl++;
	}
	return Q.query();
}

void add(int l, int r, ll v, bool skip = false) {
	if (l > r) return;
	if (v < 0 && skip) return;
	//cout << "adding value " << v << '\n';
	ans[l] += v;
	if (r + 1 < w) ans[r + 1] -= v;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> t >> w;
	ans.resize(w);
	while (t--) {
		int m;
		cin >> m;
		a.resize(m);
		for (auto &i : a) cin >> i;
		if (2 * m <= w) {
			ll mx = -md;
			for (int i = 0; i < m; i++) {
				mx = max(mx, a[i]);
				add(i, i, mx, true);
			}
			mx = -md;
			int nxt = w - 1;
			for (int i = m - 1; i >= 0; i--) {
				mx = max(mx, a[i]);
				add(nxt, nxt, mx, true);
				nxt--;
			}
			add(m, nxt, mx, true);
		}
		else {
			Q.restart();
			Q.push(a[0]);
			curl = curr = 0;
			for (int i = 0; i < w; i++) {
				//cout << "adding to " << i << " query " << max(0, m - (w - i)) << " " << min(m - 1, i) << '\n';
				bool tmp = false;
				if (m - (w - i) < 0) tmp = true;
				if (i >= m) tmp = true;
				add(i, i, query(max(0, m - (w - i)), min(m - 1, i)), tmp);
			}
		}
	}
	for (int i = 1; i < w; i++) ans[i] += ans[i - 1];
	for (int i = 0; i < w; i++) cout << ans[i] << " "; cout << '\n';
}
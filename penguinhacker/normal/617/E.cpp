#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 100000;
const int B = 300;
int n, m, k, a[mxN], pre[mxN + 1], cnt[1 << 20];
ll cur = 0, ans[mxN];

struct Query {
	int l, r, ind;
	bool operator<(const Query& o) const {return l / B != o.l / B ? l / B < o.l / B : r < o.r;}
} qry[mxN];

void Add(int ind) {
	cur += cnt[pre[ind] ^ k];
	++cnt[pre[ind]];
}
void Remove(int ind) {
	--cnt[pre[ind]];
	cur -= cnt[pre[ind] ^ k];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		pre[i + 1] = pre[i] ^ a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> qry[i].l >> qry[i].r, --qry[i].l, qry[i].ind = i;
	}
	sort(qry, qry + m);
	for (int i = 0, l = 0, r = 0; i < m; ++i) {
		int ql = qry[i].l, qr = qry[i].r;
		while(l > ql) Add(--l);
		while(r <= qr) Add(r++);
		while(l < ql) Remove(l++);
		while(r > qr + 1) Remove(--r);
		ans[qry[i].ind] = cur;
	}
	for (int i = 0; i < m; ++i) {
		cout << ans[i] << "\n";
	}
	return 0;
}
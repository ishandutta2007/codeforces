#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int n, ma, ans, o[500005], m[500005], l[500005], r[500005], ftv[500005];
pair<int, int> d[500005];
 
inline int ls(int x) { return x & -x; }
 
struct node {
	node *left, *right;
	int S, E, vcnt, cnt;
	bool ip = 0;
	node(int _s, int _e) : S(_s), E(_e), vcnt(0), cnt(0) {
		if (S == E)
			return;
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	void prop() {
		if (S == E || !ip) return;
		left->vcnt = left->cnt = right->vcnt = right->cnt = 0;
		left->ip  = right->ip = 1;
		ip = 0;
	}
	void upd(int p, int v1, int v2) {
		if (S == E) {
			vcnt += v1;
			cnt += v2;
			return;
		}
		prop();
		int M = (S + E) >> 1;
		if (p <= M) left->upd(p, v1, v2);
		else right->upd(p, v1, v2);
		vcnt = left->vcnt + right->vcnt;
		cnt = left->cnt + right->cnt;
	}
	void rset(int l, int r) {
		if (l > E || r < S) return;
		if (l <= S && r >= E) {
			vcnt = cnt = 0;
			ip = 1;
			return;
		}
		prop();
		left->rset(l, r);
		right->rset(l, r);
	}
	pair<int, int> qry(int l, int r) {
		if (l > E || r < S) return make_pair(0, 0);
		if (l <= S && r >= E) return make_pair(vcnt, cnt);
		prop();
		auto lq = left->qry(l, r), rq = right->qry(l, r);
		lq.first += rq.first;
		lq.second += rq.second;
		return lq;
	}
} *root;
 
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> m[i], d[i] = make_pair(m[i], i);
	sort(d + 1, d + 1 + n);
	for (int i = 1, cnt = 1; i <= n; i++) {
		ftv[d[i].second] = cnt;
		if (i == n || d[i].first ^ d[i + 1].first) cnt++;
	}
	root = new node(1, n);
	for (int i = 1; i <= n; i++) {
		if (m[i] < m[i - 1]) {
			auto v = root->qry(ftv[i] + 1, n);
			l[i] = l[i - 1] - v.first + v.second * m[i];
			root->rset(ftv[i] + 1, n);
			root->upd(ftv[i], v.second * m[i], v.second);
		} else l[i] = l[i - 1];
		l[i] += m[i];
		root->upd(ftv[i], m[i], 1);
	}
	root->rset(1, n);
	for (int i = n; i >= 1; i--) {
		if (m[i] < m[i + 1]) {
			auto v = root->qry(ftv[i] + 1, n);
			r[i] = r[i + 1] - v.first + v.second * m[i];
			root->rset(ftv[i] + 1, n);
			root->upd(ftv[i], v.second * m[i], v.second);
		} else r[i] = r[i + 1];
		r[i] += m[i];
		root->upd(ftv[i], m[i], 1);
	}
	for (int i = 1; i <= n; i++) {
		if (l[i] + r[i] - m[i] >= ma) {
			ma = l[i] + r[i] - m[i];
			ans = i;
		}
	}
	for (int j = ans - 1, lim = m[ans]; j >= 1; j--) {
		lim = min(lim, m[j]);
		o[j] = lim;
	}
	for (int j = ans + 1, lim = m[ans]; j <= n; j++) {
		lim = min(lim, m[j]);
		o[j] = lim;
	}
	o[ans] = m[ans];
	for (int i = 1; i <= n; i++) cout << o[i] << ' ';
	cout << '\n';
}
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##e = (r); i <= i##e; i++)
#define per(i, r, l) for(int i = (r), i##e = (l); i >= i##e; i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define rev(i) reverse(&s[i][1], &s[i][m + 1])

using namespace std;
using ll = long long;

const int N = 2e5 + 5;
const ll P = 999999937;

ll bas[26], hsh[N], g[N];
int n, m, c[N];
string s[N];
vector<int> id[N];
struct trie {
	int sz, ch[N][26], ed[N], pre[N], suf[N], idx, rk[N];
	int L[N], R[N];
	void ins(int i) {
		int o = 0;
		rep(j, 1, m) {
			int& oo = ch[o][s[i][j] - 97];
			o = oo = oo ? oo : ++sz;
		}
		ed[o] = i;
	}
	void clr() {
		rep(i, 0, sz) mem(ch[i], 0), ed[i] = 0;
		sz = idx = 0;
	}
	void dfs(int u) {
		pre[u] = idx + 1;
		if(ed[u]) rk[ed[u]] = ++idx;
		rep(i, 0, 25) if(ch[u][i]) dfs(ch[u][i]);
		suf[u] = idx;
	}
	void get(int i) {
		int o = 0;
		L[0] = pre[0], R[0] = suf[0];
		rep(j, 1, m) {
			o = ch[o][s[i][j] - 97];
			L[j] = pre[o], R[j] = suf[o];
		}
	}
} A, B;
vector<int> pts[N];
struct Qry { int l, r, t; };
vector<Qry> qs[N];
void add(int i, int v) {
	for(; i <= n; i += i & -i) c[i] += v;
}
int qry(int i, int r = 0) {
	for(; i; i &= i - 1) r += c[i];
	return r;
}

int main() {
#ifdef local
	freopen(".in", "r", stdin);
#endif
	bas[0] = 1;
	rep(i, 1, 25) bas[i] = bas[i - 1] * 29 % P;
	cin >> n;
	rep(i, 1, n) {
		s[i].resize(N / n + 5), scanf("%s", &s[i][1]);
		m = strlen(&s[i][1]);
		rep(j, 1, m) (hsh[i] += bas[s[i][j] - 97]) %= P;
		g[i] = hsh[i];
	}
	sort(g + 1, g + n + 1);
	rep(i, 1, n) id[lower_bound(g + 1, g + n + 1, hsh[i]) - g].pb(i);
	ll as = 0, su = 0;
	rep(j, 1, n) {
		int sz = id[j].size();
		as += sz * su * 1337 + (sz - 1ll) * sz, su += sz;
		for(int i : id[j]) A.ins(i), rev(i);
		for(int i : id[j]) B.ins(i), rev(i);
		A.dfs(0), B.dfs(0);
		for(int i : id[j]) pts[A.rk[i]].pb(B.rk[i]);
		for(int i : id[j]) {
			A.get(i), rev(i), B.get(i), rev(i);
			int ls = 1;
			rep(k, 1, m) if(k == m || s[i][k] > s[i][k + 1]) {
				int l = B.L[m - k], r = B.R[m - k];
				qs[A.L[ls - 1] - 1].pb({l, r, -1}), qs[A.R[ls - 1]].pb({l, r, 1}), as++, ls = k + 1;
			}
		}
		rep(i, 1, sz) {
			for(int k : pts[i]) add(k, 1);
			for(auto [l, r, t] : qs[i]) as -= (qry(r) - qry(l - 1)) * t;
		}
		rep(i, 1, sz) for(int k : pts[i]) add(k, -1);
		A.clr(), B.clr();
		rep(i, 1, sz) pts[i].clear(), qs[i].clear();
	}
	cout << as;
	return 0;
}
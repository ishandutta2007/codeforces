#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define m c[o]

using namespace std;
const int N = 3e5 + 5;
struct node {
	int c[2], f, ma; multiset <int> v;
	node() { v.insert(ma = -1); }
	void modify(int x, int y) { v.erase(v.find(x)), v.insert(y); }
} c[N];
int id(int o) { return o == c[m.f].c[1]; }
int nrt(int o) { return m.f && c[m.f].c[id(o)] == o; }
void pushup(int o) { m.ma = max(*m.v.rbegin(), max(c[m.c[0]].ma, c[m.c[1]].ma)); }
void rot(int o, int d) {
	int k = m.c[!d], &x = c[k].c[d];
	if(nrt(o)) c[m.f].c[id(o)] = k;
	pushup(x = c[m.c[!d] = x].f = o), c[k].f = m.f, pushup(m.f = k);
}
void splay(int o) {
	for(int f; nrt(o); rot(m.f, !id(o)))
	if(nrt(f = m.f)) rot(id(o) == id(f) ? c[f].f : f, !id(o));
}
void acc(int o) {
	for(int x = 0; o; o = c[x = o].f) splay(o), m.c[1] = x, pushup(o);
}
int n, K, sz = 1, ch[N][26], ed[N], w[N], q[N]; char s[N];
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> K;
	rep(i, 1, n) {
		scanf("%s", s);
		int o = 1;
		for(char* j = s; *j; j++) {
			int& oo = ch[o][*j-97];
			o = oo = oo ? oo : ++sz;
		} c[ed[i] = o].v.insert(0);
	}
	int l = 1, r = 0;
	rep(i, 0, 25) if(ch[1][i]) c[q[++r] = ch[1][i]].f = 1; else ch[1][i] = 1;
	for(; l <= r; l++) rep(i, 0, 25) {
		int o = q[l], &oo = ch[o][i];
		if(oo) c[q[++r] = oo].f = ch[m.f][i];
		else oo = ch[m.f][i];
	}
	for(int op, i, x; K--;) {
		scanf("%d", &op);
		if(op == 1) {
			scanf("%d%d", &i, &x), splay(ed[i]);
			c[ed[i]].modify(w[i], x), w[i] = x, pushup(ed[i]);
		} else {
			scanf("%s", s);
			int o = 1, ans = -1;
			for(char* j = s; *j; j++)
				o = ch[o][*j-97], acc(o), splay(o), ans = max(ans, m.ma);
			printf("%d\n", ans);
		}
	}
	return 0;
}
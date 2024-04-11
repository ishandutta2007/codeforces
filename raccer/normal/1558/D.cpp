#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define rnd() (rand() << 15 | rand())
using namespace std;

const int mod = 998244353;

struct Treap {
	struct Node {
		int x, fix, tag;
		Node *lson, *rson;
		Node() {fix = rnd();}
		void addtag(int t) {x += t, tag += t;}
		void pushdown() {
			if (!tag) return ;
			if (lson) lson->addtag(tag);
			if (rson) rson->addtag(tag);
			tag = 0;
		}
	}POOL[400010], *CUR, *rt;
	void clear() {CUR = POOL, rt = NULL;}
	typedef pair <Node *, Node *> pnn;
	Node *merge(Node *l, Node *r) {
		if (!l || !r) return l ? l : r;
		if (l->fix > r->fix) {
			l->pushdown();
			l->rson = merge(l->rson, r);
			return l;
		} else {
			r->pushdown();
			r->lson = merge(l, r->lson);
			return r;
		}
	}
	pnn split(Node *T, int x) {
		if (!T) return pnn(NULL, NULL);
		T->pushdown();
		if (x < T->x) {
			pnn t = split(T->lson, x);
			T->lson = t.se;
			return mp(t.fi, T);
		} else {
			pnn t = split(T->rson, x);
			T->rson = t.fi;
			return mp(T, t.se);
		}
	}
	int count(int x) {
		pnn t1 = split(rt, x - 1), t2 = split(t1.se, x);
		int ans = t2.fi ? 1 : 0;
		rt = merge(t1.fi, merge(t2.fi, t2.se));
		return ans;
	}
	void insert(int x) {
		pnn t = split(rt, x);
		Node *now = CUR++; now->x = x, now->tag = 0, now->lson = now->rson = NULL;
		rt = merge(t.fi, merge(now, t.se));
	}
	void AddRng(int x) {
		pnn t = split(rt, x - 1);
		if (t.se) t.se->addtag(1);
		rt = merge(t.fi, t.se);
	}
}S;

long long fac[500010], inv[500010];

long long power(long long a, int b) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ans;
}

long long C(int n, int k) {
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int main() {
	fac[0] = 1;
	for (int i = 1; i <= 500005; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	for (int i = 0; i <= 500005; i++) {
		inv[i] = power(fac[i], mod - 2);
	}
	srand((int)time(NULL)), rnd();
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		S.clear();
		int sz = 0;
		for (int i = 0; i < m; i++) {
			int x, y; scanf("%d%d", &x, &y);
			if (S.count(y - 1)) S.AddRng(y - 1);
			else {
				S.AddRng(y);
				S.insert(y), sz++;
			}
		}
		printf("%lld\n", C(n + n - sz - 1, n));
	}
	return 0;
}
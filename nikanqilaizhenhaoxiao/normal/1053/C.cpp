#include <bits/stdc++.h>

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

const int maxn = 2e5 + 10, mod = 1e9 + 7;

struct node {
	node *ch[2];
	long long sw;
	int sxw;

	node() { ch[0] = ch[1] = 0; sw = sxw = 0; }

	void pull() {
		sw = ch[0]->sw + ch[1]->sw;
		sxw = (ch[0]->sxw + ch[1]->sxw) % mod;
		return;
	}
} *root;

int n, q, a[maxn], w[maxn];

void B(node* &u = root, int l = 1, int r = n) {
	u = new node;
	if(l == r) { u->sw = w[l]; u->sxw = (long long) (a[l] - l) * w[l] % mod; return; }
	int mid = l + r >> 1;
	B(u->ch[0], l, mid);
	B(u->ch[1], mid + 1, r);
	return u->pull();
}

void M(int i, node* &u = root, int l = 1, int r = n) {
	if(l == r) { u->sw = w[l]; u->sxw = (long long) (a[l] - l) * w[l] % mod; return; }
	int mid = l + r >> 1;
	if(i <= mid) M(i, u->ch[0], l, mid);
	else M(i, u->ch[1], mid + 1, r);
	return u->pull();
}

long long Qsw(int a, int b, node* &u = root, int l = 1, int r = n) {
	if(a <= l && r <= b) return u->sw;
	int mid = l + r >> 1;
	long long t = 0;
	if(a <= mid) t += Qsw(a, b, u->ch[0], l, mid);
	if(b > mid) t += Qsw(a, b, u->ch[1], mid + 1, r);
	return t;
}

int Qsxw(int a, int b, node* &u = root, int l = 1, int r = n) {
	if(a <= l && r <= b) return u->sxw;
	int mid = l + r >> 1;
	int t = 0;
	if(a <= mid) t = (t + Qsxw(a, b, u->ch[0], l, mid)) % mod;
	if(b > mid) t = (t + Qsxw(a, b, u->ch[1], mid + 1, r)) % mod;
	return t;
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) scanf("%d", w + i);
	B();
	for (int i = 1; i <= q; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		if(x < 0) {
			x = -x;
			w[x] = y;
			M(x);
		}
		else {
			int lb = x, rb = y;
			long long s = Qsw(lb, rb);
#ifdef DEBUG
			printf("s = %"LLFORMAT"d\n", s);
#endif
			while(lb <= rb) {
				int mid = lb + rb >> 1;
				long long t = Qsw(x, mid);
				if(t > s - t) rb = mid - 1;
				else lb = mid + 1;
			}
//			int pivot = lb;
#ifdef DEBUG
			printf("pivot = %d\n", lb);
#endif
			int ans = 0;
			if(x <= rb) {
				int sw = Qsw(x, rb) % mod, sxw = Qsxw(x, rb);
				ans = ((long long) (a[lb] - lb) * sw - sxw) % mod;
			}
			if(lb + 1 <= y) {
				int sw = Qsw(lb + 1, y) % mod, sxw = Qsxw(lb + 1, y);
				ans = ((long long) (lb - a[lb]) * sw + sxw + ans) % mod;
			}
			printf("%d\n", (ans + mod) % mod);
		}
	}
	return 0;
}
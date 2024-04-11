#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int MOD = 1000000007;

inline int add(int u, int v) {
    u += v;
    if (u >= MOD) {
        u -= MOD;
    }
    return u;
}

inline int sub(int u, int v) {
    u -= v;
    if (u < 0) {
        u += MOD;
    }
    return u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) {
            res = mul(res, u);
        }
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

inline int inv(int u) {
    return power(u, MOD - 2);
}


int n, q;
int a[N], w[N];

struct IT {
	long long ww[N << 2];
	int aa[N << 2];

	void init(int node, int l, int r) {
		if (l == r) {
			ww[node] = w[l];
			aa[node] = mul(a[l], w[l]);
			return;
		}
		int m = l + r >> 1;
		init(node << 1, l, m);
		init(node << 1 | 1, m + 1, r);
		ww[node] = ww[node << 1] + ww[node << 1 | 1];
		aa[node] = add(aa[node << 1], aa[node << 1 | 1]);
	}

	void update(int node, int l, int r, int x) {
		if (x > r || x < l) {
			return;
		}
		if (l == r) {
			ww[node] = w[l];
			aa[node] = mul(a[l], w[l]);
			return;
		}
		int m = l + r >> 1;
		update(node << 1, l, m, x);
		update(node << 1 | 1, m + 1, r, x);
		ww[node] = ww[node << 1] + ww[node << 1 | 1];
		aa[node] = add(aa[node << 1], aa[node << 1 | 1]);
	}

	long long get(int node, int l, int r, int x, int y) {
		if (x > r || y < l) {
			return 0ll;
		}
		if (x <= l && r <= y) {
			return ww[node];
		}
		int m = l + r >> 1;
		long long p1 = get(node << 1, l, m, x, y);
		long long p2 = get(node << 1 | 1, m + 1, r, x, y);
		return p1 + p2;
	}

	int getMod(int node, int l, int r, int x, int y) {
		if (x > r || y < l) {
			return 0;
		}
		if (x <= l && r <= y) {
			return aa[node];
		}
		int m = l + r >> 1;
		int p1 = getMod(node << 1, l, m, x, y);
		int p2 = getMod(node << 1 | 1, m + 1, r, x, y);
		return add(p1, p2);
	}

	int findId(int node, int l, int r, long long x) {
		if (l == r) {
			return l;
		}
		long long foo = ww[node << 1];
		int m = l + r >> 1;
		if (foo >= x) {
			return findId(node << 1, l, m, x);
		} else {
			return findId(node << 1 | 1, m + 1, r, x - foo);
		}
	}
} it;

int getVal(int l, int r, int id) {
	if (r < l) {
		return 0;
	}
	int x = it.get(1, 1, n, l, r) % MOD;
	x = mul(x, a[id]);
	int y = it.getMod(1, 1, n, l, r);
	return sub(x, y);
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		a[i] -= i;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", w + i);
	}
	it.init(1, 1, n);
	while (q--) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (x < 0) { //update
			x = -x;
			w[x] = y;
			it.update(1, 1, n, x);
		} else {
			int l = x, r = y;
			long long foo = it.get(1, 1, n, 1, l - 1) + it.get(1, 1, n, 1, r);
			foo = (foo + 1ll) / 2ll;
			int id = it.findId(1, 1, n, foo);
			int res = sub(getVal(l, id - 1, id), getVal(id + 1, r, id));
			printf("%d\n", res);
		}
	}
	return 0;
}
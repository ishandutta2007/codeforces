#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7, inf = INT_MAX;
const double pi = acos(-1.0);

template <typename T>
class SegmentTree {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<T> t;
    vector<ll> lazy, color;
    T e;
    F f;
    SegmentTree() : n(), t(), lazy(), e(), f() {}

    template <typename U>
    SegmentTree(const U& arr, int n, T e, F f): n(n), t(4 * n), lazy(4 * n), color(4 * n), e(e), f(f) {
        build(arr, 1, 0, n - 1);
    }

    template <typename U>
    void build(const U& arr, int i, int l, int r) {
        if (l == r) {
            t[i] = T(arr[l], l);
            return;
        }

        int mid = (l + r) >> 1;
        build(arr, i << 1, l, mid);
        build(arr, i << 1 | 1, mid + 1, r);

        t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    void push (int x, int l, int r) {
        if (lazy[x]) {
        	int mid = (l + r) >> 1;
            t[x << 1].sum += (mid - l + 1) * lazy[x];
            t[x << 1 | 1].sum += (r - mid) * lazy[x];
            lazy[x << 1] += lazy[x];
            lazy[x << 1 | 1] += lazy[x];
            lazy[x] = 0;
        }
        if (color[x]) {
			tie(t[x << 1].l, t[x << 1].r) = make_pair(t[x].l, t[x].r);
			tie(t[x << 1 | 1].l, t[x << 1 | 1].r) = make_pair(t[x].l, t[x].r);
			color[x << 1] = 1;
			color[x << 1 | 1] = 1;
        	color[x] = 0;
        }
    }

    template <typename U>
    void update(int ql, int qr, U val) {
        updateHelper(ql, qr, val, 1, 0, n - 1);
    }

    template <typename U>
    void updateHelper(int ql, int qr, U val, int i, int l, int r) {
        if (ql > r or qr < l)
            return;
        if (ql <= l and r <= qr) {
            if (val == INT_MAX) {
				color[i] = 1;
				t[i].l = ql;
				t[i].r = qr;
            } else {
				t[i].sum += (ll)(r - l + 1) * val;
				lazy[i] += val;
            }
            return;
        }
        push(i, l, r);
        int mid = (l + r) >> 1;
        updateHelper(ql, qr, val, i << 1, l, mid);
        updateHelper(ql, qr, val, i << 1 | 1, mid + 1, r);

        t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    T query(int ql, int qr) {
        return queryHelper(ql, qr, 1, 0, n - 1);
    }

    T queryHelper(int ql, int qr, int i, int l, int r) {
        if (ql > r or qr < l)
            return e;
        if (ql <= l and r <= qr)
            return t[i];
        push(i, l, r);
        int mid = (l + r) >> 1;
        T x = queryHelper(ql, qr, i << 1, l, mid), y = queryHelper(ql, qr, i << 1 | 1, mid + 1, r);
        return f(x, y);
    }
};

struct node {
	int l, r;
	ll sum;
	node(): sum(), l(-1), r(-1) {}
	node(int x, int i): sum(x), l(i), r(i) {}
};

node combine(const node& a, const node& b) {
	if (b.r == -1) {
		return a;
	}
	node res = b;
	res.sum += a.sum;
	return res;
}

const int N = 1e5 + 5;

int n, q, a[N], k[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++) cin >> k[i];

	SegmentTree<node> st(a, n, node(), combine);

	cin >> q;
	while (q--) {
		char c;
		cin >> c;

		if (c == '+') {
			int i, x;
			cin >> i >> x; --i;
			node res = st.query(i, i);
			if (res.l < i) {
				st.update(res.l, i - 1, INT_MAX);
			}
			int j = res.r;
			st.update(i, j, x);

			j = j + 1;
			while (j < n) {
				res = st.query(j, j);
				ll diff = res.sum - (st.query(j - 1, j - 1).sum + k[j - 1]);
				if (diff < 0) {
					st.update(j, res.r, -diff);
				} else {
					break;
				}
				j = res.r + 1;
			}
			st.update(i, j - 1, INT_MAX);
		} else {
			int l, r;
			cin >> l >> r;
			cout << st.query(--l, --r).sum << '\n';
		}
	}
	return 0;
}
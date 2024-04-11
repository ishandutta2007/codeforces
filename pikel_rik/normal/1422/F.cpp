#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

ll modexp(ll x, ll n) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return ans;
}

ll modinv(ll x) {
    return modexp(x, mod - 2);
}

template <typename T>
class Persistent {
public:
    using F = function<T(const T&, const T&)>;

    struct Node {
        T val;
        Node *l, *r;
        Node(T val) : val(val), l(nullptr), r(nullptr) {}
        Node(T val, Node *l, Node *r): val(val), l(l), r(r) {}
    };

    int n;
    vector<Node*> root;
    Node *curVer;
    T e;
    F f;
    Persistent(): root(), n(), curVer(), e(), f() {}

    void changeVer(int k) {
        curVer = root[k - 1];
    }

    template <typename U>
    Persistent(const U& arr, int n, T e, F f): n(n), e(e), f(f) {
        root.push_back(build(arr, 0, n - 1));
        curVer = root.back();
    }

    template <typename U>
    Node* build(const U& arr, int l, int r) {
        if (l == r)
            return new Node(T(arr[l]));
        int mid = (l + r) >> 1;
        Node* temp1 = build(arr, l, mid);
        Node* temp2 = build(arr, mid + 1, r);
        return new Node(f(temp1->val, temp2->val), temp1, temp2);
    }

    template <typename U>
    void update(int idx, U val) {
        root.push_back(updateHelper(idx, val, curVer, 0, n - 1));
        curVer = root.back();
    }

    template <typename U>
    Node* updateHelper(int idx, U val, Node *v, int l, int r) {
        if (l == r)
            return new Node((ll)v->val * val % mod);
        int mid = (l + r) >> 1;
        if (idx <= mid) {
            Node *temp = updateHelper(idx, val, v->l, l, mid);
            return new Node(f(temp->val, v->r->val), temp, v->r);
        } else {
            Node *temp = updateHelper(idx, val, v->r, mid + 1, r);
            return new Node(f(v->l->val, temp->val), v->l, temp);
        }
    }

    T query(int ql, int qr) {
        return queryHelper(ql, qr, curVer, 0, n - 1);
    }

    T queryHelper(int ql, int qr, Node *v, int l, int r) {
        if (ql > r or l > qr)
            return e;
        if (ql <= l and r <= qr)
            return v->val;
        int mid = (l + r) >> 1;
        return f(queryHelper(ql, qr, v->l, l, mid), queryHelper(ql, qr, v->r, mid + 1, r));
    }
};

template <typename T>
class SegmentTree {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<T> t;
    T e;
    F f;
    SegmentTree() : n(), t(), e(), f() {}

    template <typename U>
    SegmentTree(const U& arr, int n, T e, F f): n(n), t(4 * n), e(e), f(f) {
        build(arr, 1, 0, n - 1);
    }

    template <typename U>
    void build(const U& arr, int i, int l, int r) {
        if (l == r) {
            t[i] = T(arr[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(arr, i << 1, l, mid);
        build(arr, i << 1 | 1, mid + 1, r);

        t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    template <typename U>
    void update(int idx, U val) {
        updateHelper(idx, val, 1, 0, n - 1);
    }

    template <typename U>
    void updateHelper(int idx, U val, int i, int l, int r) {
        if (l == r) {
            t[i] = T(val);
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid)
            updateHelper(idx, val, i << 1, l, mid);
        else updateHelper(idx, val, i << 1 | 1, mid + 1, r);

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
        int mid = (l + r) >> 1;
        T x = queryHelper(ql, qr, i << 1, l, mid), y = queryHelper(ql, qr, i << 1 | 1, mid + 1, r);
        return f(x, y);
    }
};

const int N = 1e5 + 5;
const int A = 2e5;

int pos[A + 1], inv[A + 1];
vector<int> primes;
vector<pair<int, int>> factors[A + 1];

void precomp() {
	for (int i = 2; i <= A; i++) {
		if (factors[i].empty()) {
			for (int j = i; j <= A; j += i) {
				factors[j].emplace_back(i, 1);
				int temp = j;
				while (temp % i == 0) {
					factors[j].back().second *= i;
					temp /= i;
				}
			}
		}
	}
	for (int i = 2; i * i <= A; i++) {
		if (factors[i][0].first == i) {
			pos[i] = (int)primes.size();
			primes.push_back(i);
		}
	}
	for (int i = 2; i <= A; i++) {
		if (factors[i][0].first == i) {
			inv[i] = modinv(i);
		}
	}
}

struct node {
	vector<int> mx;
	node() {}
	node(int x): mx(primes.size(), 1) {
		for (auto& [p, c] : factors[x]) {
			if ((ll)p * p <= A) {
				mx[pos[p]] = c;
			}
		}
	}
};

node combine(const node& a, const node& b) {
	if (a.mx.empty()) {
		return b;
	}
	if (b.mx.empty()) {
		return a;
	}
	node res; res.mx.assign(primes.size(), 1);
	for (int i = 0; i < primes.size(); i++) {
		res.mx[i] = max(a.mx[i], b.mx[i]);
	}
	return res;
}

int n, a[N], prv[A], ver[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	precomp();
	memset(prv, -1, sizeof(prv));

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> temp(n, 1);
	Persistent<int> prst(temp, n, 1, [&] (int x, int y) {
		return (ll)x * y % mod;
	});

	for (int i = 0; i < n; i++) {
		for (auto& [p, c] : factors[a[i]]) {
			if (p <= primes.back()) continue;
			if (prv[p] != -1) {
				prst.update(prv[p], inv[p]);
			}
			prst.update(i, p);
			prv[p] = i;
		}
		ver[i] = (int)prst.root.size();
	}

	SegmentTree<node> st(a, n, node(), combine);
	int last = 0, q;
	cin >> q;

	while (q--) {
		int x, y;
		cin >> x >> y;
		int l = (last + x) % n, r = (last + y) % n;
		if (l > r) {
			swap(l, r);
		}
		prst.changeVer(ver[r]);
		last = prst.query(l, r);

		node res = st.query(l, r);
		for (int i = 0; i < primes.size(); i++) {
			last = (ll)last * res.mx[i] % mod;
		}
		cout << last << '\n';
	}
	return 0;
}
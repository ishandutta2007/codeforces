#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int MAX_PRIME = 10;

int MOD, n, q;
int a[N];
vector<int> primes;

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

inline int inv(int a) {
    int xa = 1, xb = 0;
    int b = MOD;
    while (b > 0) {
        int q = a / b;
        int r = a - b * q, xr = xa - xb * q;
        a = b, xa = xb;
        b = r, xb = xr;
    }
    xa %= MOD;
    if (xa < 0) xa += MOD;
    return xa;
}

pair<vector<int>, int> factorize(int u) {
    vector<int> power(primes.size());
    for (int i = 0; i < primes.size(); i++) {
        while (u % primes[i] == 0) {
            u /= primes[i];
            power[i]++;
        }
    }
    return make_pair(power, u);
}

struct IT {
    int val[N << 2], off[N << 2], t[N << 2];
    vector<int> power[N << 2];

    void init(int node, int l, int r) {
        power[node].resize(primes.size(), 0);
        val[node] = 1;
        off[node] = 1;
        if (l == r) {
            val[node] = t[node] = a[l] % MOD;
            tie(power[node], off[node]) = factorize(a[l]);
            return;
        }
        int m = l + r >> 1;
        init(node << 1, l, m);
        init(node << 1 | 1, m + 1, r);
        t[node] = add(t[node << 1], t[node << 1 | 1]);
    }

    void downChild(int node, int nodeChild) {
        val[nodeChild] = mul(val[nodeChild], val[node]);
        t[nodeChild] = mul(t[nodeChild], val[node]);
        off[nodeChild] = mul(off[nodeChild], off[node]);
        for (int i = 0; i < power[node].size(); i++) power[nodeChild][i] += power[node][i];
    }

    void down(int node) {
        downChild(node, node << 1);
        downChild(node, node << 1 | 1);
        val[node] = off[node] = 1;
        for (int i = 0; i < power[node].size(); i++) power[node][i] = 0;
    }

    void update(int node, int l, int r, int x, int y, int v, int o, const vector<int> &pw) {
        if (x > r || y < l) return;
        if (x <= l && r <= y) {
            val[node] = mul(val[node], v);
            t[node] = mul(t[node], v);
            off[node] = mul(off[node], o);
            for (int i = 0; i < pw.size(); i++) power[node][i] += pw[i];
            return;
        }
        int m = l + r >> 1;
        down(node);
        update(node << 1, l, m, x, y, v, o, pw);
        update(node << 1 | 1, m + 1, r, x, y, v, o, pw);
        t[node] = add(t[node << 1], t[node << 1 | 1]);
    }

    int calc(const vector<int> &pw) {
        int res = 1;
        for (int i = 0; i < pw.size(); i++) {
            res = mul(res, ::power(primes[i], pw[i]));
        }
        return res;
    }

    void des(int node, int l, int r, int x, int v, int o, const vector<int> &pw) {
        if (x > r || x < l) return;
        if (l == r) {
            off[node] = mul(off[node], inv(o));
            for (int i = 0; i < pw.size(); i++) power[node][i] -= pw[i];
            val[node] = calc(power[node]);
            val[node] = mul(val[node], off[node]);
            t[node] = val[node];
            return;
        }
        int m = l + r >> 1;
        down(node);
        des(node << 1, l, m, x, v, o, pw);
        des(node << 1 | 1, m + 1, r, x, v, o, pw);
        t[node] = add(t[node << 1], t[node << 1 | 1]);
    }

    int get(int node, int l, int r, int x, int y) {
        if (x > r || y < l) return 0;
        if (x <= l && r <= y) return t[node];
        int m = l + r >> 1;
        down(node);
        int p1 = get(node << 1, l, m, x, y);
        int p2 = get(node << 1 | 1, m + 1, r, x, y);
        return add(p1, p2);
    }
} t;

void init() {
    int u = MOD;
    for (int i = 2; i * i <= u; i++) {
        if (u % i == 0) {
            primes.push_back(i);
            while (u % i == 0) u /= i;
        }
    }
    if (u > 1) primes.push_back(u);
    t.init(1, 1, n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> MOD;
    for (int i = 1; i <= n; i++) cin >> a[i];
    init();
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            vector<int> power;
            int off;
            tie(power, off) = factorize(x);
            t.update(1, 1, n, l, r, x, off, power);
        } else if (op == 2) {
            int p, x;
            cin >> p >> x;
            vector<int> power;
            int off;
            tie(power, off) = factorize(x);
            t.des(1, 1, n, p, x, off, power);
        } else {
            int l, r;
            cin >> l >> r;
            cout << t.get(1, 1, n, l, r) << '\n';
        }
    }
    return 0;
}
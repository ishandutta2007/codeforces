#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int



#if 0
const int MOD = (int);

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void sub(int &x, int y) {
    x += MOD - y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}

inline int inv(int x) {
    return lgput(x, MOD - 2);
}
#endif

#if 0
int fact[], invfact[];

inline void prec(int n) {
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    invfact[n] = lgput(fact[n], MOD - 2);
    for(int i = n - 1; i >= 0; i--) {
        invfact[i] = (1LL * invfact[i + 1] * (i + 1)) % MOD;
    }
}

inline int comb(int n, int k) {
    if(n < k) return 0;
    return (1LL * fact[n] * (1LL * invfact[k] * invfact[n - k] % MOD)) % MOD;
}
#endif

using namespace std;

struct Fenwick {
    vector <int> aib;
    int n;

    inline void init(int _n) {
        n = _n;
        aib.resize(n + 1);
    }

    inline void update(int pos, int val) {
        for(int i = pos; i <= n; i += lsb(i)) {
            aib[i] += val;
        }
    }

    inline int query(int pos) {
        int ans = 0;
        for(int i = pos; i > 0; i -= lsb(i)) {
            ans += aib[i];
        }
        return ans;
    }

    inline int sum(int l, int r) {
        return query(r) - query(l - 1);
    }

    inline int kth(int pos) {
        int res = 0, cnt = 0;
        for(int step = 1 << 20; step; step >>= 1) {
            if(res + step <= n && aib[res + step] + cnt < pos) {
                res += step;
                cnt += aib[res];
            }
        }
        return res + 1;
    }
};

struct DSU {
    vector <int> par;
    int n;
    inline void init(int _n) {
        n = _n;
        par.resize(n + 1);
    }
    int root(int x) {
        if(par[x] == 0)
            return x;
        return par[x] = root(par[x]);
    }
    inline void join(int x, int y) {
        x = root(x), y = root(y);
        if(x != y) {
            par[x] = y;
        }
    }
};

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <int> id(2 * n + 1), l(n + 1), r(n + 1);

    for(i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        id[l[i]] = -i;
        id[r[i]] = i;
    }

    Fenwick fen; fen.init(2 * n);
    ll ans = 0;

    DSU dsu; dsu.init(n);

    for(i = 1; i <= 2 * n && ans < n; i++) {
        if(id[i] < 0) {
            int cur = fen.sum(l[-id[i]], r[-id[i]]);
            ans += cur;
            fen.update(r[-id[i]], 1);

            int pos = fen.query(l[-id[i]]);

            for(int j = 1; j <= cur; j++) {
                int p = fen.kth(pos + j);
                if(dsu.root(id[p]) == dsu.root(-id[i])) {
                    cout << "NO";
                    return 0;
                }
                dsu.join(id[p], -id[i]);
            }
        }
    }

    if(ans != n - 1) {
        cout << "NO";
        return 0;
    }

    cout << "YES";

    return 0;
}
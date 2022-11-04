#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int



#if 0
const int MOD = (int) ;

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
    Fenwick(int _n) {
        n = _n;
        aib.resize(n + 1);
    }
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

    vector <int> pos(n + 1);
    for(i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
    }

    Fenwick fen(n);
    ll ans = 0;

    for(i = 1; i <= n; i++) {

        ans += fen.sum(pos[i], n) - min(fen.sum(pos[i], n), fen.query(pos[i]));
        fen.update(pos[i], 1);

        int l = pos[i], r = pos[i];
        for(int step = 1 << 17; step; step >>= 1) {
            if(r + step <= n && 2 * fen.query(r + step) <= i) {
                r += step;
            }
            if(l - step > 0 && 2 * fen.sum(l - step, n) <= i) {
                l -= step;
            }
        }

        ans += r - l + 1;
        ans -= fen.sum(l, r);

        cout << ans << " ";
    }

    return 0;
}
#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long



#if 0
const int MOD = ;

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
};


int main() {
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <int> x(n), y(n);
    for(i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    auto nrm = [&](vector <int> &x) -> void {
        vector < pair <int, int> > cur;
        for(i = 0; i < n; i++) {
            cur.push_back({x[i], i});
        }
        sort(cur.begin(), cur.end());
        int sz = 0;
        for(i = 0; i < n; i++) {
            if(i == 0 || (i > 0 && cur[i].first != cur[i - 1].first)) sz++;
            x[cur[i].second] = sz;
        }
    };

    nrm(x);
    nrm(y);

    Fenwick fen; fen.init(n);
    vector <int> cnt(n + 1);
    for(i = 0; i < n; i++) {
        cnt[x[i]]++;
        if(cnt[x[i]] == 1) {
            fen.update(x[i], 1);
        }
    }

    vector < vector <int> > xs(n + 1);
    for(i = 0; i < n; i++) {
        xs[y[i]].push_back(x[i]);
    }

    ll ans = 0;
    for(i = 1; i <= n; i++) {
        if(xs[i].size() == 0) break;

        sort(xs[i].begin(), xs[i].end());

        int last = 0;
        for(auto it : xs[i]) {
            ans += 1LL * (fen.query(it) - last) * (fen.query(n) - fen.query(it) + 1);
            last = fen.query(it);
        }

        for(auto it : xs[i]) {
            cnt[it]--;
            if(cnt[it] == 0) {
                fen.update(it, -1);
            }
        }
    }

    cout << ans;

    return 0;
}
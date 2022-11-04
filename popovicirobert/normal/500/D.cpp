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

const int MAXN = (int) 2e5;

int a[MAXN + 1], b[MAXN + 1], l[MAXN + 1];
vector <int> g[MAXN + 1];
int sz[MAXN + 1];

void dfs(int nod, int par) {
    sz[nod] = 1;
    for(auto it : g[nod]) {
        int cur = (a[it] ^ b[it] ^ nod);
        if(cur != par) {
            dfs(cur, nod);
            sz[nod] += sz[cur];
        }
    }
}

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for(i = 1; i < n; i++) {
        cin >> a[i] >> b[i] >> l[i];
        g[a[i]].push_back(i);
        g[b[i]].push_back(i);
    }

    dfs(1, 0);

    auto get = [&](int sz) {
        return 1.0 * sz * (sz - 1) * (sz - 2) / (1.0 * n * (n - 1) * (n - 2));
    };

    auto get_coef = [&](int x, int y) {
        if(sz[x] < sz[y]) {
            swap(x, y);
        }
        return 1.0 - get(n - sz[y]) - get(sz[y]);
    };

    double ans = 0.0;
    for(i = 1; i < n; i++) {
        ans += 2.0 * l[i] * get_coef(a[i], b[i]);
    }

    cin >> q;
    while(q--) {
        int id, w;
        cin >> id >> w;

        ans -= 2.0 * l[id] * get_coef(a[id], b[id]);

        l[id] = w;

        ans += 2.0 * l[id] * get_coef(a[id], b[id]);

        cout << fixed << setprecision(20) << ans << "\n";
    }

    return 0;
}
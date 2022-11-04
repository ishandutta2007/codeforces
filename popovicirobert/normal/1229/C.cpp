#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int



#if 1
const int MOD = (int) 1e9 + 7;

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

const int MAXN = (int) 1e5;

vector <int> g[MAXN + 1], big[MAXN + 1];


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    vector <int> deg(n + 1), cnt(n + 1), a(n + 1);
    for(i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        big[min(x, y)].push_back(max(x, y));
        cnt[max(x, y)]++;
        deg[x]++, deg[y]++;
    }

    auto get = [&](int nod) {
        return 1LL * (deg[nod] - cnt[nod]) * cnt[nod];
    };

    ll ans = 0;
    for(i = 1; i <= n; i++) {
        ans += get(i);
    }

    cout << ans << "\n";

    int q; cin >> q;
    for(int qq = 1; qq <= q; qq++) {
        int nod; cin >> nod;
        ans -= get(nod);

        for(auto it : big[nod]) {
            ans -= get(it);
            big[it].push_back(nod), cnt[it]--;
            ans += get(it);
        }
        big[nod].clear(), cnt[nod] = deg[nod];

        cout << ans << "\n";
    }

    return 0;
}
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



int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int t, i, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;

    while(t--) {
        cin >> k;
        n = 2 * k;

        vector < vector < pair <int, int> > > g(n + 1);
        for(i = 1; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            g[x].push_back({y, z});
            g[y].push_back({x, z});
        }

        vector <ll> down(n + 1), dp(n + 1);
        vector <int> w(n + 1);

        function <void(int, int)> dfs = [&](int nod, int par) {
            w[nod] = 1;
            for(auto it : g[nod]) {
                if(it.first != par) {
                    dfs(it.first, nod);
                    w[nod] += w[it.first];
                    down[nod] += down[it.first] + 1LL * w[it.first] * it.second;
                    dp[nod] += dp[it.first] + 1LL * (w[it.first] / 2) * it.second;
                }
            }
        };

        dfs(1, 0);

        int cen;
        for(i = 1; i <= n; i++) {
            int mx = 0;
            for(auto it : g[i]) {
                int cur = w[it.first];
                if(cur > w[i]) {
                    cur = n - w[i];
                }
                mx = max(mx, cur);
            }
            if(mx <= n / 2) {
                cen = i;
            }
        }

        function <ll(int, int, ll)> solve_big = [&](int nod, int par, ll dst) {
            ll ans = dst;
            for(auto it : g[nod]) {
                if(it.first != par) {
                    ans += solve_big(it.first, nod, dst + it.second);
                }
            }
            return ans;
        };

        ll big = solve_big(cen, 0, 0);
        ll small = down[1] - 2 * dp[1];

        //cerr << "\n\n\n";

        cout << small << " " << big << "\n";
    }

    return 0;
}
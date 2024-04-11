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




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, k, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> q;

    while(q--) {
        cin >> n >> k;

        vector < vector < pair <int, int> > > g(n + 1);
        for(i = 1; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }

        vector < vector <ll> > dp(n + 1, vector <ll>(2));

        function <void(int, int)> dfs = [&](int nod, int par) {
            vector <ll> vals;

            for(auto it : g[nod]) {
                if(it.first != par) {
                    dfs(it.first, nod);

                    dp[nod][0] += dp[it.first][0];
                    dp[nod][1] += dp[it.first][0];
                    vals.push_back(dp[it.first][1] - dp[it.first][0] + it.second);
                }
            }

            sort(vals.rbegin(), vals.rend());

            //cerr << vals[0] << "\n";

            for(int i = 0; i < k && i < vals.size() && vals[i] > 0; i++) {
                dp[nod][0] += vals[i];
            }
            for(int i = 0; i + 1 < k && i < vals.size() && vals[i] > 0; i++) {
                dp[nod][1] += vals[i];
            }
        };

        dfs(1, 0);

        cout << dp[1][0] << "\n";
    }

    return 0;
}
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




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> k;

    vector < vector <int> > box(k);
    vector <int> n(k);
    vector <ll> sum(k);

    unordered_map <ll, int> mp;
    unordered_map <ll, bool> vis;

    ll s = 0;
    for(i = 0; i < k; i++) {
        cin >> n[i];

        box[i].resize(n[i]);
        for(j = 0; j < n[i]; j++) {
            cin >> box[i][j];

            mp[box[i][j]] = i;
            vis[box[i][j]] = 1;
            sum[i] += box[i][j];
        }

        s += sum[i];
    }

    if(llabs(s) % k != 0) {
        cout << "No";
        return 0;
    }

    s /= k;

    vector <bool> dp(1 << k);
    vector <int> root(1 << k), from(1 << k);

    for(i = 0; i < k; i++) {
        for(auto x : box[i]) {
            int conf = 0;
            ll y = x;

            while((conf & (1 << mp[y])) == 0) {
                conf |= (1 << mp[y]);
                y = s - (sum[mp[y]] - y);
                if(vis[y] == 0) {
                    break;
                }
            }

            if(y == x) {
                dp[conf] = 1;
                root[conf] = x;
            }
        }
    }

    for(int conf = 1; conf < (1 << k); conf++) {
        from[conf] = 0;
        for(int cur = conf; cur; cur = (cur - 1) & conf) {
            if(dp[cur] & dp[cur ^ conf]) {
                dp[conf] = 1, from[conf] = cur;
                break;
            }
        }
    }

    if(dp[(1 << k) - 1] == 0) {
        cout << "No";
        return 0;
    }

    cout << "Yes\n";

    vector < pair <int, int> > sol(k);

    int conf = (1 << k) - 1;
    while(conf > 0) {
        int cnf = (conf ^ from[conf]);
        ll x = root[cnf];

        while(1) {
            ll y = s - (sum[mp[x]] - x);
            sol[mp[y]] = {y, mp[x]};

            x = y;
            if(x == root[cnf]) {
                break;
            }
        }

        conf = from[conf];
    }

    for(i = 0; i < k; i++) {
        cout << sol[i].first << " " << sol[i].second + 1 << "\n";
    }

    return 0;
}
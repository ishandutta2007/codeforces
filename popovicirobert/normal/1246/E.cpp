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

bitset <2005> dp[1 << 16];

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;

    vector <int> a(n);
    for(i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp[0][0] = 1;
    for(int conf = 0; conf < (1 << n); conf++) {
        for(i = (2000 / k) * k; i > 0; i -= k) {
            dp[conf][i / k] = (dp[conf][i / k] | dp[conf][i]);
        }
        for(int bit = 0; bit < n; bit++) {
            if((conf & (1 << bit)) == 0) {
                dp[conf ^ (1 << bit)] = (dp[conf ^ (1 << bit)] | (dp[conf] << a[bit]));
            }
        }
    }

    if(dp[(1 << n) - 1][1] == 0) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    vector <int> pw(n);
    int conf = (1 << n) - 1, val = 1;

    while(conf & (conf - 1)) {
        if(val * k <= 2000 && dp[conf][val * k]) {
            val *= k;
            for(i = 0; i < n; i++) {
                if(conf & (1 << i))
                    pw[i]++;
            }
            continue;
        }
        else {
            for(int bit = 0; bit < n; bit++) {
                if((conf & (1 << bit)) && val >= a[bit] && dp[conf ^ (1 << bit)][val - a[bit]]) {
                    val -= a[bit];
                    conf ^= (1 << bit);
                    break;
                }
            }
        }
    }

    multiset < pair <int, int> > mst;
    for(i = 0; i < n; i++) {
        mst.insert({-pw[i], a[i]});
    }

    auto get = [&](int x) {
        pair <int, int> ans = {x, 0};
        while(ans.first % k == 0) {
            ans.first /= k;
            ans.second++;
        }
        return ans;
    };

    while(mst.size() > 1) {
        auto x = *mst.begin();
        auto y = *next(mst.begin());
        x.first *= -1, y.first *= -1;

        cout << x.second << " " << y.second << "\n";

        mst.erase(mst.begin());
        mst.erase(mst.begin());

        auto cur = get(x.second + y.second);

        mst.insert({-(x.first - cur.second), cur.first});
    }

    return 0;
}
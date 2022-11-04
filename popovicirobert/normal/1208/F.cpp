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

pair <int, int> dp[1 << 21];

inline void upd(pair <int, int> &a, int b) {
    if(a.first < b) {
        a.second = a.first;
        a.first = b;
    }
    else if(a.second < b) {
        a.second = b;
    }
}



int main() {
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <int> a(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        upd(dp[a[i]], i);
    }

    for(int bit = 0; bit <= 20; bit++) {
        for(i = (1 << 21) - 1; i >= 0; i--) {
            if((i & (1 << bit)) == 0) {
                upd(dp[i], dp[i ^ (1 << bit)].first);
                upd(dp[i], dp[i ^ (1 << bit)].second);
            }
        }
    }

    // dp[i].second = poz. max. unde ai doua care contin masca i


    int ans = 0;
    for(i = 1; i <= n - 2; i++) {
        int cur = 0;
        for(int bit = 20; bit >= 0; bit--) {
            if(a[i] & (1 << bit)) continue;
            if(dp[cur ^ (1 << bit)].second > i) {
                cur ^= (1 << bit);
            }
        }
        ans = max(ans, cur | a[i]);
    }

    cout << ans;

    return 0;
}
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
    int t, i, n, s;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;

    while(t--) {
        cin >> n >> s;

        vector <ll> sp(n + 1), a(n + 1);
        pair <int, int> ans = {0, 0};

        for(i = 1; i <= n; i++) {
            cin >> a[i];
            sp[i] = sp[i - 1] + a[i];
            if(sp[i] <= s) {
                ans = {i, 0};
            }
        }

        for(i = 1; i <= n; i++) {
            if(sp[i - 1] <= s) {
                int res = i - 1;
                for(int step = 1 << 18; step; step >>= 1) {
                    if(res + step <= n && sp[res + step] - a[i] <= s) {
                        res += step;
                    }
                }
                if(res - 1 > ans.first) {
                    ans.first = res - 1;
                    ans.second = i;
                }
            }
        }

        cout << ans.second << "\n";
    }

    return 0;
}
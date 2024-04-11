#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = 998244353;

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
}*/

/*int fact[], invfact[];

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
}*/

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    vector <int> arr(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int res = -1;
    for(int step = 1 << 18; step; step >>= 1) {
        int last = 0, ok = 1, cur = res + step;
        if(cur >= m) {
            continue;
        }
        for(i = 1; i <= n; i++) {
            int a, b;
            if(arr[i] + cur >= m) {
                // [arr[i], m - 1]
                // [0, arr[i] + cur - m]
                if(last > arr[i] + cur - m) {
                    if(last < arr[i]) {
                        last = arr[i];
                    }
                }
            }
            else {
                a = arr[i], b = arr[i] + cur;
                if(last > b) {
                    ok = 0;
                }
                else {
                    if(a > last) {
                        last = a;
                    }
                }
            }
        }
        if(ok == 0) {
            res = cur;
        }
    }

    cout << res + 1;

    return 0;
}
#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = (int) 1e9 + 7;

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

inline int get(int x) {
    int ans = 0;
    while((1 << ans) < x) {
        ans++;
    }
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, I;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> I;

    I *= 8;
    I /= n;
    I = min(I, 30);

    int pw = 1;
    while(I > 0) {
        pw *= 2;
        I--;
    }

    vector <int> arr(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector <int> sp(n + 1);
    sp[1] = 1;
    for(i = 2; i <= n; i++) {
        sp[i] = sp[i - 1] + (arr[i] != arr[i - 1]);
    }

    int ans = n + 1;
    for(i = 1; i <= n; i++) {
        if(sp[i] > sp[i - 1]) {
            int res = i;
            for(int step = 1 << 17; step; step >>= 1) {
                if(res + step <= n && sp[res + step] - sp[i - 1] <= pw) {
                    res += step;
                }
            }
            if(sp[res] - sp[i - 1] <= pw) {
                ans = min(ans, i - 1 + n - res);
            }
        }
    }

    cout << ans;

    return 0;
}
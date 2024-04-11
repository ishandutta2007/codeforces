#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


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

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <int> l(n + 1), r(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> l[i];
    }
    for(i = 1; i <= n; i++) {
        cin >> r[i];
        r[i]++;
    }

    vector <int> I(n + 1), E(n + 1);
    int sumI = 0;
    for(i = 1; i < n; i++) {
        int p = min(r[i], r[i + 1]) - max(l[i], l[i + 1]), q = 1LL * (r[i] - l[i]) * (r[i + 1] - l[i + 1]) % MOD;
        E[i] = 1LL * max(p, 0) * inv(q) % MOD; // egal
        I[i] = (1 - E[i] + MOD) % MOD; // diferit
        add(sumI, I[i]);
    }

    int ans = sumI;
    mul(ans, ans);

    for(i = 1; i < n; i++) {
        sub(ans, 1LL * I[i] * I[i] % MOD);
        sub(ans, 2LL * I[i] * I[i - 1] % MOD);
        add(ans, I[i]);

        ll cur;
        if(i > 1) {
            cur = 1LL * (min(min(r[i], r[i + 1]), r[i - 1]) - max(max(l[i], l[i + 1]), l[i - 1])) * inv(1LL * (1LL * (r[i] - l[i]) * (r[i + 1] - l[i + 1]) % MOD) * (r[i - 1] - l[i - 1]) % MOD);
            cur = max(0LL, cur) % MOD;
            add(ans, 2 * (1 + cur) % MOD);
            sub(ans, 2LL * (E[i] + E[i - 1]) % MOD);
        }
    }

    add(ans, (1 + 2 * sumI) % MOD);
    cout << ans;

    //cin.close();
    //cout.close();
    return 0;
}
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
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    vector <int> lin(n + 1), col(m + 1);
    int mn = 1e9, mx = 0;

    for(i = 1; i <= n; i++) {
        cin >> lin[i]; // mn
        mx = max(mx, lin[i]);
    }
    for(i = 1; i <= m; i++) {
        cin >> col[i]; // mx
        mn = min(mn, col[i]);
    }

    if(mx > mn) {
        cout << -1;
        return 0;
    }

    sort(lin.begin(), lin.end());
    sort(col.begin(), col.end());
    vector <int> fr(n + 1), ok(n + 1);

    ll ans = 0;
    int pos = n;

    for(j = m; j >= 1; j--) {
        while(pos >= 1) {
            if(lin[pos] <= col[j]) {
                //cerr << pos << " " << col[j] << " " << fr[pos] << " " << ok[pos] << "\n";
                if(fr[pos] == m - 1) {
                    ok[pos] |= (lin[pos] == col[j]);
                    if(ok[pos]) {
                        ans += col[j];
                        fr[pos]++;
                        break;
                    }
                }
                else if(fr[pos] < m) {
                    fr[pos]++;
                    ans += col[j];
                    ok[pos] |= (lin[pos] == col[j]);
                    break;
                }
            }
            pos--;
        }
        if(pos == 0) {
            cout << -1;
            return 0;
        }
    }

    for(i = 1; i <= n; i++) {
        ans += 1LL * (m - fr[i]) * lin[i];
        //cerr << m - fr[i] << " " << lin[i] << "\n";
    }

    cout << ans;

    return 0;
}
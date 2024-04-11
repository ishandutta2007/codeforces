#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long

const int MAXN = (int) 3e5;

#if 1
const int MOD = 998244353;

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

#if 1
int fact[MAXN + 1], invfact[MAXN + 1];

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
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    vector <int> a(n), b(n);
    map <int, int> fra, frb;
    for(i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        fra[a[i]]++;
        frb[b[i]]++;
    }
    prec(n);
    int ans = fact[n];

    int cura = 1, curb = 1;
    for(auto it : fra) {
        mul(cura, fact[it.second]);
    }
    for(auto it : frb) {
        mul(curb, fact[it.second]);
    }
    sub(ans, cura);
    sub(ans, curb);

    vector <int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](const int &x, const int &y) {
                return a[x] < a[y];
        });

    int cur = 1, mx = -1;
    i = 0;
    while(i < n) {
        map <int, int> fr;
        int j = i;
        while(j < n && a[ord[i]] == a[ord[j]]) {
            fr[b[ord[j]]]++;
            if(b[ord[j]] < mx) {
                cur = 0;
            }
            j++;
        }
        for(auto it : fr) {
            mul(cur, fact[it.second]);
            mx = max(mx, it.first);
        }
        i = j;
    }
    add(ans, cur);

    cout << ans;

    return 0;
}
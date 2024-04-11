#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 217
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 1e6;

int a[MAXN + 1];

int fact[MAXN + 1], invfact[MAXN + 1];

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1)
            ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline int comb(int n, int k) {
    return (1LL * fact[n] * ((1LL * invfact[k] * invfact[n - k]) % MOD)) % MOD;
}

inline int mod(int x) {
    if(x < 0)
        x += MOD;
    return x;
}

inline int solve(int n, int x) {
    return (1LL * ((1LL * fact[n - x - 1] * comb(n, x + 1)) % MOD) * fact[x]) % MOD;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    fact[0] = invfact[0] = 1;
    for(i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
        invfact[i] = lgput(fact[i], MOD - 2);
    }
    int ans = 0;
    int pos = 1;
    for(i = 1; i <= n; i++) {
        while(pos <= n && a[i] > a[pos]) {
            pos++;
        }
        int x = n - pos;
        if(x > 0 && a[i] != a[n])
            ans = (ans + 1LL * a[i] * solve(n, x)) % MOD;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}
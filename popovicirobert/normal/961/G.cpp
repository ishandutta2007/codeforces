#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 2e5;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

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

int fact[MAXN + 1];
int invfact[MAXN + 1];

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
    return (1LL * fact[n] * ((1LL * invfact[k] * invfact[n - k]) % MOD)) % MOD;
}

inline int Stirling(int n, int k) {
    int ans = 0;
    for(int i = 0; i < k; i++) {
        if(i % 2 == 0) {
            ans = (ans + 1LL * lgput(k - i, n) * comb(k, i)) % MOD;
        }
        else {
            ans -= (1LL * lgput(k - i, n) * comb(k, i)) % MOD;
            if(ans < 0)
                ans += MOD;
        }
    }
    return (1LL * ans * invfact[k]) % MOD;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k, w;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int sum = 0;
    for(i = 1; i <= n; i++) {
        cin >> w;
        sum += w;
        mod(sum);
    }
    prec(n);
    //printf("%d "  ,Stirling(4, 2));
    cout << (1LL * sum * ((Stirling(n, k) + 1LL * (n - 1) * Stirling(n - 1, k)) % MOD)) % MOD;
    //cin.close();
    //cout.close();
    return 0;
}
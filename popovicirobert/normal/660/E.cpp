#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

/////////
// pt s[1],s[2],...,s[len] nr cate secvente de lung n au subsir pe s
// avem grija ca s sa apara prima data ca subsir pe poz fixate ca sa nu dublam solutiile
// fixam len si la ce poz se termina subsirul(pos)
// ans = suma((m - 1) ^ (pos - len) * m ^ (n - pos + len) * comb(pos - 1, len - 1))
// ans = suma((m - 1) ^ x * m ^ (n - x) * comb(x + len - 1, len - 1))
// x = pos - len
/////////

const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 1e6;

int fact[MAXN + 1];
int invfact[MAXN + 1];

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

inline void prec(int n) {
    fact[0] = 1;
    for(int i  =1; i <= n; i++) {
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


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    if(m == 1) {
        cout << n + 1;
        return 0;
    }
    prec(n);
    int inv = lgput(m - 1, MOD - 2), pw1 = m, pw2 = lgput(m - 1, n - 1);
    int ans = lgput(m, n);
    for(int x = 1; x <= n; x++) {
        int cur = (1LL * pw1 * pw2) % MOD;
        cur = (1LL * cur * comb(n, x - 1)) % MOD;
        ans += cur;
        mod(ans);
        pw1 = (1LL * pw1 * m) % MOD;
        pw2 = (1LL * pw2 * inv) % MOD;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}
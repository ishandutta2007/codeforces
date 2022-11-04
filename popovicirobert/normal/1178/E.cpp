#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


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

const int MAXN = (int) 1e6;

char str[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> str + 1;
    n = strlen(str + 1);

    for(i = 1; i <= n; i++) {
        str[i] -= 'a';
    }

    int l = 1, r = n;
    string a;

    while(r - l + 1 >= 4) {
        vector <int> fr(3);
        fr[str[l]]++, fr[str[l + 1]]++, fr[str[r - 1]]++, fr[str[r]]++;

        for(int ch = 0; ch < 3; ch++) {
            if(fr[ch] >= 2) {
                a.push_back(ch + 'a');
                break;
            }
        }

        l += 2, r -= 2;
    }

    cout << a;
    if(l <= r) {
        cout << (char) (str[l] + 'a');
    }
    reverse(a.begin(), a.end());
    cout << a;

    return 0;
}
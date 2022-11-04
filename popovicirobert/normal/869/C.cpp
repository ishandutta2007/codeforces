#include <bits/stdc++.h>
#define ll long long


using namespace std;

const int MAXN = 5000;
const int MOD = 998244353;

int fact[MAXN + 1];

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1)
            ans = (1LL * ans * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

inline int comb(int n, int k) {
    return (1LL * fact[n] * lgput((1LL * fact[k] * fact[n - k]) % MOD, MOD - 2)) % MOD;
}

inline int solve(int a, int b, int i) {
    return (1LL * ((1LL * comb(a, i) * comb(b, i)) % MOD) * fact[i]) % MOD;
}


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, a, b, c;
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    fact[0] = 1;
    for(i = 1; i <= MAXN; i++)
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    int ans1 = 0, ans2 = 0, ans3 = 0;
    for(i = 0; i <= MAXN; i++) {
        if(min(a, b) >= i)
            ans1 = (ans1 + solve(a, b, i)) % MOD;
        if(min(b, c) >= i)
            ans2 = (ans2 + solve(b, c, i)) % MOD;
        if(min(a, c) >= i)
            ans3 = (ans3 + solve(a, c, i)) % MOD;
    }
    cout << (1LL * ((1LL * ans1 * ans2) % MOD) * ans3) % MOD;
    //cin.close();
    //cout.close();
    return 0;
}
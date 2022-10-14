#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 998244353;

string S;
int memo[2005][2005];
int pref[2005];

int binpow(int n, int x) {
    if (x == 0) {
        return 1;
    }
    int res = binpow(n, x / 2);
    res = (1ll * res * res) % MOD;
    if (x & 1) res = (1ll * res * n) % MOD;
    return res;
}

int dp(int l, int r) {
    if (l >= r) {
        return 0;
    }
    if (memo[l][r] != -1) {
        return memo[l][r];
    }
    int res = 0;
    if (S[l] != '(') {
        res += dp(l + 1, r);
        res %= MOD;
    }
    if (S[r] != ')') {
        res += dp(l, r - 1);
        res %= MOD;
    }
    if (S[l] != '(' && S[r] != ')') {
        res -= dp(l + 1, r - 1);
        res %= MOD;
    }
    if (S[l] != ')' && S[r] != '(') {
        res += (1ll * dp(l + 1, r - 1) + binpow(2, pref[r - 1] - pref[l])) % MOD;
        res %= MOD;
    }
    if (res < 0) res += MOD;
    return memo[l][r] = res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    memset(memo, -1, sizeof(memo));

    cin >> S;
    
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '?') {
            pref[i] = 1;
        }
        if (i > 0) {
            pref[i] += pref[i - 1];
        }
    }

    cout << dp(0, S.size() - 1) << "\n";
    return 0;
}
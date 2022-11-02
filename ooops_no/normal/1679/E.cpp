#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int MOD = 998244353;

int add(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

int mul(int a, int b) {
    return (1ll * a * b % MOD);
}

int binpow(int a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        int g = binpow(a, n / 2);
        return mul(g, g);
    } else {
        return mul(a, binpow(a, n - 1));
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sum = 0;
    for (auto to : s) {
        sum += (to == '?');
    }
    vector<vector<int>> dp(18, vector<int>(1 << 17));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            int l = i, r = i, cnt = 0, mask = 0, dif = sum;
            if (j == 1) r = i + 1;
            while (l >= 0 && r < n) {
                if (s[l] == s[r]) {
                    if (s[l] == '?') {
                        cnt++;
                        if (l == r) dif--;
                        else dif -= 2;
                    }
                } else {
                    dif--;
                    if (s[l] == '?') {
                        mask |= (1 << (s[r] - 'a'));
                    } else if (s[r] == '?') {
                        mask |= (1 << (s[l] - 'a'));
                    } else {
                        break;
                    }
                }
                for (int j = 1; j <= 17; j++) {
                    dp[j][mask] = add(dp[j][mask], mul(binpow(j, dif), binpow(j, cnt)));
                }
                l--, r++;
            }
        }
    }
    for (int i = 1; i <= 17; i++) {
        for (int j = 0; j < 17; j++) {
            for (int mask = 0; mask < (1 << 17); mask++) {
                if (mask & (1 << j)) {
                    dp[i][mask] = add(dp[i][mask], dp[i][mask ^ (1 << j)]);
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        int mask = 0, sz = t.size();
        for (int i = 0; i < sz; i++) {
            mask |= (1 << (t[i] - 'a'));
        }
        cout << dp[sz][mask] << endl;
    }
    return 0;
}
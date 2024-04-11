#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

inline int add(int u, int v) {
    return (u += v) >= MOD ? u - MOD : u;
}

inline int sub(int u, int v) {
    return (u -= v) < 0 ? u + MOD : u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = mul(res, u);
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

inline int inv(int u) {
    return power(u, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int l = 0;
    while (l < s.size() && s[l] == '0') l++;
    if (l == s.size()) {
        cout << s.size() << '\n';
        return 0;
    }
    int r = s.size() - 1;
    while (s[r] == '0') r--;
    int mulRes = mul(l + 1, s.size() - r);
    vector<int> dp(s.size() + 1, 0);
    int sum = 0;
    vector<int> ls;
    int curZero = 0;
    for (int i = l + 1; i <= r; i++) {
        if (s[i] == '0') curZero++;
        else {
            ls.push_back(curZero);
            curZero = 0;
        }
    }
    for (int u : ls) {
        int lastSum = add(sum, 1);
        for (int i = 0; i <= u; i++) {
            sum = sub(sum, dp[i]);
            sum = add(sum, lastSum);
            dp[i] = lastSum;
        }
    }
    cout << mul(mulRes, add(sum, 1)) << '\n';
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int MOD = (int)1e9 + 7;
const int N = 5010;

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

int div(vector<int> &a, int p) {
    vector<int> b;
    long long r = 0;
    for (int u : a) {
        r = r * 10 + u;
        int now = r / p;
        if (now || !b.empty()) b.push_back(now);
        r %= p;
    }
    a.swap(b);
    return r;
}

int dp[2][N][2][2];

const int INV2 = inv(2);

int getSmaller(int l, int r) {
    int foo = add(l, r);
    foo = mul(foo, (r - l + 1) % MOD);
    foo = mul(foo, INV2);
    return foo;
}

int p;

int getBigger(int l, int r) {
    if (l > r) return 0;    
    int foo = (r - l + 1) % MOD;
    foo = mul(foo, p - 1);
    foo = sub(foo, getSmaller(l, r));
    return foo;
}   

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int alpha;
    cin >> p >> alpha;
    string s;
    cin >> s;
    vector<int> a(s.size());
    for (int i = 0; i < s.size(); i++) {
        a[i] = s[i] - '0';
    }
    vector<int> r;
    while (!a.empty()) {
        r.push_back(div(a, p));
    }
    r.push_back(0);
    reverse(r.begin(), r.end());
    if (alpha > r.size()) {
        cout << 0 << endl;
        return 0;
    }
    int n = r.size();
    dp[0][0][1][0] = 1;
    int cur = 0;
    for (int i = 0; i < n - 1; i++, cur ^= 1) {
        memset(dp[cur ^ 1], 0, sizeof dp[cur ^ 1]);
        for (int j = 0; j <= alpha; j++) {
            for (int eq = 0; eq < 2; eq++) {
                for (int carry = 0; carry < 2; carry++) {
                    if (!dp[cur][j][eq][carry]) continue;

                    for (int newEq = 0; newEq < 2; newEq++) {
                        if (eq == 0 && newEq == 1) continue;
                        for (int newCarry = 0; newCarry < 2; newCarry++) {
                            int low = 0, high = p - 1;
                            if (newEq) {
                                low = high = r[i + 1];
                            } else {
                                if (eq) {
                                    high = r[i + 1] - 1;
                                }
                            }
                            int foo = carry ? getBigger(low, high) : getSmaller(low, high);
                            if (carry == newCarry) foo = add(foo, (high - low + 1) % MOD);
                            int newJ = min(j + newCarry, alpha);
                            dp[cur ^ 1][newJ][newEq][newCarry] = add(dp[cur ^ 1][newJ][newEq][newCarry], mul(dp[cur][j][eq][carry], foo));
                        }
                    }
                }
            }
        }
    }
    int res = add(dp[cur][alpha][0][0], dp[cur][alpha][1][0]);
    cout << res << endl;
    return 0;
}
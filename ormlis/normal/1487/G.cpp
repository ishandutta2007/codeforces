#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < (n); ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

const ll INF = 1e18;

using namespace std;
const int md = 998244353;
const int INFi = 2e9;
const int maxN = 500;

int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}


int rev(int a) {
    return binpow(a, md - 2);
}

int fact[maxN];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxN; ++i) fact[i] = mul(fact[i - 1], i);
}

int C(int n, int k) {
    if (k > n || k < 0) return 0;
    return mul(fact[n], rev(mul(fact[k], fact[n - k])));
}

int c[26];

void solve() {
    int n;
    cin >> n;
    range(i, 26) cin >> c[i];
    int answer = mul(26 * 26, binpow(25, n - 2));
    int k = n / 2;
    {
        vector<ar<int, 2>> dp(n + 1, {0, 0});
        dp[0][0] = 25;
        dp[1][1] = 1;
        range(_, k - 1) {
            vector<ar<int, 2>> newdp(n + 1, {0, 0});
            range(i, n + 1) {
                if (i != n) {
                    newdp[i + 1][1] = dp[i][0];
                }
                newdp[i][0] = add(mul(24, dp[i][0]), mul(25, dp[i][1]));
            }
            swap(dp, newdp);
        }
        range(i, n + 1) {
            dp[i][0] = add(dp[i][0], dp[i][1]);
            dp[i][1] = 0;
        }
        {
            vector<ar<int, 2>> newdp(n + 1, {0, 0});
            range(i, n + 1) {
                if (i != n) {
                    newdp[i + 1][1] = dp[i][0];
                }
                newdp[i][0] = mul(25, dp[i][0]);
            }
            swap(dp, newdp);
        }
        range(_, n - k - 1) {
            vector<ar<int, 2>> newdp(n + 1, {0, 0});
            range(i, n + 1) {
                if (i != n) {
                    newdp[i + 1][1] = dp[i][0];
                }
                newdp[i][0] = add(mul(24, dp[i][0]), mul(25, dp[i][1]));
            }
            swap(dp, newdp);
        }
        range(i, n + 1) {
            dp[i][0] = add(dp[i][0], dp[i][1]);
            dp[i][1] = 0;
        }
        for (int ci = 0; ci < 26; ++ci) {
            for (int cnt = c[ci] + 1; cnt <= n; ++cnt) {
                answer = sub(answer, dp[cnt][0]);
            }
        }
    }
    {
        vector<vector<ar<int, 3>>> dp(n + 1, vector<ar<int, 3>>(n + 1, {0, 0, 0}));
        dp[0][0][0] = 24;
        dp[0][1][2] = 1;
        dp[1][0][1] = 1;
        range(_, k - 1) {
            vector<vector<ar<int, 3>>> newdp(n + 1, vector<ar<int, 3>>(n + 1, {0, 0, 0}));
            range(i, n + 1) {
                range(j, n + 1) {
                    if (i != n) {
                        newdp[i + 1][j][1] = add(dp[i][j][0], dp[i][j][2]);
                    }
                    if (j != n) {
                        newdp[i][j + 1][2] = add(dp[i][j][0], dp[i][j][1]);
                    }
                    newdp[i][j][0] = add(mul(23, dp[i][j][0]),
                                         mul(24, add(dp[i][j][1], dp[i][j][2])));
                }
            }
            swap(dp, newdp);
        }
        range(i, n + 1) {
            range(j, n + 1) {
                dp[i][j][0] = add(dp[i][j][0], add(dp[i][j][1], dp[i][j][2]));
                dp[i][j][1] = dp[i][j][2] = 0;
            }
        }
        {

            vector<vector<ar<int, 3>>> newdp(n + 1, vector<ar<int, 3>>(n + 1, {0, 0, 0}));
            range(i, n + 1) {
                range(j, n + 1) {
                    if (i != n) {
                        newdp[i + 1][j][1] = add(dp[i][j][0], dp[i][j][2]);
                    }
                    if (j != n) {
                        newdp[i][j + 1][2] = add(dp[i][j][0], dp[i][j][1]);
                    }
                    newdp[i][j][0] = mul(24, dp[i][j][0]);
                }
            }
            swap(dp, newdp);
        }
        range(_, n - k - 1) {
            vector<vector<ar<int, 3>>> newdp(n + 1, vector<ar<int, 3>>(n + 1, {0, 0, 0}));
            range(i, n + 1) {
                range(j, n + 1) {
                    if (i != n) {
                        newdp[i + 1][j][1] = add(dp[i][j][0], dp[i][j][2]);
                    }
                    if (j != n) {
                        newdp[i][j + 1][2] = add(dp[i][j][0], dp[i][j][1]);
                    }
                    newdp[i][j][0] = add(mul(23, dp[i][j][0]),
                                         mul(24, add(dp[i][j][1], dp[i][j][2])));
                }
            }
            swap(dp, newdp);
        }
        range(i, n + 1) {
            range(j, n + 1) {
                dp[i][j][0] = add(dp[i][j][0], add(dp[i][j][1], dp[i][j][2]));
                dp[i][j][1] = dp[i][j][2] = 0;
            }
        }
        for (int ci = 0; ci < 26; ++ci) {
            for (int cj = ci + 1; cj < 26; ++cj) {
                for (int cnt1 = c[ci] + 1; cnt1 <= n; ++cnt1) {
                    for (int cnt2 = c[cj] + 1; cnt2 <= n; ++cnt2) {
                        answer = add(answer, dp[cnt1][cnt2][0]);
                    }
                }
            }
        }
    }
    cout << answer;
}

int main() {
    init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
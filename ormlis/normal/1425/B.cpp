#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define range(i, n) for(int i = 0; i < n; ++i)
#define ar array

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int maxN = 2e3 + 1;
const int md = 1e9 + 7;

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

const int maxF = 1e6 + 1;
int fact[maxF], invfact[maxF];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxF; ++i) fact[i] = mul(i, fact[i - 1]);
    invfact[maxF - 1] = rev(fact[maxF - 1]);
    for (int i = maxF - 2; i >= 1; --i) invfact[i] = mul(invfact[i + 1], i + 1);
    invfact[0] = 1;
}

int C(int n, int k) {
    if (k < 0) return 0;
    if (k > n) return 0;
    return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

vector<int> g[maxN];
int used[maxN];

int go(int v, int p) {
    if (v == 1) return 1;
    int res = 1;
    used[v] = 1;
    for (auto &u: g[v]) {
        if (u == p) {
            p = -1;
            continue;
        }
        res += go(u, v);
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a;
    range(_, m) {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for (auto &u: g[1]) {
        if (used[u]) continue;
        a.push_back(go(u, 1));
    }
    int w = m;
    n = a.size();
    vector<vector<int>> prefdp(n + 1, vector<int>(w * 2+ 5, 0));
    prefdp[0][w] = 1;
    prefdp[0][a[0] + w] = 1;
    prefdp[0][w - a[0]] = 1;
    for (int i = 1; i < n; ++i) {
        for (int l = 0; l <= 2 * w; ++l) {
            prefdp[i][l] = prefdp[i - 1][l];
            if (l >= a[i]) prefdp[i][l] = add(prefdp[i][l], prefdp[i - 1][l - a[i]]);
            if (l + a[i] <= w * 2) prefdp[i][l] = add(prefdp[i][l], prefdp[i - 1][l + a[i]]);
        }
    }
    vector<vector<int>> sufdp(n + 1, vector<int>(w * 2+ 5, 0));
    sufdp[n - 1][w] = 1;
    sufdp[n - 1][a[n - 1] + w] = 1;
    sufdp[n - 1][w - a[n - 1]] = 1;
    for (int i = n - 2; i >= 0; --i) {
        for (int l = 0; l <= 2 * w; ++l) {
            sufdp[i][l] = sufdp[i + 1][l];
            if (l >= a[i]) sufdp[i][l] = add(sufdp[i][l], sufdp[i + 1][l - a[i]]);
            if (l + a[i] <= 2 * w) sufdp[i][l] = add(sufdp[i][l], sufdp[i + 1][l + a[i]]);
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int l = 0; l <= 2 * w; ++l) {
            //if (l) prefdp[i][l] = add(prefdp[i][l], prefdp[i][l - 1]);
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int l = 0; l <= 2 * w; ++l) {
            //if (l) sufdp[i][l] = add(sufdp[i][l], sufdp[i][l - 1]);
        }
    }
    int ans = 0;
    range(i, n) {
        for (int l1 = 0; l1 <= 2 * w; ++l1) {
            // l2 >= -l1 - a[i] + 2
            // l2 <= -l1 + a[i] - 2
            int high = -(l1-w) + a[i] - 2+w;
            int low = -(l1-w) - a[i] + 2+w;
            low = max(low, 0);
            high = min(high, 2 * w);
            for (int l2 = low; l2 <= high; ++l2) {
                int cnt1 = 0, cnt2 = 0;
                if (l1 == w) cnt1 = 1;
                if (l2 == w) cnt2 = 1;
                if (i) {
                    cnt1 = prefdp[i - 1][l1];
                    //if (l1) cnt1 = sub(cnt1, prefdp[i-1][l1-1]);
                }
                if (i + 1 != n) {
                    cnt2 = sufdp[i+1][l2];
                    //if (l2) cnt2 = sub(cnt2, sufdp[i+1][l2-1]);
                }
                ans = add(ans, mul(2, mul(cnt1, cnt2)));
            }
        }
    }
    sufdp.clear();
    prefdp.clear();
    vector<vector<int>> dp(n + 1, vector<int>(w * 2+ 5, 0));
    dp[0][a[0] + w] = 1;
    dp[0][w - a[0]] = 1;
    for (int i = 1; i < n; ++i) {
        for (int l = 0; l <= 2 * w; ++l) {
            if (l >= a[i]) dp[i][l] = add(dp[i][l], dp[i - 1][l - a[i]]);
            if (l + a[i] <= w * 2) dp[i][l] = add(dp[i][l], dp[i - 1][l + a[i]]);
        }
    }
    ans = add(ans, dp[n-1][w]);
    dp.clear();

    vector<vector<int>> prefdp2(n + 1, vector<int>(w * 2+ 5, 0));
    prefdp2[0][a[0] + w] = 1;
    prefdp2[0][w - a[0]] = 1;
    for (int i = 1; i < n; ++i) {
        for (int l = 0; l <= 2 * w; ++l) {
            if (l >= a[i]) prefdp2[i][l] = add(prefdp2[i][l], prefdp2[i - 1][l - a[i]]);
            if (l + a[i] <= w * 2) prefdp2[i][l] = add(prefdp2[i][l], prefdp2[i - 1][l + a[i]]);
        }
    }
    vector<vector<int>> sufdp2(n + 1, vector<int>(w * 2+ 5, 0));
    sufdp2[n - 1][a[n - 1] + w] = 1;
    sufdp2[n - 1][w - a[n - 1]] = 1;
    for (int i = n - 2; i >= 0; --i) {
        for (int l = 0; l <= 2 * w; ++l) {
            if (l >= a[i]) sufdp2[i][l] = add(sufdp2[i][l], sufdp2[i + 1][l - a[i]]);
            if (l + a[i] <= 2 * w) sufdp2[i][l] = add(sufdp2[i][l], sufdp2[i + 1][l + a[i]]);
        }
    }
    range(i, n) {
        for (int l1 = 0; l1 <= 2 * w; ++l1) {
            // l2 >= -l1 - a[i] + 2
            // l2 <= -l1 + a[i] - 2
            int high = -(l1-w) + a[i] - 1+w;
            int low = -(l1-w) - a[i] + 1+w;
            //low = max(low, 0);
            //high = min(high, 2 * w);
            int l2 = low;
            for (int it = 0; it < 2; ++it) {
                if (l2 >= 0 && l2 <= 2 * w) {
                    int cnt1 = 0, cnt2 = 0;
                    if (l1 == w) cnt1 = 1;
                    if (l2 == w) cnt2 = 1;
                    if (i) {
                        cnt1 = prefdp2[i - 1][l1];
                        //if (l1) cnt1 = sub(cnt1, prefdp[i-1][l1-1]);
                    }
                    if (i + 1 != n) {
                        cnt2 = sufdp2[i + 1][l2];
                        //if (l2) cnt2 = sub(cnt2, sufdp[i+1][l2-1]);
                    }
                    ans = add(ans, mul(2, mul(cnt1, cnt2)));
                }
                l2 = high;
            }
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
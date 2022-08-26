#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>
#include <cassert>
#include <iomanip>
#include <list>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 2e18 + 5;
const int INFi = 1e8;
const int maxN = 3e5 + 100;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

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

void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n);
    range(i, n) cin >> a[i];
    int res = 0;
    vector<int> st2(n * m + 5);
    st2[0] = 1;
    for(int i = 1; i < st2.size(); ++i) st2[i] = mul(st2[i - 1], 2);
    int cnt = 0;
    range(i, n) range(j, m) if (a[i][j] == 'o') cnt++;
    vector<int> dp(st2.size(), 0);
    for(int i = 1; i < dp.size(); ++i) {
        if (cnt - i * 2 - 1 < 0) break;
        dp[i] = add(dp[i - 1], st2[cnt - i * 2 - 1]);
    }
    range(j, m) {
        int len = 0;
        range(i, n) {
            if (a[i][j] == '*') {
                len = 0;
                continue;
            }
            len++;
            if (len == 1) continue;
            res = add(res, dp[(len-1)/2]);
            if (len % 2 == 0) {
                res = add(res, st2[cnt-len]);
            }
        }
    }
    range(i, n) {
        int len = 0;
        range(j, m) {
            if (a[i][j] == '*') {
                len = 0;
                continue;
            }
            len++;
            if (len == 1) continue;
            res = add(res, dp[(len-1)/2]);
            if (len % 2 == 0) {
                res = add(res, st2[cnt-len]);
            }
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
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
const int md2 = 998244353;
const int md = 1e9 + 7;

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
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    sort(all(a));
    ll sum = accumulate(all(a), 0ll);
    if (sum % n) {
        cout << "0\n";
        return;
    }
    ll need = sum / n;
    int small = 0;
    int big = 0;
    range(i, n) {
        if (a[i] < need) small++;
        if (a[i] > need) big++;
    }
    vector<int> fact(n + 1);
    fact[0] = 1;
    for(int i = 1; i <= n; ++i) fact[i] = mul(fact[i - 1], i);
    map<int, int> cnt;
    for(auto &x : a) cnt[x]++;
    int t = 1;
    for(auto &[x, c] : cnt) {
        t = mul(t, fact[c]);
    }
    if (small > 1 && big > 1) {
        int res = 2;
        res = mul(res, fact[big]);
        res = mul(res, fact[small]);
        for(int i = big + small + 1; i <= n; ++i) res = mul(res, i);
        res = mul(res, rev(t));
        cout << res << '\n';
        return;
    }
    int result = fact[n];
    result = mul(result, rev(t));
    cout << result << '\n';
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
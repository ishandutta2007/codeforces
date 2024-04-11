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
// #include <ext/pb_ds/assoc_container.hpp>

// using namespace __gnu_pbds;

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
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

int fact[maxN];

int rev(int a) {
    return binpow(a, md - 2);
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxN; ++i) fact[i] = mul(fact[i - 1], i);
}

int C(int n, int k) {
    if (k > n || k < 0) return 0;
    return mul(fact[n], rev(mul(fact[k], fact[n - k])));
}

void solve() {
    init();
    int n, x, pos;
    cin >> n >> x >> pos;
    int left = 0, right = n;
    int cnt_big = 0, cnt_low = 0;
    while (left < right) {
        int mid = (left + right) / 2;
        if (mid <= pos) {
            cnt_low++;
            left = mid + 1;
        } else {
            cnt_big++;
            right = mid;
        }
    }
    int ans = mul(C(n - x, cnt_big), C(x - 1, cnt_low - 1));
    ans = mul(ans, fact[n - cnt_big - cnt_low]);
    ans = mul(ans, fact[cnt_big]);
    ans = mul(ans, fact[cnt_low - 1]);
    cout << ans << "\n";
}

int main() {
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
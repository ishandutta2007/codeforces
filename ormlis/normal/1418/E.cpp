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

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

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

int fact[maxN];
void init() {
    fact[0] = 1;
    for(int i = 1; i < maxN; ++i) fact[i] = mul(fact[i-1], i);
}

int binpow(int a, int b) {
    if ( b <= 0) return 1;
    if (b % 2 ) return mul(binpow(a, b - 1), a);
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int rev(int a) {
    return binpow(a, md - 2);
}

void solve() {
    init();
    int n, m;
    cin >> n >> m;
    vector<int> d(n);
    range(i, n) cin >> d[i];
    sort(all(d));
    vector<int> suf(n), pref(n);
    suf[n - 1] = d[n - 1] % md;
    pref[0] = d[0] % md;
    for (int i = n - 2; i >= 0; --i) suf[i] = add(suf[i + 1], d[i] % md);
    for(int i = 1; i < n; ++i) pref[i] = add(pref[i-1], d[i] % md);
    range(i, m) {
        int a, b;
        cin >> a >> b;
        int j = lower_bound(all(d), b) - d.begin();
        if (n - j < a) {
            cout << 0 << "\n";
            continue;
        }
        int ans = 0;
        if (n - j > a) {
            ans = mul(fact[n - j - 1], n - j - a);
            ans = mul(ans, suf[j]);
            ans = mul(ans, mul(fact[n], rev(fact[n - j])));
        }
        if (j) {
            int ans2 = mul(fact[n - j], n - j - a + 1);
            ans2 = mul(ans2, mul(fact[n], rev(fact[n - j + 1])));
            ans2 = mul(ans2, pref[j - 1]);
            ans = add(ans, ans2);
        }
        cout << mul(ans, rev(fact[n])) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 4e5 + 5;
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

int bp(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, bp(a, b - 1));
    int m = bp(a, b / 2);
    return mul(m, m);
}

int rev(int a) {
    return bp(a, md - 2);
}

int fact[maxN], invfact[maxN];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxN; ++i) fact[i] = mul(fact[i - 1], i);
    invfact[maxN - 1] = rev(fact[maxN - 1]);
    for (int i = maxN - 2; i >= 0; --i) invfact[i] = mul(invfact[i + 1], i + 1);
}

int C(int n, int k) {
    if (k > n || k < 0) return 0;
    return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

void solve() {
    init();
    int n;
    cin >> n;
    vector<int> a(n * 2);
    range(i, n * 2) {
        cin >> a[i];
    }
    sort(all(a));
    int ans = 0;
    range(i, n) ans = sub(ans, a[i] % md);
    range(i, n) ans = add(ans, a[i + n] % md);
    cout << mul(ans, C(2 * n, n)) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
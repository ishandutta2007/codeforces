#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

// using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 2e9;
const int maxN = 2e6 + 1000;
const int md2 = 998244353;
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

int fact[maxN];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxN; ++i) fact[i] = mul(fact[i - 1], i);
}

int C(int n, int k) {
    if (k > n || k < 0) return 0;
    return mul(fact[n], rev(mul(fact[k], fact[n - k])));
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<int> c(n);
    range(i, n) c[a[i]-1]++;
    for(int i = n - 1; i >= 0; --i) {
        if (k <= c[i]) {
            cout << C(c[i], k) << '\n';
            return;
        }
        k -= c[i];
    }
}

int main() {
    init();
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
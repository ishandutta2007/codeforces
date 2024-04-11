#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int fact[maxN];

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int mid = binpow(a, b / 2);
    return mul(mid, mid);
}

int rev(int a) {
    return binpow(a, md - 2);
}

int C(int n, int k) {
    return mul(fact[n], mul(rev(fact[k]), rev(fact[n - k])));
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxN; ++i) fact[i] = mul(fact[i - 1], i);
}

void solve() {
    init();
    ll n, k;
    cin >> n >> k;
    auto S = [] (ll n, ll k) {
        if (k > n) return 0;
        int res = 0;
        range(j, k + 1) {
            if ((k + j) & 1) {
                res = sub(res, mul(C(k, j), binpow(j, n)));
            } else {
                res = add(res, mul(C(k, j), binpow(j, n)));
            }
        }
        return mul(res, rev(fact[k]));
    };
    if (k < n) {
        if (k == 0) {
            cout << fact[n];
        } else {
            cout << mul(fact[n-k], mul(C(n, k), mul(S(n, n - k), 2)));
        }
    } else {
        cout << 0;
    }
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
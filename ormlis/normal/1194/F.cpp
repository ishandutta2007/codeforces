#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int P = 998244353;
const int md = 1e9 + 7;

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

int binpow(int a, int b) {
    if (b == 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int mid = binpow(a, b / 2);
    return mul(mid, mid);
}

int rev(int a) {
    return binpow(a, md - 2);
}

int fact[maxN];

int C(int n, int k) {
    return mul(fact[n], mul(rev(fact[k]), rev(fact[n - k])));
}

void solve() {
    fact[0] = 1;
    for (int i = 1; i < maxN; ++i) fact[i] = mul(fact[i - 1], i);
    int n;
    ll T;
    cin >> n >> T;
    vector<ll> t(n);
    range(i, n) cin >> t[i];
    for (int i = 1; i < n; ++i) t[i] += t[i - 1];
    int p = 0;
    int j = 0;
    for (int i = n - 1; i >= 0; --i) {
        int c = i + 1;
        j = max(0, min(j, c));
        ll time = t[i] + j;
        while (time <= T && j <= c) {
            if (c == n || t[c] + j > T) {
                int k = mul(C(c, j), binpow(2, n-c));
                p = add(p, mul(c, k));
            } else if (t[c] + j + 1 > T) {
                int k = mul(C(c, j), binpow(2, n - c - 1));
                p = add(p, mul(c, k));
            }
            j++;
            time++;
        }
        j--;
    }
    cout << mul(p, rev(binpow(2, n)));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}
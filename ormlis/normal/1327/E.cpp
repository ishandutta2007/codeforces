#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef unsigned long long ll;

using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int P = 998244353;
const int md = 998244353;

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

void solve() {
    int n;
    cin >> n;
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = mul(fact[i - 1], i);
    for (int i = 1; i <= n; ++i) {
        int c = max(0, n - i - 1);
        int ans = mul(mul(mul(c, 10), binpow(9, 2)), binpow(10, n - i - 2));
        if (i != n) {
            ans = add(ans, mul(180, binpow(10, n - i - 1)));
        } else {
            ans = add(ans, mul(10, binpow(10, n - i - 1)));
        }
        cout << ans << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests=1;
    range(_, tests) {
        solve();
    }
    return 0;
}
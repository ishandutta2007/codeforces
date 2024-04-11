#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll INF = 2e18;
const int INFi = 2e9;

const int md = 998244353; //1e9 + 7, 1e9 + 9

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
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

const int maxN = 4e5 + 5;
int fact[maxN];
int rfact[maxN];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxN; ++i) fact[i] = mul(fact[i - 1], i);
    rfact[maxN - 1] = rev(fact[maxN - 1]);
    for (int i = maxN - 1; i >= 1; --i) {
        rfact[i - 1] = mul(rfact[i], i);
    }
}

int C(int n, int k) {
    if (k < 0 || n < k) return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

int T(int n, int k) {
    return C(n + k - 1, k - 1);
}

void solve() {
    init();
    int n, k; cin >> n >> k;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<int> p(n + 1, -1);
    range(i, n) p[a[i]] = i;
    int cnt = 1;
    range(i, n - 1) {
        if (p[a[i] + 1] > p[a[i + 1] + 1]) cnt++;
    }
    if (cnt > k) {
        cout << "0\n";
        return;
    }
    cout << T(k - cnt, n + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
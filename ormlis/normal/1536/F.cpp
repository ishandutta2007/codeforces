#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;

using namespace std;
//using namespace __gnu_pbds;

const int INFi = 2e9 + 5;
const int maxN = 2e6 + 100;
const ll INF = 2e18;
const int md = 1e9 + 7; //, 1e9 + 9;

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
    int n;
    cin >> n;
    int ans = 0;
    if (n % 2 == 0) ans = fact[n];
    for (int segs = 1; segs <= n; ++segs) {
        int ciles = n - segs;
        if (ciles < segs || ciles % 2 != 0) continue;
        int ost = ciles - segs;
        int cnt = T(ost, segs);
        int cur = T(ost - 1, segs + 1);
        cur = add(cur, mul(cnt, 2));
        cur = mul(cur, fact[ciles]);
        ans = add(ans, cur);
    }
    cout << mul(ans, 2) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
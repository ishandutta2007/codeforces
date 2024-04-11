#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 501;
const int md = 998244353;
const ll INF = 2e18;

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

int fact[maxN];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxN; ++i) fact[i] = mul(fact[i - 1], i);
}

int C(int n, int k) {
    if (k > n || k < 0) return 0;
    return mul(fact[n], rev(mul(fact[k], fact[n - k])));
}

int check(int n, vector<int> a, ll mn) {
    // p[0] = 'C':
    ll ans = 0;
    vector<ll> suf(n);
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) suf[i] = suf[i + 1] + a[i];
    for(int i = n - 1; i >= 1; --i) {
        if (suf[i] >= mn) ans++;
    }
    vector<ll> s2(n);
    s2[n - 1] = a[n - 1];
    s2[n - 2] = a[n - 2];
    for (int i = n - 3; i >= 0; --i) s2[i] = s2[i + 2] + a[i];
    vector<ll> p2(n);
    p2[0] = a[0];
    p2[1] = a[1];
    for (int i = 2; i < n; ++i) p2[i] = p2[i - 2] + a[i];
    int j = 1;
    for (int pp = 3; pp <= n - 2; pp += 2) {
        ll cur = suf[pp];
        while(j < pp - 2 && cur + s2[j] - s2[pp] >= mn) j += 2;
        while(j >= 3 && cur + s2[j] - s2[pp] < mn) j -= 2;
        if (cur + s2[j] - s2[pp] >= mn) {
            ans += (j + 1) / 2;
        }
    }
    j = 1;
    for (int pp = 1; pp <= n - 3; pp += 2) {
        ll cur = suf[pp] - a[n - 1];
        while(j < pp && cur + s2[j] - s2[pp] >= mn) j += 2;
        while(j >= 3 && cur + s2[j] - s2[pp] < mn) j -= 2;
        if (cur + s2[j] - s2[pp] >= mn) {
            ans += (j + 1) / 2;
        }
    }
    j = 2;
    for (int pp = 4; pp <= n - 2; pp += 2) {
        ll cur = suf[pp];
        while(j < pp - 2 && cur + s2[j] - s2[pp] >= mn) j += 2;
        while(j >= 4 && cur + s2[j] - s2[pp] < mn) j -= 2;
        if (cur + s2[j] - s2[pp] >= mn) {
            ans += j / 2;
        }
    }
    j = 2;
    for (int pp = 2; pp <= n - 3; pp += 2) {
        ll cur = suf[pp] - a[n - 1];
        while(j < pp && cur + s2[j] - s2[pp] >= mn) j += 2;
        while(j >= 4 && cur + s2[j] - s2[pp] < mn) j -= 2;
        if (cur + s2[j] - s2[pp] >= mn) {
            ans += j / 2;
        }
    }
    for(int i = n - 2; i >= 1; --i) {
        if (s2[i] >= mn) {
            ans++;
        }
    }
    return ans % md;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    if (n == 1) {
        cout << "1\n";
        return;
    }
    if (n == 2) {
        int res = 1;
        if (a[0] != a[1]) res++;
        cout << res << '\n';
        return;
    }
    ll sum = accumulate(all(a), 0ll);
    ll mn = sum / 2 + 1;
    int ans = check(n, a, mn);
    {
        ll cur = 0;
        range(i, n) {
            cur += a[i];
            if (cur >= mn) ans++;
        }
    }
    ans %= md;
    vector<int> b(n - 1);
    range(i, n - 1) b[i] = a[i + 1];
    ans = add(ans, check(n - 1, b, mn - a[0]));
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
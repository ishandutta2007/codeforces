#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

//using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 1e9;
const int maxN = 20;
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

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    range(i, n) cin >> a[i];
    vector<int> cnt(60);
    range(i, n) {
        range(j, 60) {
            if ((1ll << j) & a[i]) cnt[j]++;
        }
    }
    ll ans = 0;
    range(j, n) {
        int c = 0;
        range(b1, 60) {
            if (!((1ll << b1) & a[j])) continue;
            c = add(c, mul((1ll << b1) % md, cnt[b1]));
        }
        range(b2, 60) {
            int c2;
            if ((1ll << b2) & a[j]) {
                c2 = n;
            } else {
                c2 = cnt[b2];
            }
            ans = add(ans, mul(mul((1ll << b2) % md, c2), c));
        }
    }
    cout << ans << '\n';
}

int main() {
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
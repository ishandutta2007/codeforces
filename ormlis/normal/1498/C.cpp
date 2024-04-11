#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e5;
const int md = 1e9 + 7;

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
void solve() {
    int n, k; cin >> n >> k;
    vector<int> from(n + 1);
    from[0] = 1;
    int ans = 1;
    for(int i = 1; i < k; ++i) {
        vector<int> from2(n + 1);
        if (i & 1) {
            int s = 0;
            range(j, n + 1) {
                from2[j] = s;
                s = add(s, from[j]);
            }
        } else {
            int s = 0;
            for(int j = n; j >= 1; --j) {
                from2[j] = s;
                s = add(s, from[j]);
            }
        }
        swap(from, from2);
        range(j, n + 1) ans = add(ans, from[j]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    // cout << setprecision(15) << fixed;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
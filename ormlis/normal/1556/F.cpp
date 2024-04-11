#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

using namespace __gnu_pbds;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 5e5 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


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
    int n;
    cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<vector<int>> win(n, vector<int>(n));
    range(i, n) range(j, n) win[i][j] = mul(a[i], rev(add(a[i], a[j])));
    vector<int> f(1 << n);
    int ans = 0;
    range(mask, 1 << n) {
        f[mask] = 1;
        range(i, n) {
            if ((1 << i) & mask) {
                range(j, n) {
                    if ((1 << j) & mask) continue;
                    f[mask] = mul(f[mask], win[i][j]);
                }
            }
        }
        for (int submask = (mask - 1) & mask; submask > 0; submask = (submask - 1) & mask) {
            int res = f[submask];
            int mask1 = mask ^submask;
            int mask2 = ((1 << n) - 1) ^mask;
            range(i, n) {
                if ((1 << i) & mask1) {
                    range(j, n) {
                        if ((1 << j) & mask2) {
                            res = mul(res, win[i][j]);
                        }
                    }
                }
            }
            f[mask] = sub(f[mask], res);
        }
        ans = add(ans, mul(__builtin_popcount(mask), f[mask]));
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
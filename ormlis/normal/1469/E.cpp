#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
using namespace std;

// using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 1e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    range(i, n) {
        char x;
        cin >> x;
        if (x == '0') a[i] = 1;
    }
    int t = 1;
    while((1 << t) <= n) t++;
    t = min(t, k);
    vector<bool> was(1 << t);
    int R = -1;
    range(i, n - k + 1) {
        R = max(R, i);
        while(R < n && a[R] == 0) R++;
        if (R - i < k - t) continue;
        int mask = 0;
        range(j, t) if (a[-j + (t - 1) + i + (k - t)]) mask |= 1 << j;
        was[mask] = true;
    }
    range(mask, 1 << t) {
        if (!was[mask]) {
            cout << "YES\n";
            range(i, k - t) cout << '0';
            range(i, t) {
                if ((1 << (t - 1 - i)) & mask) cout << '1';
                else cout << '0';
            }
            cout << '\n';
            return;
        }
    }
    cout << "NO\n";
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
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
    int n, k; cin >> n >> k;
    vector<int> h(n);
    range(i, n) cin >> h[i];
    vector<int> order(n);
    iota(all(order), 0);
    sort(all(order), [&] (const int &i, const int &j) {
        return h[i] > h[j];
    });
    vector<int> a(n, -1);
    for(auto &i : order) {
        int need = h[i];
        if (i && a[i - 1] != -1) {
            need = max(need, a[i - 1] - k + 1);
        }
        if (i + 1 != n && a[i + 1] != -1) {
            need = max(need, a[i + 1] - k + 1);
        }
        if (need >= h[i] + k) {
            cout << "No\n";
            return;
        }
        a[i] = need;
    }
    if (a[0] != h[0] || a[n - 1] != h[n - 1]) {
        cout << "NO\n";
        return;
    }
    cout << "Yes\n";
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
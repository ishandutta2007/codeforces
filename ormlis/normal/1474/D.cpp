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
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<ll> pref(n);
    pref[0] = a[0];
    for(int i = 1; i < n; ++i) pref[i] = a[i] - pref[i - 1];
    vector<ll> min_pref(n + 2);
    min_pref[n + 1] = min_pref[n] = INF;
    for(int i = n - 1; i >= 0; --i) {
        min_pref[i] = min(min_pref[i + 2], pref[i]);
    }
    if (pref[n - 1] == 0 && min_pref[0] >= 0 && min_pref[1] >= 0) {
        cout << "YES\n";
        return;
    }
    range(i, n - 1) {
        ll k = a[i + 1] - a[i];
        if (pref[i] + k >= 0 && min_pref[i + 1] - 2 * k >= 0 && min_pref[i + 2] + 2 * k >= 0) {
            if (i % 2 == (n - 1) % 2) {
                if (pref[n - 1] + 2 * k == 0) {
                    cout << "YES\n";
                    return;
                }
            } else {
                if (pref[n - 1] - 2 * k == 0) {
                    cout << "YES\n";
                    return;
                }
            }
        }
        if (pref[i] < 0) break;
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
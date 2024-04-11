#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
using namespace std;

const ll INF = 1e18 + 5;
const int INFi = 1e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    ll s = accumulate(all(a), 0ll);
    for(int l = n; l >= 1; --l) {
        if (s % l) continue;
        ll need = s / l;
        ll cur = 0;
        bool bad = false;
        range(i, n) {
            cur += a[i];
            if (cur > need) {
                bad = true;
                break;
            }
            if (cur == need) cur = 0;
        }
        if (bad) continue;
        cout << n - l << '\n';
        return;
    }
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
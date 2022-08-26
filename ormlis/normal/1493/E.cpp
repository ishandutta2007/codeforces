#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9 + 5;
const int maxN = 2e5 + 1;
const int md = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string l, r; cin >> l >> r;
    if (l == r) {
        cout << l << '\n';
        return;
    }
    if (l[0] == '0') {
        range(i, n) cout << '1';
        cout << '\n';
        return;
    }
    if (r.back() == '1') {
        cout << r << '\n';
        return;
    }
    int j = 0;
    while(l[j] == r[j]) j++;
    bool bad = true;
    for(int i = j + 1; i < n; ++i) {
        if (r[i] == '1') bad = false;
    }
    for(int i = j + 1; i < n; ++i) {
        if (l[i] == '0') bad = false;
    }
    if (!bad) {
        r.back() = '1';
    }
    cout << r << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
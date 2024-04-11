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
const int INFi = 2e9;
const int maxN = 5e5 + 1;
const int md = 1e9 + 7;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> p(n);
    range(i, n) {
        char x; cin >> x;
        p[i] = x - 'a' + 1;
        if (i) p[i] += p[i - 1];
    }
    range(_, q) {
        int l, r; cin >> l >> r;
        r--;
        l--;
        int res = p[r];
        if (l) res -= p[l - 1];
        cout << res << '\n';
    }
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
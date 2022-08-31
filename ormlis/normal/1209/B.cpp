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
const int md = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> o(n), a(n), b(n);
    range(i, n) {
        char x; cin >> x;
        o[i] = x - '0';
    }
    range(i, n) cin >> a[i] >> b[i];
    int ans = accumulate(all(o), 0);
    for(int t = 1; t <= 10500; ++t) {
        range(i, n) {
            if (t >= b[i] && (t - b[i]) % a[i] == 0) o[i] ^= 1;
        }
        ans = max(ans, accumulate(all(o), 0));
    }
    cout << ans << '\n';
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
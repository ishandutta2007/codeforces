#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;

const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 1e9 + 7;
const ll INF = 2e18;


void solve() {
    ll p, a, b, c; cin >> p >> a >> b >> c;
    cout << min({(a - p % a) % a, (b - p % b) % b, (c - p % c) % c}) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
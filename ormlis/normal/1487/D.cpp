#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < (n); ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

const ll INF = 1e18;

using namespace std;
const int md = 1e9 + 7;
const int INFi = 1e8;
const int maxN = 59;

void solve() {
    int n;
    cin >> n;
    ll L = 0, R = n;
    while (R - L > 1) {
        ll mid = (R + L) / 2;
        ll x = 2 * mid + 1;
        ll t = x * x;
        t--;
        t /= 2;
        if (t + 1 <= n) L = mid;
        else R = mid;
    }
    cout << L << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 3e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    ll a1, k;
    cin >> a1 >> k;
    ll prev = 0;
    while (k > 0 && prev != a1) {
        prev = a1;
        int mn = 9, mx = 0;
        while (a1) {
            mn = min(1ll * mn, a1 % 10);
            mx = max(1ll * mx, a1 % 10);
            a1 /= 10;
        }
        a1 = prev + mn * mx;
        k--;
    }
    cout << prev << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1000001;
ll md = 1000000007;

void solve() {
    ll a, b, c, n; cin >> a >> b >> c >> n;
    ll s = a + b + c + n;
    ll s2 = s / 3;
    if (s % 3) {
        cout << "NO\n";
        return;
    }
    if (a > s2 || b > s2 || c > s2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tests; cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
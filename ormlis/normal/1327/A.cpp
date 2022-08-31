#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef unsigned long long ll;

using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int P = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    ll n, k; cin >> n >> k;
    if (n < (k - 1) * k + k  || n % 2 != k % 2) {
        cout << "NO\n";
        return;
    } else {
        cout << "YES\n";
    }
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
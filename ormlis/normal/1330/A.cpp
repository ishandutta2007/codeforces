#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1000;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n + 2);
    range(i, n) cin >> a[i + 1];
    a[n+1] = INFi;
    sort(all(a));
    range(i, n + 1) {
        x -= max(0, a[i + 1] - a[i] - 1);
        if (x < 0) {
            cout << a[i+1] + x - 1 << '\n';
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tests; cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
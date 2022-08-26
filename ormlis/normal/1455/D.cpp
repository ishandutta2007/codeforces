#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

// using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 3e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if (a[i] <= x) continue;
        bool was = false;
        range(j, n - 1) {
            if (a[j] > a[j + 1]) was = true;
        }
        if (!was) break;
        ans++;
        swap(x, a[i]);
    }
    bool was = false;
    range(j, n - 1) {
        if (a[j] > a[j + 1]) was = true;
    }
    if (was) {
        cout << "-1\n";
        return;
    } else {
        cout << ans << '\n';
    }
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
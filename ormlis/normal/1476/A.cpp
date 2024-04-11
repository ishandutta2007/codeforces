#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

// using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 2e9;
const int maxN = 1e6 + 1000;
const int md = 1e9 + 123;
const int md2 = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;
    if (n % k == 0) {
        cout << "1\n";
        return;
    }
    if (n < k) {
        cout << (k + n - 1) / n << '\n';
        return;
    }
    cout << 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
     cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
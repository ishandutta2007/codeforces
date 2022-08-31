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
    int n, k;
    cin >> n >> k;
    if (n % 2 == 0) {
        cout << (k - 1) % n + 1 << '\n';
        return;
    }
    k--;
    int t = k / (n / 2);
    cout << (k + t) % n + 1 << '\n';
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
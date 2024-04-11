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

ld pi = atan2(0, -1);

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n;
    cin >> n;
    ld R = (ld) 1 / (ld) (2 * sin(pi / (2 * n)));
    int k = n / 2;
    ld L = 2 * R * sin((pi / n * k) / (ld)2);
    ld L2 = 2 * R * sin((pi / n * (n - k)) / (ld)2);
    cout << (L2 + L) / sqrt(2) << "\n";
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
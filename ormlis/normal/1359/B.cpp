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
const int maxN = 5000 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> a(n, vector<int>(m));
    range(i, n) range(j, m) {
            char e;
            cin >> e;
            if (e == '*') a[i][j] = 1;
        }

    y = min(y, x * 2);
    ll ans = 0;
    range(i, n) {
        range(j, m) {
            if (!a[i][j]) {
                if (j != m - 1 && !a[i][j + 1]) {
                    ans += y;
                    a[i][j] = a[i][j + 1] = 1;
                } else {
                    ans += x;
                    a[i][j] = 1;
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
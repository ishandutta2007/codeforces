#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;

using namespace std;

const ll INF = 2e18 + 5;
const int INFi = 1e8;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    range(i, n) {
        range(j, m) {
            char x; cin >> x;
            if (x == '*') a[i][j] = 1;
        }
    }
    ll ans = 0;
    vector<vector<int>> c(m, vector<int> (m, 0));
    range(i, m) if (a[0][i]) {
        c[i][i] = 1;
        ans++;
    }
    for(int i = 1; i < n; ++i) {
        vector<vector<int>> c2(m, vector<int> (m, 0));
        range(j, m) {
            for(int e = j; e < m; ++e) {
                if (!a[i][e]) break;
                if (e == j) {
                    ans++;
                    c2[j][e] = 1;
                    continue;
                }
                if ((e - j) % 2) continue;
                ans += (c2[j][e] = c[j+1][e-1]);
            }
        }
        swap(c, c2);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
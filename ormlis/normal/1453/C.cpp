#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < (n); ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

// using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 1e9;
const int maxN = 3e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    range(i, n) range(j, n) {
            char x;
            cin >> x;
            a[i][j] = x - '0';
        }
    vector<int> ans(10, 0);
    range(_, 2) {
        range(__, 2) {
            vector<int> was(10, n);
            range(i, n) {
                vector<int> was_row(10, n);
                range(j, n) {
                    was[a[i][j]] = min(was[a[i][j]], i);
                    was_row[a[i][j]] = min(was_row[a[i][j]], j);
                    ans[a[i][j]] = max(ans[a[i][j]], (j - was_row[a[i][j]]) * i);
                    ans[a[i][j]] = max(ans[a[i][j]], j * (i - was[a[i][j]]));
                    ans[a[i][j]] = max(ans[a[i][j]], (j - was_row[a[i][j]]) * (n - 1 - i));
                    ans[a[i][j]] = max(ans[a[i][j]], (n - 1 - j) * (i - was[a[i][j]]));
                }
            }
            reverse(all(a));
        }
        range(i, n) {
            range(j, i) {
                swap(a[i][j], a[j][i]);
            }
        }
    }
    range(i, 10) cout << ans[i] << " ";
    cout << '\n';
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
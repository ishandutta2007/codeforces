#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;

using namespace std;

const ll INF = 2e18 + 5;
const int INFi = 1e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 999999001;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    range(i, n) {
        cin >> b[i];
        b[i]--;
    }
    vector<int> can(n * 3 + 5);
    range(i, n) {
        {
            int low = b[i] - i;
            if (low) {
                can[max(0, i - (low - 1))]++;
                can[i + 1]--;
            }
        }
        {
            int high = 2 * n - (b[i] + 1);
            high -= n - (i + 1);
            if (high) {
                can[i + 1]++;
                can[i + high + 1]--;
            }
        }
    }
    int cnt = 0;
    int ans = 0;
    range(i, n + 1) {
        cnt += can[i];
        if (cnt == n) ans++;
    }
    cout << ans << '\n';
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
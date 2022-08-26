#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 5e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n;
    cin >> n;
    ar<ll, 3> dp = {0, 0, 0};
    int prev = -5;
    range(_, n) {
        int a, b; cin >> a >> b;
        ar<ll, 3> new_dp = {INF, INF, INF};
        range(i, 3) {
            range(j, 3) {
                if (a + i != prev + j) new_dp[i] = min(new_dp[i], dp[j] + 1ll * i * b);
            }
        }
        dp = new_dp;
        prev = a;
    }
    cout << min(dp[0], min(dp[1], dp[2])) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
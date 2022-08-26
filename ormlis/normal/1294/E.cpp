#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1000001;
ll md = 1000000007;

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> t(n, vector<ll> (m, 0));
    range(i, n) {
        range(j, m) cin >> t[i][j];
    }
    ll answer = 0;
    range(j, m) {
        vector<ll> c(n, 0);
        range(i, n) {
            if (t[i][j] % m == (j + 1) % m && (j + 1) <= t[i][j] && t[i][j] <= m * (n - 1) + (j + 1)) {
                int f = t[i][j] - (j + 1);
                f /= m;
                int ans = i - f;
                if (ans < 0) ans += n;
                if (ans >= n) ans %= n;
                c[ans]++;
            }
        }
        ll ans_cur = n;
        range(i, n) {
            ll ans2 = i;
            ans2 += n - c[i];
            ans_cur = min(ans_cur, ans2);
        }
        answer += ans_cur;
    }
    cout << answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}
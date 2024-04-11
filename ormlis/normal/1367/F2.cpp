#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    auto b = a;
    sort(all(b));
    b.resize(unique(all(b)) - b.begin());
    range(i, n) a[i] = 1 + (lower_bound(all(b), a[i]) - b.begin());
    vector<int> last(n + 1, -1);
    vector<int> cnt(n + 1, 0);
    range(i, n) last[a[i]] = i;
    vector<int> dp1(n + 1), dp2(n + 1), dp3(n + 1);
    range(i, n) {
        dp1[a[i]]++;
        dp3[a[i]] = max(dp3[a[i]], dp1[a[i] - 1]) + 1;
        if (dp2[a[i]] == 0) {
            dp2[a[i]] = dp1[a[i] - 1];
        }
        dp2[a[i]]++;
        if (i == last[a[i]]) {
            dp1[a[i]] = dp2[a[i]];
        }
    }
    cout << n - (*max_element(all(dp3))) << "\n";
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
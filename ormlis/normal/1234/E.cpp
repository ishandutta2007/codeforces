#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 1e9;
const int maxN = 400000 + 2000;
const int md = 998244353;
const int md2 = 1e9 + 7;

// double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    range(i, m) cin >> x[i];
    vector<int> pref(n + 2);
    vector<ll> f2(n + 2);
    ll ans = 0;
    range(i, m - 1) {
        if (x[i] == x[i + 1]) {
            continue;
        }
        pref[min(x[i], x[i + 1]) + 1] += 1;
        pref[max(x[i], x[i + 1])] -= 1;
        ans += abs(x[i] - x[i + 1]);
        f2[x[i]] -= abs(x[i] - x[i + 1]);
        if (x[i] < x[i+1]) {
            f2[x[i]] += x[i+1] - 1;
            f2[x[i+1]] += x[i];
        } else {
            f2[x[i+1]] += x[i] - 1;
            f2[x[i]] += x[i+1];
        }
        f2[x[i+1]] -= abs(x[i] - x[i + 1]);
    }
    for(int i = 1; i <= n; ++i) pref[i] += pref[i-1];
    for(int i = 1; i <= n; ++i) {
        cout << ans + f2[i] - pref[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
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
    int n, m; cin >> n >> m;
    vector<ll> l(m);
    vector<ll> suf(m + 1);
    range(i, m) cin >> l[i];
    suf[m] = 0;
    for(int i = m - 1; ~i; --i) suf[i] = l[i] + suf[i+1];
    ll cur = 1;
    vector<ll> ans(m);
    range(i, m) {
        if (cur + l[i] - 1 > n) {
            cout << -1;
            return;
        }
        if (suf[i] < n - cur + 1) {
            cout << -1;
            return;
        }
        ans[i] = cur;
        if (suf[i] == n - cur + 1) {
            cur += l[i];
            continue;
        }
        if (suf[i+1] < n - cur + 1 - l[i]) {
            cout << -1;
            return;
        }
        if (suf[i+1] < n - cur + 1) {
            cur = n - suf[i+1] + 1;
        } else {
            cur++;
        }
    }
    if (cur != n + 1) {
        cout << -1;
        return;
    }
    range(i, m) cout << ans[i] << " ";
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
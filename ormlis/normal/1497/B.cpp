#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;

using namespace std;
//using namespace __gnu_pbds;

const int INFi = 2e9 + 5;
const int maxN = 2e5 + 100;
const int md = 1e9 + 7;
const ll INF = 2e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    range(i, n) a[i] %= m;
    vector<int> b(m);
    int cnt0 = 0;
    int cntmp = 0;
    range(i, n) {
        if (a[i] == 0) {
            cnt0++;
        } else if (a[i] * 2 == m) {
            cntmp++;
        } else if (a[i] * 2 < m) {
            b[a[i]]++;
        } else {
            b[a[i]]++;
        }
    }
    int ans = (cnt0 != 0) + (cntmp != 0);
    for(int i = 1; i * 2 < m; ++i) {
        int x = m - i;
        if (!b[x] && !b[i]) continue;
        int res = b[i] - b[x];
        res = abs(res);
        if (res <= 1) {
            ans++;
        } else {
            ans += res;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
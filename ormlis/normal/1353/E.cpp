#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    range(i, n) {
        char x;
        cin >> x;
        if (x == '1') a[i] = 1;
    }
    int allcnt = 0;
    vector<vector<int>> b(k);
    range(i, n) {
        b[i%k].push_back(a[i]);
        if (a[i]) allcnt++;
    }
    int ans = INFi;
    range(i, k) {
        int s = b[i].size();
        int cur = allcnt;
        int prevmin = 1;
        int cnt1 = 0;
        range(j, s) {
            if (b[i][j]) cnt1++;
            prevmin = min(prevmin, -j + 2 * cnt1);
            cur = min(cur, j + allcnt - 2 * cnt1 + prevmin);
        }
        ans = min(ans, cur);
    }
    cout << ans << "\n";
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